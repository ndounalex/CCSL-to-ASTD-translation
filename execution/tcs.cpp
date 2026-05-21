#include "utils.cpp"
#include "helper.h"
#include <chrono>
#include <ctime>
#include "inttypes.h"
std::time_t  current_time = 0;
enum AutState
{
  S0
};
struct TState_S_subclock_C
{
  AutState  autState;

};
struct TState_D_precede_C
{
  int  counter;
  AutState  autState;

};
struct TState_C_precede_D
{
  int  counter;
  AutState  autState;

};
struct TState_D_alternateWith_C
{
  TState_C_precede_D  ts_C_precede_D;
  TState_D_precede_C  ts_D_precede_C;

};
struct TState_Diagnostic
{
  TState_D_alternateWith_C  ts_D_alternateWith_C;
  TState_S_subclock_C  ts_S_subclock_C;

};
struct TState_DiagnosticGuard
{
  TState_Diagnostic  ts_Diagnostic;

};
struct TState_getTemperature
{
  AutState  autState;

};
struct TState_TCS_o1
{
  int  nb_r;
  int  nb_i;
  float  temp;
  Timer diagnostic_to_control = current_time;
  TState_getTemperature  ts_getTemperature;
  TState_DiagnosticGuard  ts_DiagnosticGuard;

};
struct TState_P_discretizedBy_10
{
  int  periodic_sense_occurence;
  Timer periodic_sense_timer = current_time;
  AutState  autState;

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
struct TState_iUr
{
  AutState  autState;

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
struct TState_r_precede_i
{
  int  counter;
  AutState  autState;

};
struct TState_i_alternatesWith_r
{
  TState_r_precede_i  ts_r_precede_i;
  TState_IbeforeR  ts_IbeforeR;

};
struct TState_InsertOrRemoveRod
{
  TState_i_alternatesWith_r  ts_i_alternatesWith_r;
  TState_exclusion  ts_exclusion;

};
struct TState_T1
{
  TState_InsertOrRemoveRod  ts_InsertOrRemoveRod;
  TState_iUr  ts_iUr;

};
struct TState_TCS4
{
  TState_T1  ts_T1;
  TState_P_alternateWith_Z  ts_P_alternateWith_Z;

};
struct TState_Control
{
  TState_TCS4  ts_TCS4;
  TState_P_discretizedBy_10  ts_P_discretizedBy_10;

};
struct TState_ControlGuard
{
  TState_Control  ts_Control;

};
struct TState_TCS
{
  int  i;
  int  z;
  int  nb_i;
  Timer diagnostic_to_control = current_time;
  int  p;
  int  nb_r;
  int  MIN;
  int  r;
  int  MAX;
  int  c;
  int  s;
  int  d;
  float  temp;
  TState_ControlGuard  ts_ControlGuard;
  TState_TCS_o1  ts_TCS_o1;

};
const std::vector<AutState>  shallow_final_r_precede_i = {S0};
const std::vector<AutState>  shallow_final_IbeforeR = {S0};
const std::vector<AutState>  shallow_final_exclusion = {S0};
TState_TCS  ts_TCS;
std::time_t  step_time = 1.0E9;
Timer  last_event_time = 0;

int    get_temperature(int  p0)
{
	int  exec = 0;
	if(ts_TCS.ts_TCS_o1.ts_getTemperature.autState == S0)
	{
				ts_TCS.temp=p0;
				if((ts_TCS.MIN<ts_TCS.temp)&&(ts_TCS.temp<ts_TCS.MAX)){
				ts_TCS.diagnostic_to_control.reset_clock(current_time);
				}
				;ts_TCS.ts_TCS_o1.ts_getTemperature.autState = S0;
				exec = 1;
	
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
	if((ts_TCS.diagnostic_to_control.expired(1E11, current_time)  && ((((((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.counter != 2) || (p0[ts_TCS.i] == '0') ) ) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.counter != 0) || (p0[ts_TCS.r] == '0') ) )) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) )) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) )) && ((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS.z] == '0') ) ) || (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS.p] == '0') ) ))) && ((ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '0') &&! (ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ) || (ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '1') && (ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )))))
	{
			if(((((((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.counter != 2) || (p0[ts_TCS.i] == '0') ) ) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.counter != 0) || (p0[ts_TCS.r] == '0') ) )) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) )) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) )) && ((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS.z] == '0') ) ) || (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS.p] == '0') ) ))) && ((ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '0') &&! (ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ) || (ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '1') && (ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))))
			{
				if((((((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.counter != 2) || (p0[ts_TCS.i] == '0') ) ) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.counter != 0) || (p0[ts_TCS.r] == '0') ) )) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) )) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) )) && ((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS.z] == '0') ) ) || (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS.p] == '0') ) ))))
				{
					if(((((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.counter != 2) || (p0[ts_TCS.i] == '0') ) ) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.counter != 0) || (p0[ts_TCS.r] == '0') ) )) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) )) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) )))
					{
						if((((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.counter != 2) || (p0[ts_TCS.i] == '0') ) ) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.counter != 0) || (p0[ts_TCS.r] == '0') ) )) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) )))
						{
							if(((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.counter != 2) || (p0[ts_TCS.i] == '0') ) ) && (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.counter != 0) || (p0[ts_TCS.r] == '0') ) )))
							{
								if((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.counter != 2) || (p0[ts_TCS.i] == '0') ) ))
								{
									clockCounterDiff(ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.counter,ts_TCS.i,ts_TCS.r,p0);ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState = S0;
									exec = 1;
								
								}
								if((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.counter != 0) || (p0[ts_TCS.r] == '0') ) ))
								{
									clockCounterDiff(ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.counter,ts_TCS.r,ts_TCS.i,p0);ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState = S0;
									exec = 1;
								
								}
							
							}
							if((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState == S0 && ((p0[ts_TCS.i] == '0') || (p0[ts_TCS.r] == '0')) ))
							{
								ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState = S0;
								exec = 1;
							
							}
						
						}
						if((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_iUr.autState == S0 && ( (p0[ts_TCS.z]-'0') == ((p0[ts_TCS.r]-'0')+(p0[ts_TCS.i]-'0')) ) ))
						{
							ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_iUr.autState = S0;
							exec = 1;
						
						}
					
					}
					if((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS.z] == '0') ) ))
					{
							clockCounterDiff(ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.counter,ts_TCS.z,ts_TCS.p,p0);ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
							exec = 1;
					
					}else if((ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS.p] == '0') ) ))
					{
							clockCounterDiff(ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.counter,ts_TCS.p,ts_TCS.z,p0);ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
							exec = 1;
					
					}
				
				}
				if((ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '0') &&! (ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
				{
					ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.autState = S0;
					exec = 1;
				
				}else if((ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS.p] == '1') && (ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
				{
					ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);
					;ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.autState = S0;
					exec = 1;
				
				}
				std::cout<<"\nControl mode action execution\n";
			}
	
	}
	if((! (ts_TCS.diagnostic_to_control.expired(1E11, current_time))  && (((ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS.d] == '0') ) ) && (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ( (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS.c] == '0') ) )) && (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS.s] == '0') || (p0[ts_TCS.c] == '1')) ))))
	{
				if((((ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS.d] == '0') ) ) && (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ( (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS.c] == '0') ) )) && (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS.s] == '0') || (p0[ts_TCS.c] == '1')) )))
				{
					if(((ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS.d] == '0') ) ) && (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ( (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS.c] == '0') ) )))
					{
						if((ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS.d] == '0') ) ))
						{
							clockCounterDiff(ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.counter,ts_TCS.d,ts_TCS.c,p0);ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
							exec = 1;
						
						}
						if((ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ( (ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS.c] == '0') ) ))
						{
							clockCounterDiff(ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.counter,ts_TCS.c,ts_TCS.d,p0);ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
							exec = 1;
						
						}
					
					}
					if((ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS.s] == '0') || (p0[ts_TCS.c] == '1')) ))
					{
						ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_S_subclock_C.autState = S0;
						exec = 1;
					
					}
					std::cout<<"\nDiagnostic mode action execution\n";
					;
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
	ts_TCS.i = i;
	ts_TCS.z = z;
	ts_TCS.nb_i = 0;
	ts_TCS.diagnostic_to_control.reset_clock(current_time);
	ts_TCS.p = p;
	ts_TCS.nb_r = 0;
	ts_TCS.MIN = MIN;
	ts_TCS.r = r;
	ts_TCS.MAX = MAX;
	ts_TCS.c = c;
	ts_TCS.s = s;
	ts_TCS.d = d;
	ts_TCS.temp = 0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.autState = S0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_r_precede_i.counter = 0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.autState = S0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_i_alternatesWith_r.ts_IbeforeR.counter = 0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_InsertOrRemoveRod.ts_exclusion.autState = S0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_T1.ts_iUr.autState = S0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_P_precede_Z.counter = 0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_TCS4.ts_P_alternateWith_Z.ts_Z_precede_P.counter = 0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.autState = S0;
	ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.periodic_sense_occurence = 1;
	ts_TCS.ts_ControlGuard.ts_Control.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);
	ts_TCS.ts_TCS_o1.nb_r = 0;
	ts_TCS.ts_TCS_o1.nb_i = 0;
	ts_TCS.ts_TCS_o1.temp = 0;
	ts_TCS.ts_TCS_o1.diagnostic_to_control.reset_clock(current_time);
	ts_TCS.ts_TCS_o1.ts_getTemperature.autState = S0;
	ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
	ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_C_precede_D.counter = 0;
	ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
	ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_D_alternateWith_C.ts_D_precede_C.counter = 0;
	ts_TCS.ts_TCS_o1.ts_DiagnosticGuard.ts_Diagnostic.ts_S_subclock_C.autState = S0;
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("get_temperature") == 0)
		{
			bool  flag = 0;
			if(_evt.params.size() == 1)
			{
				int  p0;
				p0 = Types::get_int(_evt.params[0], flag);
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
