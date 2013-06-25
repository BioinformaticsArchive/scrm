/* 
 * param.cc
 */

#include "param.h"

void Param::init(){
  this->random_seed=time(0);
  this->nsites=1000000;
  this->nsam=5;
  this->npop=10000;
  this->theta=0.00001;
  this->rho=0;	//double, in ms, rho = 4 * npop * recomb_rate_persite * (nsites-1)
  this->recomb_rate_persite=0;
  //this->rho=0.00000002;	
  this->ith_change=25;
  this->exact_window_length=0;
  this->log_bool=false;
  this->log_NAME="scrm.log";
  this->treefile="TREEFILE";
  this->seg_bool=false;
  this->total_mut=0;
  this->tmrca_bool=false;
  this->tmrca_NAME="tmrcaFILE";
}

Model Param::parse() {
  int argc_i=0;
  this->init();

  while( argc_i < argc_ ){
    std::cout << argv_[++argc_i] << std::endl;
    /*
    std::string argv_i(argv_[argc_i]);
    
    if (argc_i == 0) {
      read_input_to_param<int>(argv_[++argc_i],nsam);
      read_input_to_param<int>(argv_[++argc_i],nreps);
    }	
  
    else if (argv_i=="-seed"){
      //read_input_to_int(argv[argc_i+1],random_seed);
      read_input_to_param<int>(argv_[argc_i+1],random_seed);
      argc_i++;
    }

    if (argv_i=="-nsites"){
      //read_input_to_int(argv[argc_i+1],random_seed);
      read_input_to_param<double>(argv_[argc_i+1],nsites);
      argc_i++;
    }

    if (argv_i=="-npop"){
      //read_input_to_int(argv[argc_i+1],npop);
      read_input_to_param<int>(argv[argc_i+1],npop);
      argc_i_++;
    }	

    if (argv_i=="-t"){
      //read_input_to_double(argv[argc_i+1],theta);
      read_input_to_param<double>(argv[argc_i+1],theta);
      argc_i++;
    }

    if (argv_i=="-r"){
      //read_input_to_double(argv[argc_i+1],rho);
      read_input_to_param<double>(argv[argc_i+1],rho);
      seg_bool=false; // this needs to be changed
      argc_i++;
      if (argc_i+1 < argc){
        if (argv[argc_i+1][0]!='-'){
          read_input_to_param<double>(argv[argc_i+1],nsites);
          argc_i++;
        }
        //else{argc_i--;}
      }
    }

    if (argv_i=="-l"){
      //read_input_to_size_t(argv[argc_i+1],exact_window_length);
      read_input_to_param<size_t>(argv[argc_i+1],exact_window_length);
      argc_i++;
    }

    if (argv_i=="-s"){
      read_input_to_param<int>(argv[argc_i+1],total_mut);
      argc_i++;
    }

    if (argv_i=="-T"){
      treefile=argv[argc_i+1];
      seg_bool=false;
      argc_i++;			
    }

    if (argv_i=="-tmrca"){
      tmrca_bool=true;
      argc_i++;
      if (argc_i < argc){
        if (argv[argc_i][0]!='-'){
          tmrca_NAME=argv[argc_i];
          //argc_i++;
        }
        else{argc_i--;}
      }
    }

    if (argv_i=="-log"){
      log_bool=true;
      argc_i++;
      if (argc_i < argc){
        if (argv[argc_i][0]!='-'){
          log_NAME=argv[argc_i];
          //argc_i++;
        }
        else{argc_i--;}
      }			
    }
    argc_i++;
  */
  }

  //if (rho>0){

  //}
  recomb_rate_persite=rho/4 / npop / (nsites-1);
  remove(treefile.c_str());
  if (log_bool){
    remove(log_NAME.c_str());
    log_param();
  }
  if (tmrca_bool){remove(tmrca_NAME.c_str());}
  //MTRand_closed mt;
  //mt.seed(random_seed);		// initialize mt seed
}






void Param::print_param(){
  std::cout<<std::setw(6)<<"nsites"<<std::setw(10)<<nsites<<std::endl;
  std::cout<<std::setw(6)<<"nreps"<<std::setw(10)<<nreps<<std::endl;
  std::cout<<std::setw(6)<<"nsam"<<std::setw(10)<<nsam<<std::endl;
  std::cout<<std::setw(6)<<"npop"<<std::setw(10)<<npop<<std::endl;
  std::cout<<std::setw(6)<<"theta"<<std::setw(10)<<theta<<std::endl;
  std::cout<<std::setw(6)<<"rho"<<std::setw(10)<<rho<<std::endl;
  std::cout<<std::setw(6)<<"l"<<std::setw(10)<<exact_window_length<<std::endl;
}	

