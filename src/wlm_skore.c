//#include <kore/kore.h>
//#include <kore/http.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <slurm/slurm.h>
#include "version.h"
#include "slurm_to_json.h"

long _slurm_api_version;
long _slurm_api_major;
long _slurm_api_minor;
long _slurm_api_micro;

void usage(){
	printf("different method :\n");
	printf("- conf       : to get configurations\n");
	printf("- partitions : to get partitions\n");
	printf("- version    : to get versions\n");
	printf("- batch      : to schedule job\n");
	printf("- jobid      : to get info about job number 'id'\n");

}


int
main(int argc, char **argv)
{
    if (argc < 2)
    {
        usage();
        return 1;
    }
    char *method = argv[1];
    char *output = "";

    _slurm_api_version = slurm_get_api_version();
    _slurm_api_major = SLURM_VERSION_MAJOR(_slurm_api_version);
    _slurm_api_minor = SLURM_VERSION_MINOR(_slurm_api_version);
    _slurm_api_micro = SLURM_VERSION_MICRO(_slurm_api_version);

    if (_slurm_api_major < MIN_SLURM_API_VERSION)
    {
        printf("This program does not work with slurm API version prior to %ld\n", MIN_SLURM_API_VERSION);
        exit(1);
    }

    if (strcmp(method, "conf") == 0)
    {
        output = slurm_get_configuration();
    }
    else if (strcmp(method, "partitions") == 0)
    {
        output = slurm_get_partitions();
    }
    else if (strcmp(method, "version") == 0)
    {
        long version = slurm_get_api_version();
        printf("slurm_api_version: %ld\n", MIN_SLURM_API_VERSION);
        printf("slurm_api_version: %ld, %ld.%ld.%ld\n", _slurm_api_version,
               _slurm_api_major,
               _slurm_api_minor,
               _slurm_api_micro);
    }
    else if (strcmp(method, "batch") == 0)
    {
        char *json_string = "{'script':'#!/bin/bash\n#SBATCH -p debug\n#SBATCH -n 1\n#SBATCH -t 12:00:00\n#SBATCH -J some_job_name\n/bin/hostname\nsleep 10','work_dir':'/home/vagrant/'}";
        slurm_exec_submit_batch_job(json_string);
    }
    else if (strcmp(method, "jobid") == 0)
    {
    	if (argc < 3) {
	    printf("Need ID of the job : jobid number\n");
	}
	else{
	    output = slurm_get_job_info(atoi(argv[2]));
	}
    }
    else
    {
        output = "Unknown method";
    }


    printf("%s\n", output);
    return 0;
}


