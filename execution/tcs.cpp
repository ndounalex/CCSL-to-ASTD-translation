#include "..\Ccsl translation\delayForModule.cpp"
#include "utils.cpp"
#include "helper.h"
#include <chrono>
#include <ctime>
#include "inttypes.h"
std::time_t  current_time = 0;
enum AutState
{
  Control,
  diagnostic,
  ControlExecution,
  S0
};
struct TState_S_subclock_C
{
  AutState  autState;

};
struct TState_D_precede_C
{
  AutState  autState;

};
struct TState_D_causality_C
{
  AutState  autState;

};
struct TState_D_alternateWith_C
{
  Timer right_clock_D_precede_C = current_time;
  Timer left_clock_D_causality_C = current_time;
  TState_D_causality_C  ts_D_causality_C;
  TState_D_precede_C  ts_D_precede_C;

};
struct TState_diagnostic
{
  Timer left_clock_D_alternateWith_C = current_time;
  Timer right_clock_S_subclock_C = current_time;
  TState_D_alternateWith_C  ts_D_alternateWith_C;
  TState_S_subclock_C  ts_S_subclock_C;

};
struct TState_r_precede_i
{
  AutState  autState;

};
struct TState_IbeforeR
{
  AutState  autState;

};
struct TState_i_alternatesWith_r
{
  Timer right_clock_r_precede_i = current_time;
  Timer left_clock_IbeforeR = current_time;
  TState_IbeforeR  ts_IbeforeR;
  TState_r_precede_i  ts_r_precede_i;

};
struct TState_exclusion
{
  AutState  autState;

};
struct TState_InsertOrRemoveRod
{
  Timer right_clock_i_alternatesWith_r = current_time;
  Timer left_clock_exclusion = current_time;
  TState_exclusion  ts_exclusion;
  TState_i_alternatesWith_r  ts_i_alternatesWith_r;

};
struct TState_iUr
{
  AutState  autState;

};
struct TState_T1
{
  Timer left_clock_iUr = current_time;
  Timer right_clock_InsertOrRemoveRod = current_time;
  TState_iUr  ts_iUr;
  TState_InsertOrRemoveRod  ts_InsertOrRemoveRod;

};
struct TState_P_causality_Z
{
  AutState  autState;

};
struct TState_P_precede_Z
{
  AutState  autState;

};
struct TState_P_alternateWith_Z
{
  Timer left_clock_P_precede_Z = current_time;
  Timer right_clock_P_causality_Z = current_time;
  TState_P_precede_Z  ts_P_precede_Z;
  TState_P_causality_Z  ts_P_causality_Z;

};
struct TState_TCS4
{
  Timer right_clock_T1 = current_time;
  Timer left_clock_P_alternateWith_Z = current_time;
  TState_P_alternateWith_Z  ts_P_alternateWith_Z;
  TState_T1  ts_T1;

};
struct TState_P_discretizedBy_10
{
  int  periodic_sense_occurence;
  Timer periodic_sense_timer = current_time;
  AutState  autState;

};
struct TState_ControlExecution
{
  Timer left_clock_P_discretizedBy_10 = current_time;
  Timer right_clock_TCS4 = current_time;
  TState_P_discretizedBy_10  ts_P_discretizedBy_10;
  TState_TCS4  ts_TCS4;

};
struct TState_Control
{
  AutState  autState;
  TState_ControlExecution  ts_ControlExecution;

};
struct TState_TCS
{
  int  nb_r;
  int  MIN;
  int  i;
  int  r;
  int  z;
  int  MAX;
  int  c;
  int  s;
  int  d;
  int  nb_i;
  Timer diagnostic_to_control = current_time;
  int  p;
  AutState  autState;
  TState_Control  ts_Control;
  TState_diagnostic  ts_diagnostic;

};
const std::vector<AutState>  shallow_final_exclusion = {S0};
const std::vector<AutState>  shallow_final_IbeforeR = {S0};
const std::vector<AutState>  shallow_final_r_precede_i = {S0};
TState_TCS  ts_TCS;
std::time_t  step_time = 1.0E9;
Timer  last_event_time = 0;

