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
struct TState_TestObserver
{
  AutState  autState;

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
  TState_D_precede_C  ts_D_precede_C;
  TState_C_precede_D  ts_C_precede_D;

};
struct TState_Diagnostic_CCSL
{
  TState_D_alternateWith_C  ts_D_alternateWith_C;
  TState_S_subclock_C  ts_S_subclock_C;

};
struct TState_Bloc1
{
  TState_Diagnostic_CCSL  ts_Diagnostic_CCSL;
  TState_TestObserver  ts_TestObserver;

};
struct TState_RprecedeI
{
  int  counter;
  AutState  autState;

};
struct TState_IbeforeR
{
  int  counter;
  AutState  autState;

};
struct TState_T4
{
  TState_IbeforeR  ts_IbeforeR;
  TState_RprecedeI  ts_RprecedeI;

};
struct TState_exclusion
{
  AutState  autState;

};
struct TState_T3
{
  TState_exclusion  ts_exclusion;
  TState_T4  ts_T4;

};
struct TState_iUr
{
  AutState  autState;

};
struct TState_T2
{
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
  TState_P_precede_Z  ts_P_precede_Z;
  TState_Z_precede_P  ts_Z_precede_P;

};
struct TState_T1
{
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
  TState_P_discretizedBy_10  ts_P_discretizedBy_10;
  TState_T1  ts_T1;

};
struct TState_Observers
{
  int  nb_r;
  bool  specific;
  int  nb_i;
  bool  obr_2;
  bool  obr_1;
  TState_Control_CCSL  ts_Control_CCSL;
  TState_Bloc1  ts_Bloc1;

};
struct TState_CallObservers
{
  CallState  callState;
  TState_Observers  ts_Observers;

};
struct TState_ControlExecution
{
  AutState  autState;

};
struct TState_Control
{
  Timer periodic_timer  = current_time;
  int  nb_remove;
  int  nb_insert;
  TState_ControlExecution  ts_ControlExecution;

};
struct TState_CallControl
{
  CallState  callState;
  TState_Control  ts_Control;

};
struct TState_GetTemperature
{
  AutState  autState;

};
struct TState_DiagnosticExecution
{
  AutState  autState;

};
struct TState_Diagnostic
{
  TState_DiagnosticExecution  ts_DiagnosticExecution;

};
struct TState_CallDiagnostic
{
  CallState  callState;
  TState_Diagnostic  ts_Diagnostic;

};
struct TState_ProgramBloc2
{
  TState_CallDiagnostic  ts_CallDiagnostic;
  TState_GetTemperature  ts_GetTemperature;

};
struct TState_Program
{
  float  temperature;
  Timer diagnostic_to_control = current_time;
  TState_ProgramBloc2  ts_ProgramBloc2;
  TState_CallControl  ts_CallControl;

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
  std::string   response;
  int  p;
  TState_CallProgram  ts_CallProgram;
  TState_CallObservers  ts_CallObservers;

};
TState_VerificationObserver  ts_VerificationObserver;
std::time_t  step_time = 1.0E9;
Timer  last_event_time = 0;