void Param::log_param(){
  //std::ofstream log_file;
  //log_file.open (log_NAME.c_str(), std::ios::out | std::ios::app | std::ios::binary); 
  std::ofstream log_file(this->log_NAME.c_str(), std::ios::out | std::ios::app | std::ios::binary); 
  log_file<<"scrm parameters: \n";
  log_file<<std::setw(10)<<"nsites ="<<std::setw(10)<<nsites<< "\n";
  log_file<<std::setw(10)<<"nreps"<<std::setw(10)<<nreps<<std::endl;
  log_file<<std::setw(10)<<"nsam ="<<std::setw(10)<<nsam<< "\n";
  log_file<<std::setw(10)<<"npop ="<<std::setw(10)<<npop<< "\n";
  log_file<<std::setw(10)<<"theta ="<<std::setw(10)<<theta<< "\n";
  log_file<<std::setw(10)<<"rho ="<<std::setw(10)<<rho<< "\n";
  log_file<<std::setw(10)<<"seed:"<<" "<<std::setw(10)<<random_seed<< "\n";
  log_file<<std::setw(10)<<"l ="<<std::setw(10)<<exact_window_length<<std::endl;
  log_file.close();
}		


void print_help(){
  //void scrm_help::print_help(){
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<"*****************************************************************"<<std::endl;
  std::cout<<"*			scrm					*"<<std::endl;
  std::cout<<"*		  Author: Paul R Staab, Sha Zhu			*"<<std::endl;
  std::cout<<"*****************************************************************"<<std::endl;
  std::cout<<std::endl<<std::endl;
  std::cout<<"Too few command line arguments"<<std::endl;
  std::cout<<"usage: ms nsam howmany"<<std::endl;
  std::cout<<"	Options:"<<std::endl;
  print_option();
  print_example();
  exit(1);
}

void print_option(){
  //std::cout<<std::setw(20)<<"-h or -help"<<"  --  "<<"Help. List the following content."<<std::endl;
  std::cout<<std::setw(20)<<"-r RHO"<<"  --  "<<"User define the recombination rate RHO, per gerneration per site."<<std::endl;
  std::cout<<std::setw(20)<<"-nsites NSITES"<<"  --  "<<"User define the sequence length NSITES."<<std::endl;
  std::cout<<std::setw(20)<<"-t THETA"<<"  --  "<<"User define the mutation rate THETA."<<std::endl;
  std::cout<<std::setw(20)<<"-npop NPOP"<<"  --  "<<"User define the population size NPOP."<<std::endl;
  std::cout<<std::setw(20)<<"-seed SEED"<<"  --  "<<"User define the random SEED."<<std::endl;
  std::cout<<std::setw(20)<<"-l exact_window_length"<<"  --  "
      <<"User define the length of the exact window."<<std::endl;
  std::cout<<std::setw(20)<<"-log [LOGFILE]"<<"  --  "<< "User specify the log file name, scrm.log by default."<<std::endl;
  std::cout<<std::setw(20)<<"-T myTREEFILE"<<"  --  "<< "User specify the tree file name, TREEFILE by default."<<std::endl;
}

void print_example(){	
  std::cout<<"Example:"<<std::endl;
  std::cout<<"./scrm 3 1"<<std::endl;
  std::cout<<"./scrm 6 3 -t 0.002 -r 0.00004 -npop 20000 "<<std::endl;
  std::cout<<"./scrm 5 3 -t 0.0002 -r 0.00003 -npop 10000 -seed 1314 -log"<<std::endl;
  std::cout<<"./scrm 6 1 -t 0.002 -r 0.00004 -nsites 2000 -log"<<std::endl;
  std::cout<<"./scrm 6 2 -t 0.002 -r 0.00004 -log LOGFILE"<<std::endl;
  std::cout<<"./scrm 6 2 -t 0.002 -r 0.00004 -log LOGFILE -T mytree"<<std::endl;

}

void appending_log_file(std::string log_file_NAME,std::string log_file_input /*! Information added*/){
  std::ofstream log_file;
  log_file.open (log_file_NAME.c_str(), std::ios::out | std::ios::app | std::ios::binary); 
  log_file << log_file_input << "\n";
  log_file.close();
}
