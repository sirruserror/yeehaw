#include "all.h"

int main(int argc, char *argv[]){
    unsigned int debug = 0;
    unsigned int no_clb = 0; // disable containerization
    unsigned int force_static = 0;
    unsigned int force_O1 = 0;
    unsigned int force_O2 = 0;
    unsigned int force_O3 = 0;
    unsigned int force_ffast_math = 0;
    unsigned int force_Os = 0;
    unsigned int force_Oz = 0;
    unsigned int deny_O0 = 1;
    unsigned int install = 0;
    unsigned int remove = 0;
    unsigned int find = 0;
    unsigned int run = 0;
    if(argc < 2){
    	fprintf(stderr, "FATAL ERROR :( : Not enough arguments passed\nUSAGE: yeehaw [install, find, remove, run] [args]\n");
       	return EXIT_FAILURE;	
    }
    for(int i = 0; i < argc; i++){
    	if(i == 0){
	    continue;
	}
	else if(strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--debug") == 0){
		debug = 1;
		continue;
	}
	else if(strcmp(argv[i], "-nc") == 0 || strcmp(argv[i], "--no-clb") == 0){
		no_clb = 1;
		continue;
	}
	else if(strcmp(argv[i], "-fs") == 0 || strcmp(argv[i], "--force-static") == 0){
		force_static = 1;
		continue;
	}
	else if(strcmp(argv[i], "-O1") == 0 || strcmp(argv[i], "--force-O1") == 0){
		force_O1 = 1;
		continue;
	}
	else if(strcmp(argv[i], "-O2") == 0 || strcmp(argv[i], "--force-O2") == 0){
		force_O2 = 1;
		continue;
	}
	else if(strcmp(argv[i], "-O3") == 0 || strcmp(argv[i], "--force-O3") == 0){
		force_O3 = 1;
		continue;
	}
	else if(strcmp(argv[i], "-ffast-math") == 0){
		force_ffast_math = 1;
		continue;
	}
	else if(strcmp(argv[i], "-Os") == 0 || strcmp(argv[i], "--force-Os") == 0){
		force_Os = 1;
		continue;
	}
	else if(strcmp(argv[i], "-Oz") == 0 || strcmp(argv[i], "--force-Oz") == 0){
		force_Oz = 1;
		continue;
	}
	else if(strcmp(argv[i], "--deny-O0") == 0){
		deny_O0 = 1;
		continue;
	}
	else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0){
		printf("yeehaw version: %d\nCLBCabinCrew version: %d\n", YEEHAW_VERSION, CLB_VERSION);
		continue;
	}
	if(strcmp(argv[i], "install") == 0){
		install = 1;
		continue;
	}
	else if(strcmp(argv[i], "remove") == 0){
		remove = 1;
		continue;
	}
	else if(strcmp(argv[i], "find") == 0){
		find = 1;
		continue;
	}
	else if(strcmp(argv[i], "run") == 0){
		run = 1;
		continue;
	}
	else {
		fprintf(stderr, "FATAL ERROR :( : No mode provided or unkown param given!\n");
		return EXIT_FAILURE;	
	}
    }
    return EXIT_SUCCESS;
}