int    periodic_sense()
{
	int  exec = 0;
	if(((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && periodic_timer.expired(1E10, current_time) ) || periodic_timer.expired(1E10, current_time) ))) || (ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && periodic_timer.expired(1E10, current_time) ) || periodic_timer.expired(1E10, current_time) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))))))))
	{
		if((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && periodic_timer.expired(1E10, current_time) ) || periodic_timer.expired(1E10, current_time) ))))
		{
			ts_VerificationObserver.ts_CallProgram.callState = CALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.temperature = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = NOTCALLED;
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && periodic_timer.expired(1E10, current_time) ) || periodic_timer.expired(1E10, current_time) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))))))
			{
				if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && periodic_timer.expired(1E10, current_time) ) || periodic_timer.expired(1E10, current_time) ))))
				{
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = CALLED;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallProgram.ts_Program.right_clock_CallControl);
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ))
						{
							periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S0;
							exec = 1;
						
						}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))
						{
							periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) )))))
				{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ))
						{
							periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S0;
							exec = 1;
						
						}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))
						{
							periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
		}else if((ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && periodic_timer.expired(1E10, current_time) ) || periodic_timer.expired(1E10, current_time) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) )))))))
		{
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && periodic_timer.expired(1E10, current_time) ) || periodic_timer.expired(1E10, current_time) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))))))
			{
				if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && periodic_timer.expired(1E10, current_time) ) || periodic_timer.expired(1E10, current_time) ))))
				{
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = CALLED;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallProgram.ts_Program.right_clock_CallControl);
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ))
						{
							periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S0;
							exec = 1;
						
						}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))
						{
							periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) )))))
				{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && periodic_timer.expired(1E10, current_time) ))
						{
							periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S0;
							exec = 1;
						
						}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S1 && periodic_timer.expired(1E10, current_time) ))
						{
							periodic_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
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
	if(((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))))))
	{
		if((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)))
		{
			ts_VerificationObserver.ts_CallProgram.callState = CALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.temperature = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = NOTCALLED;
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))))
			{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)))
					{
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = CALLED;
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
								exec = 1;
							
							}
						
						}
					
					}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)))
					{
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
								exec = 1;
							
							}
						
						}
					
					}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
		}else if((ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)))))
		{
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))))
			{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)))
					{
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = CALLED;
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
								exec = 1;
							
							}
						
						}
					
					}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)))
					{
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
								exec = 1;
							
							}
						
						}
					
					}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
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
	if(((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))) || (ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) )))))))
	{
		if((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))))
		{
			ts_VerificationObserver.ts_CallProgram.callState = CALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.temperature = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = NOTCALLED;
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) )))))
			{
				if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))))
				{
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = CALLED;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallProgram.ts_Program.right_clock_CallControl);
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) ))
						{
							
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove++;
							;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) ))))
				{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) ))
						{
							
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove++;
							;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
							exec = 1;
						
						}
					
					}
				
				}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
		}else if((ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) ))))))
		{
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) )))))
			{
				if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))))
				{
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = CALLED;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallProgram.ts_Program.right_clock_CallControl);
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) ))
						{
							
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove++;
							;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) ))))
				{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert) != 0) ))
						{
							
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove++;
							;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
							exec = 1;
						
						}
					
					}
				
				}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
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
	if((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED || (ts_VerificationObserver.ts_CallProgram.callState == CALLED && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState == S0)))
	{
		if(ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED)
		{
			ts_VerificationObserver.ts_CallProgram.callState = CALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.temperature = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = NOTCALLED;
			if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState == S0)
			{
						
						ts_VerificationObserver.ts_CallProgram.ts_Program.temperature=p0;
						if((ts_VerificationObserver.min_temp<=ts_VerificationObserver.ts_CallProgram.ts_Program.temperature)&&(ts_VerificationObserver.ts_CallProgram.ts_Program.temperature<=ts_VerificationObserver.max_temp)){
						ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(current_time);
						}
						;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState = S0;
						exec = 1;
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
		}else if((ts_VerificationObserver.ts_CallProgram.callState == CALLED && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState == S0))
		{
			if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState == S0)
			{
						
						ts_VerificationObserver.ts_CallProgram.ts_Program.temperature=p0;
						if((ts_VerificationObserver.min_temp<=ts_VerificationObserver.ts_CallProgram.ts_Program.temperature)&&(ts_VerificationObserver.ts_CallProgram.ts_Program.temperature<=ts_VerificationObserver.max_temp)){
						ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(current_time);
						}
						;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState = S0;
						exec = 1;
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
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
	if((ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED || (ts_VerificationObserver.ts_CallObservers.callState == CALLED && (((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_VerificationObserver.p] == '1') && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ) && (((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) )))))) || ((((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_TestObserver.autState == S0)))))
	{
		if(ts_VerificationObserver.ts_CallObservers.callState == NOTCALLED)
		{
			ts_VerificationObserver.ts_CallObservers.callState = CALLED;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.nb_r = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.specific = false;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.nb_i = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2 = false;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 = false;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(ts_VerificationObserver.right_clock_CallObservers);
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter = 0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
			ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_TestObserver.autState = S0;
			if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_VerificationObserver.p] == '1') && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ) && (((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) )))))))
			{
					if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_VerificationObserver.p] == '1') && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
						exec = 1;
					
					}
					if((((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) ))))))
					{
						if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )))
						{
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter,ts_VerificationObserver.z,ts_VerificationObserver.p,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
								exec = 1;
							
							}
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter,ts_VerificationObserver.p,ts_VerificationObserver.z,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
								exec = 1;
							
							}
						
						}
						if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) )))))
						{
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ))
							{
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
								exec = 1;
							
							}
							if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) ))))
							{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
									exec = 1;
								
								}
								if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) )))
								{
									if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ))
									{
										clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter,ts_VerificationObserver.r,ts_VerificationObserver.i,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState = S0;
										exec = 1;
									
									}
									if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) ))
									{
										clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter,ts_VerificationObserver.i,ts_VerificationObserver.r,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState = S0;
										exec = 1;
									
									}
								
								}
							
							}
						
						}
					
					}
					ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=true;
			}
			if(((((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_TestObserver.autState == S0))
			{
				if((((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )))
				{
						if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )))
						{
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter,ts_VerificationObserver.c,ts_VerificationObserver.d,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
								exec = 1;
							
							}
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter,ts_VerificationObserver.d,ts_VerificationObserver.c,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
								exec = 1;
							
							}
						
						}
						if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) ))
						{
							ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
							exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=true;
				}
				if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_TestObserver.autState == S0)
				{
						
						if(p0=="00000000000"){
						ts_VerificationObserver.ts_CallObservers.ts_Observers.specific=true;
						}
						;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_TestObserver.autState = S0;
						exec = 1;
				
				}
			
			}
			if(exec)
			{
				
				if(!ts_VerificationObserver.ts_CallObservers.ts_Observers.specific){
				if((ts_VerificationObserver.response=="true") &&!(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2)){
				std::cout<<"Violation\n";
				}else if(!(ts_VerificationObserver.response=="true") &&(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2)){
				std::cout<<"Violation\n";
				}
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=false;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=true;
				;
			}
		
		}else if((ts_VerificationObserver.ts_CallObservers.callState == CALLED && (((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_VerificationObserver.p] == '1') && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ) && (((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) )))))) || ((((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_TestObserver.autState == S0))))
		{
			if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_VerificationObserver.p] == '1') && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ) && (((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) )))))))
			{
					if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_VerificationObserver.p] == '1') && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
					{
						ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
						exec = 1;
					
					}
					if((((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) ))))))
					{
						if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) )))
						{
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_VerificationObserver.z] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter,ts_VerificationObserver.z,ts_VerificationObserver.p,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
								exec = 1;
							
							}
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_VerificationObserver.p] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter,ts_VerificationObserver.p,ts_VerificationObserver.z,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
								exec = 1;
							
							}
						
						}
						if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) )))))
						{
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_VerificationObserver.z]-'0') == ((p0[ts_VerificationObserver.r]-'0')+(p0[ts_VerificationObserver.i]-'0')) ) ))
							{
								ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
								exec = 1;
							
							}
							if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ) && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) ))))
							{
								if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_VerificationObserver.i] == '0') || (p0[ts_VerificationObserver.r] == '0')) ))
								{
									ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
									exec = 1;
								
								}
								if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) )))
								{
									if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_VerificationObserver.r] == '0') ) ))
									{
										clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter,ts_VerificationObserver.r,ts_VerificationObserver.i,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState = S0;
										exec = 1;
									
									}
									if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_VerificationObserver.i] == '0') ) ))
									{
										clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter,ts_VerificationObserver.i,ts_VerificationObserver.r,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState = S0;
										exec = 1;
									
									}
								
								}
							
							}
						
						}
					
					}
					ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=true;
			}
			if(((((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )) || ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_TestObserver.autState == S0))
			{
				if((((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) )))
				{
						if(((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ) && (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) )))
						{
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_VerificationObserver.c] == '0')) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter,ts_VerificationObserver.c,ts_VerificationObserver.d,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
								exec = 1;
							
							}
							if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_VerificationObserver.d] == '0') ) ))
							{
								clockCounterDiff(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter,ts_VerificationObserver.d,ts_VerificationObserver.c,p0);ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
								exec = 1;
							
							}
						
						}
						if((ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_VerificationObserver.s] == '0') || (p0[ts_VerificationObserver.c] == '1')) ))
						{
							ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
							exec = 1;
						
						}
						ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=true;
				}
				if(ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_TestObserver.autState == S0)
				{
						
						if(p0=="00000000000"){
						ts_VerificationObserver.ts_CallObservers.ts_Observers.specific=true;
						}
						;ts_VerificationObserver.ts_CallObservers.ts_Observers.ts_Bloc1.ts_TestObserver.autState = S0;
						exec = 1;
				
				}
			
			}
			if(exec)
			{
				
				if(!ts_VerificationObserver.ts_CallObservers.ts_Observers.specific){
				if((ts_VerificationObserver.response=="true") &&!(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2)){
				std::cout<<"Violation\n";
				}else if(!(ts_VerificationObserver.response=="true") &&(ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1 && ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2)){
				std::cout<<"Violation\n";
				}
				}
				ts_VerificationObserver.response="";
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_1=false;
				ts_VerificationObserver.ts_CallObservers.ts_Observers.obr_2=true;
				;
			}
		
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
	if(((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))) || (ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) )))))))
	{
		if((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))))
		{
			ts_VerificationObserver.ts_CallProgram.callState = CALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.temperature = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = NOTCALLED;
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) )))))
			{
				if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))))
				{
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = CALLED;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallProgram.ts_Program.right_clock_CallControl);
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) ))
						{
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert++;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) ))))
				{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) ))
						{
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert++;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
							exec = 1;
						
						}
					
					}
				
				}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
		}else if((ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) ))))))
		{
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) )))))
			{
				if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == NOTCALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))))
				{
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = CALLED;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.periodic_timer .reset_clock(ts_VerificationObserver.ts_CallProgram.ts_Program.right_clock_CallControl);
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert = 0;
					ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) ))
						{
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert++;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState == CALLED && (ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) ))))
				{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) )))
					{
						if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState == S0 && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert-ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_remove) != 2) ))
						{
							ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.nb_insert++;ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.ts_Control.ts_ControlExecution.autState = S1;
							exec = 1;
						
						}
					
					}
				
				}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
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
	if(((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && ! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time) ) || (ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && ! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)))))))
	{
		if((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && ! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time) ))
		{
			ts_VerificationObserver.ts_CallProgram.callState = CALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.temperature = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = NOTCALLED;
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && ! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)))))
			{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && ! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time) ))
					{
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = CALLED;
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
								exec = 1;
							
							}else if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
								exec = 1;
							
							}
						
						}
					
					}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0))))
					{
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
								exec = 1;
							
							}else if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
								exec = 1;
							
							}
						
						}
					
					}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
		}else if((ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && ! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0))))))
		{
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && ! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time) ) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)))))
			{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && ! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time) ))
					{
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = CALLED;
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
								exec = 1;
							
							}else if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
								exec = 1;
							
							}
						
						}
					
					}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0))))
					{
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2 || ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
								exec = 1;
							
							}else if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
								exec = 1;
							
							}
						
						}
					
					}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
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
	if(((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)) || (ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))))))
	{
		if((ts_VerificationObserver.ts_CallProgram.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)))
		{
			ts_VerificationObserver.ts_CallProgram.callState = CALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.temperature = 0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.reset_clock(ts_VerificationObserver.left_clock_CallProgram);
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = NOTCALLED;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_GetTemperature.autState = S0;
			ts_VerificationObserver.ts_CallProgram.ts_Program.ts_CallControl.callState = NOTCALLED;
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))))
			{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)))
					{
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = CALLED;
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S2;
								exec = 1;
							
							}
						
						}
					
					}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)))
					{
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S2;
								exec = 1;
							
							}
						
						}
					
					}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
		}else if((ts_VerificationObserver.ts_CallProgram.callState == CALLED && ((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)))))
		{
			if(((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)) || (ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))))
			{
					if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == NOTCALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)))
					{
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState = CALLED;
						ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S2;
								exec = 1;
							
							}
						
						}
					
					}else if((ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.callState == CALLED && (! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)))
					{
						if((! ts_VerificationObserver.ts_CallProgram.ts_Program.diagnostic_to_control.expired(1E11, current_time)  && ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))
						{
							if(ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)
							{
								ts_VerificationObserver.ts_CallProgram.ts_Program.ts_ProgramBloc2.ts_CallDiagnostic.ts_Diagnostic.ts_DiagnosticExecution.autState = S2;
								exec = 1;
							
							}
						
						}
					
					}
			
			}
			if(exec)
			{
				ts_VerificationObserver.response="true";
			}
		
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    Step()
{
	int  exec = 1;
	current_time = step_time+current_time;
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
	ts_VerificationObserver.response = "";
	ts_VerificationObserver.p = p;
	ts_VerificationObserver.ts_CallProgram.callState = NOTCALLED;
	ts_VerificationObserver.ts_CallObservers.callState = NOTCALLED;
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("periodic_sense") == 0)
		{
			if(periodic_sense())
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
