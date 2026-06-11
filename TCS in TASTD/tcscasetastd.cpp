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
struct TState_GetTemperature
{
  AutState  autState;

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
struct TState_CallDiagnostic
{
  CallState  callState;
  TState_Control  ts_Control;

};
struct TState_TcsCaseTastd_o1
{
  float  temperature;
  Timer diagnostic_to_control = current_time;
  Timer right_clock_GetTemperature = current_time;
  Timer left_clock_CallDiagnostic = current_time;
  TState_CallDiagnostic  ts_CallDiagnostic;
  TState_GetTemperature  ts_GetTemperature;

};
struct TState_DiagnosticExecution
{
  AutState  autState;

};
struct TState_Diagnostic
{
  TState_DiagnosticExecution  ts_DiagnosticExecution;

};
struct TState_CallControl
{
  CallState  callState;
  TState_Diagnostic  ts_Diagnostic;

};
struct TState_TcsCaseTastd
{
  float  temperature;
  int  min_temp;
  int  max_temp;
  Timer diagnostic_to_control = current_time;
  Timer left_clock_CallControl = current_time;
  Timer right_clock_TcsCaseTastd_o1 = current_time;
  TState_CallControl  ts_CallControl;
  TState_TcsCaseTastd_o1  ts_TcsCaseTastd_o1;

};
TState_TcsCaseTastd  ts_TcsCaseTastd;
std::time_t  step_time = 1.0E9;
Timer  last_event_time = 0;

int    Step()
{
	int  exec = 0;
	current_time = step_time+current_time;
	if(((ts_TcsCaseTastd.ts_CallControl.callState == NOTCALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_TcsCaseTastd.ts_CallControl.callState == CALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))))
	{
		if((ts_TcsCaseTastd.ts_CallControl.callState == NOTCALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)))
		{
			ts_TcsCaseTastd.ts_CallControl.callState = CALLED;
			ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
			if((! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))
			{
				if(ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
				{
					ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
					exec = 1;
				
				}
			
			}
			ts_TcsCaseTastd.left_clock_CallControl.reset_clock(current_time);
		}else if((ts_TcsCaseTastd.ts_CallControl.callState == CALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)))
		{
			if((! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))
			{
				if(ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
				{
					ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
					exec = 1;
				
				}
			
			}
			ts_TcsCaseTastd.left_clock_CallControl.reset_clock(current_time);
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
	if(((ts_TcsCaseTastd.ts_CallControl.callState == NOTCALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)) || (ts_TcsCaseTastd.ts_CallControl.callState == CALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))))
	{
		if((ts_TcsCaseTastd.ts_CallControl.callState == NOTCALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && S0 == S2)))
		{
			ts_TcsCaseTastd.ts_CallControl.callState = CALLED;
			ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
			if((! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))
			{
				if(ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
				{
					ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
					exec = 1;
				
				}
			
			}
			ts_TcsCaseTastd.left_clock_CallControl.reset_clock(current_time);
		}else if((ts_TcsCaseTastd.ts_CallControl.callState == CALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)))
		{
			if((! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2))
			{
				if(ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S2)
				{
					ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
					exec = 1;
				
				}
			
			}
			ts_TcsCaseTastd.left_clock_CallControl.reset_clock(current_time);
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
	if(((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == NOTCALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))) || (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == CALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert) != 0) )))))
	{
			if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == NOTCALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 0) ))))
			{
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState = CALLED;
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer .reset_clock(ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic);
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove = 0;
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert = 0;
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S1;
				if((ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert) != 0) )))
				{
					if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert) != 0) ))
					{
						
						ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove++;
						;ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S1;
						exec = 1;
					
					}
				
				}
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic.reset_clock(current_time);
			}else if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == CALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert) != 0) ))))
			{
				if((ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert) != 0) )))
				{
					if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert) != 0) ))
					{
						
						ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove++;
						;ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S1;
						exec = 1;
					
					}
				
				}
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic.reset_clock(current_time);
			}
		if(exec)
		{
			ts_TcsCaseTastd.right_clock_TcsCaseTastd_o1.reset_clock(current_time);
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
	if(ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_GetTemperature.autState == S0)
	{
				
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.temperature=p0;
				if((ts_TcsCaseTastd.min_temp<=ts_TcsCaseTastd.ts_TcsCaseTastd_o1.temperature)&&(ts_TcsCaseTastd.ts_TcsCaseTastd_o1.temperature<=ts_TcsCaseTastd.max_temp)){
					ts_TcsCaseTastd.diagnostic_to_control.reset_clock(current_time);
				}
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.right_clock_GetTemperature.reset_clock(current_time);ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_GetTemperature.autState = S0;
				exec = 1;
		if(exec)
		{
			ts_TcsCaseTastd.right_clock_TcsCaseTastd_o1.reset_clock(current_time);
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
	if(((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == NOTCALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))) || (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == CALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove) != 2) )))))
	{
			if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == NOTCALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (S1 == S0 && ((0-0) != 2) ))))
			{
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState = CALLED;
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer .reset_clock(ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic);
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove = 0;
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert = 0;
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S1;
				if((ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove) != 2) )))
				{
					if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove) != 2) ))
					{
						ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert++;ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S1;
						exec = 1;
					
					}
				
				}
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic.reset_clock(current_time);
			}else if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == CALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove) != 2) ))))
			{
				if((ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove) != 2) )))
				{
					if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert-ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove) != 2) ))
					{
						ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert++;ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S1;
						exec = 1;
					
					}
				
				}
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic.reset_clock(current_time);
			}
		if(exec)
		{
			ts_TcsCaseTastd.right_clock_TcsCaseTastd_o1.reset_clock(current_time);
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
	if(((ts_TcsCaseTastd.ts_CallControl.callState == NOTCALLED && ! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time) ) || (ts_TcsCaseTastd.ts_CallControl.callState == CALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S0))))
	{
		if((ts_TcsCaseTastd.ts_CallControl.callState == NOTCALLED && ! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time) ))
		{
			ts_TcsCaseTastd.ts_CallControl.callState = CALLED;
			ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
			if((! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S0))
			{
				if(ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)
				{
					ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
					exec = 1;
				
				}
			
			}
			ts_TcsCaseTastd.left_clock_CallControl.reset_clock(current_time);
		}else if((ts_TcsCaseTastd.ts_CallControl.callState == CALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)))
		{
			if((! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S0))
			{
				if(ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S0)
				{
					ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S1;
					exec = 1;
				
				}
			
			}
			ts_TcsCaseTastd.left_clock_CallControl.reset_clock(current_time);
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
	if(((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == NOTCALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time)  || (S1 == S0 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) )))) || (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == CALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S1 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ) || (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ))))))
	{
			if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == NOTCALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time)  || (S1 == S0 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) )))))
			{
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState = CALLED;
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer .reset_clock(ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic);
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_remove = 0;
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.nb_insert = 0;
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S1;
				if((ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S1 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ) || (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ))))
				{
					if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S1 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ))
					{
						ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.reset_clock(current_time);ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S0;
						exec = 1;
					
					}else if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ))
					{
						ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.reset_clock(current_time);ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S0;
						exec = 1;
					
					}
				
				}
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic.reset_clock(current_time);
			}else if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState == CALLED && (ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S1 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ) || (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) )))))
			{
				if((ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S1 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ) || (ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ))))
				{
					if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S1 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ))
					{
						ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.reset_clock(current_time);ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S0;
						exec = 1;
					
					}else if((ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState == S0 && ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.expired(1E10, current_time) ))
					{
						ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.periodic_timer.reset_clock(current_time);ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.ts_Control.ts_ControlExecution.autState = S0;
						exec = 1;
					
					}
				
				}
				ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic.reset_clock(current_time);
			}
		if(exec)
		{
			ts_TcsCaseTastd.right_clock_TcsCaseTastd_o1.reset_clock(current_time);
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
	if(((ts_TcsCaseTastd.ts_CallControl.callState == NOTCALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)) || (ts_TcsCaseTastd.ts_CallControl.callState == CALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))))
	{
		if((ts_TcsCaseTastd.ts_CallControl.callState == NOTCALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && S0 == S1)))
		{
			ts_TcsCaseTastd.ts_CallControl.callState = CALLED;
			ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S0;
			if((! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))
			{
				if(ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)
				{
					ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S2;
					exec = 1;
				
				}
			
			}
			ts_TcsCaseTastd.left_clock_CallControl.reset_clock(current_time);
		}else if((ts_TcsCaseTastd.ts_CallControl.callState == CALLED && (! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)))
		{
			if((! ts_TcsCaseTastd.diagnostic_to_control.expired(1E11, current_time)  && ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S1))
			{
				if(ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState == S1)
				{
					ts_TcsCaseTastd.ts_CallControl.ts_Diagnostic.ts_DiagnosticExecution.autState = S2;
					exec = 1;
				
				}
			
			}
			ts_TcsCaseTastd.left_clock_CallControl.reset_clock(current_time);
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
	ts_TcsCaseTastd.temperature = 0;
	ts_TcsCaseTastd.min_temp = min_temp;
	ts_TcsCaseTastd.max_temp = max_temp;
	ts_TcsCaseTastd.diagnostic_to_control.reset_clock(current_time);
	ts_TcsCaseTastd.left_clock_CallControl.reset_clock(current_time);
	ts_TcsCaseTastd.right_clock_TcsCaseTastd_o1.reset_clock(current_time);
	ts_TcsCaseTastd.ts_CallControl.callState = NOTCALLED;
	ts_TcsCaseTastd.ts_TcsCaseTastd_o1.temperature = 0;
	ts_TcsCaseTastd.diagnostic_to_control.reset_clock(current_time);
	ts_TcsCaseTastd.ts_TcsCaseTastd_o1.right_clock_GetTemperature.reset_clock(current_time);
	ts_TcsCaseTastd.ts_TcsCaseTastd_o1.left_clock_CallDiagnostic.reset_clock(current_time);
	ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_CallDiagnostic.callState = NOTCALLED;
	ts_TcsCaseTastd.ts_TcsCaseTastd_o1.ts_GetTemperature.autState = S0;
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