int    Step()
{
	int  exec = 0;
	current_time = step_time+current_time;
	if((ts_TCS.autState == diagnostic && ts_TCS.diagnostic_to_control.expired(1E11, current_time) ))
	{
		
		std::cout<<"\nGo to control mode\n";
		;ts_TCS.autState = Control;
		ts_TCS.ts_Control.autState = ControlExecution;
		ts_TCS.ts_Control.ts_ControlExecution.left_clock_P_discretizedBy_10.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.right_clock_TCS4.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState = S0;
		ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_occurence = 1;
		ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.right_clock_T1.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.left_clock_P_alternateWith_Z.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.left_clock_P_precede_Z.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.right_clock_P_causality_Z.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_causality_Z.autState = S0;
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.left_clock_iUr.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.right_clock_InsertOrRemoveRod.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_iUr.autState = S0;
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.right_clock_i_alternatesWith_r.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.left_clock_exclusion.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState = S0;
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.right_clock_r_precede_i.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.left_clock_IbeforeR.reset_clock(last_event_time);
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState = S0;
		ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState = S0;
		exec = 1;
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    e(std::string   p0)
{
	int  exec = 0;
	if((ts_TCS.autState == Control && (ts_TCS.ts_Control.autState == ControlExecution && (((ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '0') &&! (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ) || (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '1') && (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( ((history[ts_TCS.p]-history[ts_TCS.z]) != 1) || (p0[ts_TCS.p] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_causality_Z.autState == S0 && ( (history[ts_TCS.p]+(p0[ts_TCS.p]-'0')) >= (history[ts_TCS.z]+(p0[ts_TCS.z]-'0')) ) )) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( ((history[ts_TCS.r]-history[ts_TCS.i]) != 0) || (p0[ts_TCS.r] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( ((history[ts_TCS.i]-history[ts_TCS.r]) != 2) || (p0[ts_TCS.i] == '0') ) )))))))))
	{
		if((ts_TCS.ts_Control.autState == ControlExecution && (((ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '0') &&! (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ) || (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '1') && (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( ((history[ts_TCS.p]-history[ts_TCS.z]) != 1) || (p0[ts_TCS.p] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_causality_Z.autState == S0 && ( (history[ts_TCS.p]+(p0[ts_TCS.p]-'0')) >= (history[ts_TCS.z]+(p0[ts_TCS.z]-'0')) ) )) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( ((history[ts_TCS.r]-history[ts_TCS.i]) != 0) || (p0[ts_TCS.r] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( ((history[ts_TCS.i]-history[ts_TCS.r]) != 2) || (p0[ts_TCS.i] == '0') ) ))))))))
		{
			if((((ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '0') &&! (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ) || (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '1') && (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( ((history[ts_TCS.p]-history[ts_TCS.z]) != 1) || (p0[ts_TCS.p] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_causality_Z.autState == S0 && ( (history[ts_TCS.p]+(p0[ts_TCS.p]-'0')) >= (history[ts_TCS.z]+(p0[ts_TCS.z]-'0')) ) )) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( ((history[ts_TCS.r]-history[ts_TCS.i]) != 0) || (p0[ts_TCS.r] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( ((history[ts_TCS.i]-history[ts_TCS.r]) != 2) || (p0[ts_TCS.i] == '0') ) )))))))
			{
				if((ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '0') &&! (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
				{
					ts_TCS.ts_Control.ts_ControlExecution.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState = S0;
					exec = 1;
				
				}else if((ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '1') && (ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
				{
					ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);ts_TCS.ts_Control.ts_ControlExecution.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS.ts_Control.ts_ControlExecution.ts_P_discretizedBy_10.autState = S0;
					exec = 1;
				
				}
				if((((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( ((history[ts_TCS.p]-history[ts_TCS.z]) != 1) || (p0[ts_TCS.p] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_causality_Z.autState == S0 && ( (history[ts_TCS.p]+(p0[ts_TCS.p]-'0')) >= (history[ts_TCS.z]+(p0[ts_TCS.z]-'0')) ) )) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( ((history[ts_TCS.r]-history[ts_TCS.i]) != 0) || (p0[ts_TCS.r] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( ((history[ts_TCS.i]-history[ts_TCS.r]) != 2) || (p0[ts_TCS.i] == '0') ) ))))))
				{
					if(((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( ((history[ts_TCS.p]-history[ts_TCS.z]) != 1) || (p0[ts_TCS.p] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_causality_Z.autState == S0 && ( (history[ts_TCS.p]+(p0[ts_TCS.p]-'0')) >= (history[ts_TCS.z]+(p0[ts_TCS.z]-'0')) ) )))
					{
						if((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( ((history[ts_TCS.p]-history[ts_TCS.z]) != 1) || (p0[ts_TCS.p] == '0') ) ))
						{
							ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.left_clock_P_precede_Z.reset_clock(current_time);ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
							exec = 1;
						
						}
						if((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_causality_Z.autState == S0 && ( (history[ts_TCS.p]+(p0[ts_TCS.p]-'0')) >= (history[ts_TCS.z]+(p0[ts_TCS.z]-'0')) ) ))
						{
							ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.right_clock_P_causality_Z.reset_clock(current_time);ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_P_alternateWith_Z.ts_P_causality_Z.autState = S0;
							exec = 1;
						
						}
						ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.left_clock_P_alternateWith_Z.reset_clock(current_time);
					}
					if(((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( ((history[ts_TCS.r]-history[ts_TCS.i]) != 0) || (p0[ts_TCS.r] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( ((history[ts_TCS.i]-history[ts_TCS.r]) != 2) || (p0[ts_TCS.i] == '0') ) )))))
					{
						if((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) ))
						{
							ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.left_clock_iUr.reset_clock(current_time);ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_iUr.autState = S0;
							exec = 1;
						
						}
						if(((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) ) && ((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( ((history[ts_TCS.r]-history[ts_TCS.i]) != 0) || (p0[ts_TCS.r] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( ((history[ts_TCS.i]-history[ts_TCS.r]) != 2) || (p0[ts_TCS.i] == '0') ) ))))
						{
							if((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) ))
							{
								ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.left_clock_exclusion.reset_clock(current_time);ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState = S0;
								exec = 1;
							
							}
							if(((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( ((history[ts_TCS.r]-history[ts_TCS.i]) != 0) || (p0[ts_TCS.r] == '0') ) ) && (ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( ((history[ts_TCS.i]-history[ts_TCS.r]) != 2) || (p0[ts_TCS.i] == '0') ) )))
							{
								if((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( ((history[ts_TCS.r]-history[ts_TCS.i]) != 0) || (p0[ts_TCS.r] == '0') ) ))
								{
									
									updateHistory(history,p0);
									;ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.left_clock_IbeforeR.reset_clock(current_time);ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState = S0;
									exec = 1;
								
								}
								if((ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( ((history[ts_TCS.i]-history[ts_TCS.r]) != 2) || (p0[ts_TCS.i] == '0') ) ))
								{
									ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.right_clock_r_precede_i.reset_clock(current_time);ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState = S0;
									exec = 1;
								
								}
								ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.right_clock_i_alternatesWith_r.reset_clock(current_time);
							}
							ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.ts_T1.right_clock_InsertOrRemoveRod.reset_clock(current_time);
						}
						ts_TCS.ts_Control.ts_ControlExecution.ts_TCS4.right_clock_T1.reset_clock(current_time);
					}
					ts_TCS.ts_Control.ts_ControlExecution.right_clock_TCS4.reset_clock(current_time);
				}
				std::cout<<"\nControl mode action execution\n";
			}
		
		}
	
	}else if((ts_TCS.autState == diagnostic && (((ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_causality_C.autState == S0 && ( (history[ts_TCS.d]+(p0[ts_TCS.d]-'0')) >= (history[ts_TCS.c]+(p0[ts_TCS.c]-'0')) ) ) && (ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ( ((history[ts_TCS.d]-history[ts_TCS.c]) != 1) || (p0[ts_TCS.d] == '0') ) )) && (ts_TCS.ts_diagnostic.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS.s] == '0') || (p0[ts_TCS.c] == '1')) ))))
	{
		if((((ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_causality_C.autState == S0 && ( (history[ts_TCS.d]+(p0[ts_TCS.d]-'0')) >= (history[ts_TCS.c]+(p0[ts_TCS.c]-'0')) ) ) && (ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ( ((history[ts_TCS.d]-history[ts_TCS.c]) != 1) || (p0[ts_TCS.d] == '0') ) )) && (ts_TCS.ts_diagnostic.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS.s] == '0') || (p0[ts_TCS.c] == '1')) )))
		{
			if(((ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_causality_C.autState == S0 && ( (history[ts_TCS.d]+(p0[ts_TCS.d]-'0')) >= (history[ts_TCS.c]+(p0[ts_TCS.c]-'0')) ) ) && (ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ( ((history[ts_TCS.d]-history[ts_TCS.c]) != 1) || (p0[ts_TCS.d] == '0') ) )))
			{
				if((ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_causality_C.autState == S0 && ( (history[ts_TCS.d]+(p0[ts_TCS.d]-'0')) >= (history[ts_TCS.c]+(p0[ts_TCS.c]-'0')) ) ))
				{
					ts_TCS.ts_diagnostic.ts_D_alternateWith_C.left_clock_D_causality_C.reset_clock(current_time);ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_causality_C.autState = S0;
					exec = 1;
				
				}
				if((ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ( ((history[ts_TCS.d]-history[ts_TCS.c]) != 1) || (p0[ts_TCS.d] == '0') ) ))
				{
					ts_TCS.ts_diagnostic.ts_D_alternateWith_C.right_clock_D_precede_C.reset_clock(current_time);ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
					exec = 1;
				
				}
				ts_TCS.ts_diagnostic.left_clock_D_alternateWith_C.reset_clock(current_time);
			}
			if((ts_TCS.ts_diagnostic.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS.s] == '0') || (p0[ts_TCS.c] == '1')) ))
			{
				updateHistory(history,p0);ts_TCS.ts_diagnostic.right_clock_S_subclock_C.reset_clock(current_time);ts_TCS.ts_diagnostic.ts_S_subclock_C.autState = S0;
				exec = 1;
			
			}
			std::cout<<"\nDiagnostic mode action execution\n";
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    backToDiagnostic(int  p0)
{
	int  exec = 0;
	if((ts_TCS.autState == Control && ts_TCS.MIN < p0 < ts_TCS.MAX ))
	{
		
		std::cout<<"\nBack to diagnostic mode\n";
		ts_TCS.diagnostic_to_control.reset_clock(current_time);
		history[ts_TCS.d]=0;
		history[ts_TCS.c]=0;
		history[ts_TCS.s]=0;
		;ts_TCS.autState = diagnostic;
		ts_TCS.ts_diagnostic.left_clock_D_alternateWith_C.reset_clock(last_event_time);
		ts_TCS.ts_diagnostic.right_clock_S_subclock_C.reset_clock(last_event_time);
		ts_TCS.ts_diagnostic.ts_D_alternateWith_C.right_clock_D_precede_C.reset_clock(last_event_time);
		ts_TCS.ts_diagnostic.ts_D_alternateWith_C.left_clock_D_causality_C.reset_clock(last_event_time);
		ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_causality_C.autState = S0;
		ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
		ts_TCS.ts_diagnostic.ts_S_subclock_C.autState = S0;
		exec = 1;
	
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
	ts_TCS.autState = diagnostic;
	ts_TCS.nb_r = 0;
	ts_TCS.MIN = MIN;
	ts_TCS.i = i;
	ts_TCS.r = r;
	ts_TCS.z = z;
	ts_TCS.MAX = MAX;
	ts_TCS.c = c;
	ts_TCS.s = s;
	ts_TCS.d = d;
	ts_TCS.nb_i = 0;
	ts_TCS.diagnostic_to_control.reset_clock(current_time);
	ts_TCS.p = p;
	ts_TCS.ts_diagnostic.left_clock_D_alternateWith_C.reset_clock(current_time);
	ts_TCS.ts_diagnostic.right_clock_S_subclock_C.reset_clock(current_time);
	ts_TCS.ts_diagnostic.ts_D_alternateWith_C.right_clock_D_precede_C.reset_clock(current_time);
	ts_TCS.ts_diagnostic.ts_D_alternateWith_C.left_clock_D_causality_C.reset_clock(current_time);
	ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_causality_C.autState = S0;
	ts_TCS.ts_diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
	ts_TCS.ts_diagnostic.ts_S_subclock_C.autState = S0;
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
		
		}else if(_evt.label.compare("e") == 0)
		{
			bool  flag = 0;
			if(_evt.params.size() == 1)
			{
				std::string   p0;
				p0 = Types::get_str(_evt.params[0]);
				if((!(flag) && e(p0)))
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
		
		}else if(_evt.label.compare("backToDiagnostic") == 0)
		{
			bool  flag = 0;
			if(_evt.params.size() == 1)
			{
				int  p0;
				p0 = Types::get_int(_evt.params[0], flag);
				if((!(flag) && backToDiagnostic(p0)))
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
