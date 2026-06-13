#include "utils.cpp"
#include "helper.h"
#include <chrono>
#include <ctime>
#include "inttypes.h"
std::time_t  current_time = 0;
enum CallState
{
  NOTCALLED,
  CALLED
};
enum AutState
{
  S0,
  S1,
  S2
};
struct TState_Observer_3
{
  AutState  autState;

};
struct TState_TestObserver
{
  AutState  autState;

};
struct TState_Observer_Bloc_1
{
  Timer right_clock_Observer_3 = current_time;
  Timer left_clock_TestObserver = current_time;
  TState_TestObserver  ts_TestObserver;
  TState_Observer_3  ts_Observer_3;

};
struct TState_Check2
{
  AutState  autState;

};
struct TState_ControlExecution
{
  AutState  autState;

};
struct TState_ControlExecutionGuard
{
  TState_ControlExecution  ts_ControlExecution;

};
struct TState_ObserverControl
{
  Timer periodic_timer  = current_time;
  int  nb_remove;
  int  nb_insert;
  Timer left_clock_ControlExecutionGuard = current_time;
  Timer right_clock_Check2 = current_time;
  TState_ControlExecutionGuard  ts_ControlExecutionGuard;
  TState_Check2  ts_Check2;

};
struct TState_CallObserver_2
{
  CallState  callState;
  TState_ObserverControl  ts_ObserverControl;

};
struct TState_Check1
{
  AutState  autState;

};
struct TState_DiagnosticExecution
{
  AutState  autState;

};
struct TState_DiagnosticExecutionGuard
{
  TState_DiagnosticExecution  ts_DiagnosticExecution;

};
struct TState_ObserverDiagnostic
{
  Timer left_clock_DiagnosticExecutionGuard = current_time;
  Timer right_clock_Check1 = current_time;
  TState_DiagnosticExecutionGuard  ts_DiagnosticExecutionGuard;
  TState_Check1  ts_Check1;

};
struct TState_CallObserver_1
{
  CallState  callState;
  TState_ObserverDiagnostic  ts_ObserverDiagnostic;

};
struct TState_Observer_Bloc_2
{
  Timer left_clock_CallObserver_1 = current_time;
  Timer right_clock_CallObserver_2 = current_time;
  TState_CallObserver_1  ts_CallObserver_1;
  TState_CallObserver_2  ts_CallObserver_2;

};
struct TState_Observers
{
  float  temperature;
  int  obr_1;
  int  obr_2;
  int  obr_3;
  Timer right_clock_Observer_Bloc_1 = current_time;
  Timer left_clock_Observer_Bloc_2 = current_time;
  TState_Observer_Bloc_2  ts_Observer_Bloc_2;
  TState_Observer_Bloc_1  ts_Observer_Bloc_1;

};
struct TState_CallObservers
{
  CallState  callState;
  TState_Observers  ts_Observers;

};
struct TState_exclusion
{
  AutState  autState;

};
struct TState_IbeforeR
{
  int  counter;
  AutState  autState;

};
struct TState_T3
{
  Timer left_clock_IbeforeR = current_time;
  Timer right_clock_exclusion = current_time;
  TState_IbeforeR  ts_IbeforeR;
  TState_exclusion  ts_exclusion;

};
struct TState_iUr
{
  AutState  autState;

};
struct TState_T2
{
  Timer right_clock_T3 = current_time;
  Timer left_clock_iUr = current_time;
  TState_iUr  ts_iUr;
  TState_T3  ts_T3;

};
struct TState_Z_precede_P
{
  int  counter;
  AutState  autState;

};
struct TState_P_precede_Z
{
  int  counter;
  AutState  autState;

};
struct TState_P_alternateWith_Z
{
  Timer left_clock_P_precede_Z = current_time;
  Timer right_clock_Z_precede_P = current_time;
  TState_P_precede_Z  ts_P_precede_Z;
  TState_Z_precede_P  ts_Z_precede_P;

};
struct TState_T1
{
  Timer right_clock_T2 = current_time;
  Timer left_clock_P_alternateWith_Z = current_time;
  TState_P_alternateWith_Z  ts_P_alternateWith_Z;
  TState_T2  ts_T2;

};
struct TState_P_discretizedBy_10
{
  Timer periodic_sense_timer = current_time;
  AutState  autState;

};
struct TState_Control_CCSL
{
  Timer right_clock_T1 = current_time;
  Timer left_clock_P_discretizedBy_10 = current_time;
  TState_P_discretizedBy_10  ts_P_discretizedBy_10;
  TState_T1  ts_T1;

};
struct TState_S_subclock_C
{
  AutState  autState;

};
struct TState_C_precede_D
{
  int  counter;
  AutState  autState;

};
struct TState_D_precede_C
{
  int  counter;
  AutState  autState;

};
struct TState_D_alternateWith_C
{
  Timer right_clock_C_precede_D = current_time;
  Timer left_clock_D_precede_C = current_time;
  TState_D_precede_C  ts_D_precede_C;
  TState_C_precede_D  ts_C_precede_D;

};
struct TState_Diagnostic_CCSL
{
  Timer left_clock_D_alternateWith_C = current_time;
  Timer right_clock_S_subclock_C = current_time;
  TState_D_alternateWith_C  ts_D_alternateWith_C;
  TState_S_subclock_C  ts_S_subclock_C;

};
struct TState_Program
{
  int  nb_r;
  int  nb_i;
  Timer diagnostic_to_control = current_time;
  Timer right_clock_Control_CCSL = current_time;
  Timer left_clock_Diagnostic_CCSL = current_time;
  TState_Diagnostic_CCSL  ts_Diagnostic_CCSL;
  TState_Control_CCSL  ts_Control_CCSL;

};
struct TState_CallProgram
{
  CallState  callState;
  TState_Program  ts_Program;

};
struct TState_VerificationObserver
{
  int  i;
  int  r;
  int  z;
  int  c;
  int  s;
  int  d;
  int  min_temp;
  int  max_temp;
  Timer diagnostic_to_control = current_time;
  std::string   response;
  int  p;
  Timer right_clock_CallObservers = current_time;
  Timer left_clock_CallProgram = current_time;
  TState_CallProgram  ts_CallProgram;
  TState_CallObservers  ts_CallObservers;

};
TState_VerificationObserver  ts_VerificationObserver;
std::time_t  step_time = 10000000;
Timer  last_event_time = 0;

int    Step()
{
	int  exec = 0;
	current_time = step_time+current_time;
	if(((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))))))
	{
		if((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)))
		{
			ts_VerificationObserver.ts_CallObservers.callState = CALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
			if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))))
			{
					if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)))
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)))
					{
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}else if((ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)))))
		{
			if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))))
			{
					if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)))
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && (! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)))
					{
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    status_update()
{
	int  exec = 0;
	if((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0))))
	{
		if(ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED)
		{
			ts_VerificationObserver.ts_CallObservers.callState = CALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)))
					{
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}else if((ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)))
		{
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)))
					{
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    remove_rod()
{
	int  exec = 0;
	if((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0))))
	{
		if(ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED)
		{
			ts_VerificationObserver.ts_CallObservers.callState = CALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) ))
								{
									
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove++;
									;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)))
					{
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) ))
								{
									
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove++;
									;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}else if((ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)))
		{
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) ))
								{
									
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove++;
									;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)))
					{
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) )))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert) != 0) ))
								{
									
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove++;
									;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    get_temperature(float  p0)
{
	int  exec = 0;
	if((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.callState == CALLED && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState == S0)))
	{
		if(ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED)
		{
			ts_VerificationObserver.ts_CallObservers.callState = CALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature=p0;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=2;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}else if((ts_VerificationObserver.ts_CallObservers.callState == CALLED && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState == S0))
		{
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature=p0;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=2;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    schedule(std::string   p0)
{
	int  exec = 0;
	if(((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (((((0 != 0) || (p0[ts_VerificationObserver.c] == '0'))  && ( (0 != 1) || (p0[ts_VerificationObserver.d] == '0') ) ) && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) ) && ((((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0'))  && ((( (0 != 0) || (p0[ts_VerificationObserver.z] == '0') )  && ( (0 != 1) || (p0[ts_VerificationObserver.p] == '0') ) ) && (( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) )  && (( (0 != 0) || (p0[ts_VerificationObserver.r] == '0') )  && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) )))))) || (ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && (((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0')) ) && (((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) )))))))))
	{
		if((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (((((0 != 0) || (p0[ts_VerificationObserver.c] == '0'))  && ( (0 != 1) || (p0[ts_VerificationObserver.d] == '0') ) ) && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) ) && ((((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0'))  && ((( (0 != 0) || (p0[ts_VerificationObserver.z] == '0') )  && ( (0 != 1) || (p0[ts_VerificationObserver.p] == '0') ) ) && (( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) )  && (( (0 != 0) || (p0[ts_VerificationObserver.r] == '0') )  && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) )))))))
		{
			ts_VerificationObserver.ts_CallProgram.callState = CALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.nb_r = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.nb_i = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.right_clock_Control_CCSL.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.left_clock_Diagnostic_CCSL.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.left_clock_D_alternateWith_C.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.right_clock_S_subclock_C.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.right_clock_C_precede_D.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.left_clock_D_precede_C.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.right_clock_T1.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.right_clock_T2.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.left_clock_P_alternateWith_Z.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.left_clock_P_precede_Z.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.right_clock_Z_precede_P.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.right_clock_T3.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.left_clock_iUr.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.left_clock_IbeforeR.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.right_clock_exclusion.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
			if(((((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && (((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0')) ) && (((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) )))))))
			{
				if((((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )))
				{
					if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ))
						{
							clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter,ts_VerificationObserver.c,ts_VerificationObserver.d,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.left_clock_D_precede_C.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
							exec = 1;
						
						}
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) ))
						{
							clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter,ts_VerificationObserver.d,ts_VerificationObserver.c,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.right_clock_C_precede_D.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
							exec = 1;
						
						}
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.left_clock_D_alternateWith_C.reset_clock(current_time);
					}
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) ))
					{
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.right_clock_S_subclock_C.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
						exec = 1;
					
					}
					ts_VerificationObserver.ts_CallProgram.ts_Program.left_clock_Diagnostic_CCSL.reset_clock(current_time);
				}
				if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && (((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0')) ) && (((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ))))))
				{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && (((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0')) ))
					{
						
						if(p0[ts_VerificationObserver.p]=='1'){ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);}
						;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
						exec = 1;
					
					}
					if((((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) )))))
					{
						if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )))
						{
							if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter,ts_VerificationObserver.z,ts_VerificationObserver.p,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.left_clock_P_precede_Z.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
								exec = 1;
							
							}
							if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter,ts_VerificationObserver.p,ts_VerificationObserver.z,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.right_clock_Z_precede_P.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
								exec = 1;
							
							}
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.left_clock_P_alternateWith_Z.reset_clock(current_time);
						}
						if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ))))
						{
							if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ))
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.left_clock_iUr.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
								exec = 1;
							
							}
							if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) )))
							{
								if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ))
								{
									clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter,ts_VerificationObserver.r,ts_VerificationObserver.i,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.left_clock_IbeforeR.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState = S0;
									exec = 1;
								
								}
								if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ))
								{
									ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.right_clock_exclusion.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.right_clock_T3.reset_clock(current_time);
							}
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.right_clock_T2.reset_clock(current_time);
						}
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.right_clock_T1.reset_clock(current_time);
					}
					ts_VerificationObserver.ts_CallProgram.ts_Program.right_clock_Control_CCSL.reset_clock(current_time);
				}
				
				ts_VerificationObserver.response="true";
				;
			}
			ts_VerificationObserver.left_clock_CallProgram.reset_clock(current_time);
		}else if((ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && (((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0')) ) && (((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ))))))))
		{
			if(((((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && (((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0')) ) && (((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) )))))))
			{
				if((((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )))
				{
					if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ))
						{
							clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter,ts_VerificationObserver.c,ts_VerificationObserver.d,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.left_clock_D_precede_C.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
							exec = 1;
						
						}
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) ))
						{
							clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter,ts_VerificationObserver.d,ts_VerificationObserver.c,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.right_clock_C_precede_D.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
							exec = 1;
						
						}
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.left_clock_D_alternateWith_C.reset_clock(current_time);
					}
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) ))
					{
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.right_clock_S_subclock_C.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
						exec = 1;
					
					}
					ts_VerificationObserver.ts_CallProgram.ts_Program.left_clock_Diagnostic_CCSL.reset_clock(current_time);
				}
				if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && (((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0')) ) && (((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ))))))
				{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && (((p0[ts_VerificationObserver.p] == '1') && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time)) || (p0[ts_VerificationObserver.p] == '0')) ))
					{
						
						if(p0[ts_VerificationObserver.p]=='1'){ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);}
						;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
						exec = 1;
					
					}
					if((((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) )))))
					{
						if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )))
						{
							if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter,ts_VerificationObserver.z,ts_VerificationObserver.p,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.left_clock_P_precede_Z.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
								exec = 1;
							
							}
							if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter,ts_VerificationObserver.p,ts_VerificationObserver.z,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.right_clock_Z_precede_P.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
								exec = 1;
							
							}
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.left_clock_P_alternateWith_Z.reset_clock(current_time);
						}
						if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ))))
						{
							if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ))
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.left_clock_iUr.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
								exec = 1;
							
							}
							if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) )))
							{
								if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ))
								{
									clockCounterDiff(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.counter,ts_VerificationObserver.r,ts_VerificationObserver.i,p0);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.left_clock_IbeforeR.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_IbeforeR.autState = S0;
									exec = 1;
								
								}
								if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ))
								{
									ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.right_clock_exclusion.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.ts_T2.right_clock_T3.reset_clock(current_time);
							}
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.ts_T1.right_clock_T2.reset_clock(current_time);
						}
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_Control_CCSL.right_clock_T1.reset_clock(current_time);
					}
					ts_VerificationObserver.ts_CallProgram.ts_Program.right_clock_Control_CCSL.reset_clock(current_time);
				}
				
				ts_VerificationObserver.response="true";
				;
			}
			ts_VerificationObserver.left_clock_CallProgram.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    insert_rod()
{
	int  exec = 0;
	if((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0))))
	{
		if(ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED)
		{
			ts_VerificationObserver.ts_CallObservers.callState = CALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert++;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)))
					{
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert++;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}else if((ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)))
		{
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert++;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)))
					{
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) )))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert-ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove) != 2) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert++;ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    diagnostic()
{
	int  exec = 0;
	if((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0))))
	{
		if(ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED)
		{
			ts_VerificationObserver.ts_CallObservers.callState = CALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}else if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)))
					{
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}else if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}else if((ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)))
		{
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}else if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)))
					{
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S2)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}else if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S0)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    periodic_sense()
{
	int  exec = 0;
	if((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0))))
	{
		if(ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED)
		{
			ts_VerificationObserver.ts_CallObservers.callState = CALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)))
					{
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}else if((ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)))
		{
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_remove = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.nb_insert = 0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S1;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState == CALLED && ((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)))
					{
						if((ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))))
						{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState == S0 && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.expired(1E10, current_time) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_ControlExecutionGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.left_clock_ControlExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.right_clock_Check2.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.ts_ObserverControl.ts_Check2.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    reconfig()
{
	int  exec = 0;
	if((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0))))
	{
		if(ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED)
		{
			ts_VerificationObserver.ts_CallObservers.callState = CALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.temperature = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3 = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.right_clock_CallObserver_2.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_2.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.right_clock_Observer_3.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_Observer_3.autState = S0;
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S2;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)))
					{
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S2;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}else if((ts_VerificationObserver.ts_CallObservers.callState == CALLED && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)))
		{
			if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0))))
			{
					if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == NOTCALLED)
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState = CALLED;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1);
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S0;
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S2;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}else if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.callState == CALLED && ((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)))
					{
						if((! ts_VerificationObserver.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1))
						{
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState == S1)
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=2;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_DiagnosticExecutionGuard.ts_DiagnosticExecution.autState = S2;
									exec = 1;
								
								}
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.left_clock_DiagnosticExecutionGuard.reset_clock(current_time);
						}
						if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState == S0)
						{
								
								if(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1!=2){ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=1;}
								;
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.right_clock_Check1.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.ts_CallObserver_1.ts_ObserverDiagnostic.ts_Check1.autState = S0;
								exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_2.left_clock_CallObserver_1.reset_clock(current_time);
					}
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.left_clock_Observer_Bloc_2.reset_clock(current_time);
				}
			
			}
			if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState == S0)
			{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.left_clock_TestObserver.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Observer_Bloc_1.ts_TestObserver.autState = S0;
						exec = 1;
				if(exec)
				{
					ts_VerificationObserver.ts_CallObservers.ts_Observers.right_clock_Observer_Bloc_1.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if((ts_VerificationObserver.response=="true")&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==1)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==1))){
				cout<<"Violation\n";
				}else if((ts_VerificationObserver.response!="true")&&(((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==0)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2)))&&((ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2==2)||(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3==2))){
				cout<<"Violation\n";
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=0;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_3=0;
				;
			}
			ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_VerificationObserver.i = i;
	ts_VerificationObserver.r = r;
	ts_VerificationObserver.z = z;
	ts_VerificationObserver.c = c;
	ts_VerificationObserver.s = s;
	ts_VerificationObserver.d = d;
	ts_VerificationObserver.min_temp = min_temp;
	ts_VerificationObserver.max_temp = max_temp;
	ts_VerificationObserver.diagnostic_to_control.reset_clock(current_time);
	ts_VerificationObserver.response = "";
	ts_VerificationObserver.p = p;
	ts_VerificationObserver.right_clock_CallObservers.reset_clock(current_time);
	ts_VerificationObserver.left_clock_CallProgram.reset_clock(current_time);
	ts_VerificationObserver.ts_CallProgram.callState = NOTCALLED;
	ts_VerificationObserver.ts_CallObservers.callState = NOTCALLED;
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("Step") == 0)
		{
			if(Step())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("status_update") == 0)
		{
			if(status_update())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("remove_rod") == 0)
		{
			if(remove_rod())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("get_temperature") == 0)
		{
			bool  flag = 0;
			if(_evt.params.size() == 1)
			{
				float  p0;
				p0 = Types::get_float(_evt.params[0], flag);
				if((!(flag) && get_temperature(p0)))
				{
					continue;
				}else if(flag)
				{
					ERROR_6;
				
				}else 
				{
					ERROR_2;
				
				}
			
			}else 
			{
				ERROR_7;
			
			}
		
		}else if(_evt.label.compare("schedule") == 0)
		{
			bool  flag = 0;
			if(_evt.params.size() == 1)
			{
				std::string   p0;
				p0 = Types::get_str(_evt.params[0]);
				if((!(flag) && schedule(p0)))
				{
					continue;
				}else if(flag)
				{
					ERROR_6;
				
				}else 
				{
					ERROR_2;
				
				}
			
			}else 
			{
				ERROR_7;
			
			}
		
		}else if(_evt.label.compare("insert_rod") == 0)
		{
			if(insert_rod())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("diagnostic") == 0)
		{
			if(diagnostic())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("periodic_sense") == 0)
		{
			if(periodic_sense())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("reconfig") == 0)
		{
			if(reconfig())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("advanceTo") == 0){
			if(Types::get_str(_evt.params[0]).find(":") != std::string::npos){
				long int numberOfSteps = advanceToV1(current_time, step_time, Types::get_str(_evt.params[0]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}
			else{
				bool flag = 0;
				long int numberOfSteps = advanceToV2(current_time, step_time, Types::get_str(_evt.params[0]), (std::time_t) Types::get_double(_evt.params[1], flag));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}
		}else if(_evt.label.compare("advanceOf") == 0){
			if(Types::get_str(_evt.params[0]).find(":") != std::string::npos){
				long int numberOfSteps = advanceOfV1(step_time, Types::get_str(_evt.params[0]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}
			else{
				bool flag = 0;
				long int numberOfSteps = advanceOfV2(step_time, Types::get_str(_evt.params[0]), (std::time_t) Types::get_double(_evt.params[1], flag));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}	
		}
		else 
		{
			ERROR_1;
		
		}
	
	}
	return 0;

}
