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
  PeriodicSenseLoop,
  S0,
  S1,
  S2
};
struct TState_ObserverCheckResponse
{
  AutState  autState;

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
  Timer right_clock_RprecedeI = current_time;
  Timer left_clock_IbeforeR = current_time;
  TState_IbeforeR  ts_IbeforeR;
  TState_RprecedeI  ts_RprecedeI;

};
struct TState_exclusion
{
  AutState  autState;

};
struct TState_T3
{
  Timer right_clock_T4 = current_time;
  Timer left_clock_exclusion = current_time;
  TState_exclusion  ts_exclusion;
  TState_T4  ts_T4;

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
struct TState_P_precede_Z
{
  int  counter;
  AutState  autState;

};
struct TState_Z_precede_P
{
  int  counter;
  AutState  autState;

};
struct TState_P_alternateWith_Z
{
  Timer right_clock_P_precede_Z = current_time;
  Timer left_clock_Z_precede_P = current_time;
  TState_Z_precede_P  ts_Z_precede_P;
  TState_P_precede_Z  ts_P_precede_Z;

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
struct TState_TCS_Observer_module
{
  int  nb_r;
  int  nb_i;
  Timer diagnostic_to_control = current_time;
  Timer right_clock_Control_CCSL = current_time;
  Timer left_clock_Diagnostic_CCSL = current_time;
  TState_Diagnostic_CCSL  ts_Diagnostic_CCSL;
  TState_Control_CCSL  ts_Control_CCSL;

};
struct TState_CallObserver
{
  CallState  callState;
  TState_TCS_Observer_module  ts_TCS_Observer_module;

};
struct TState_Observer
{
  Timer left_clock_CallObserver = current_time;
  Timer right_clock_ObserverCheckResponse = current_time;
  TState_CallObserver  ts_CallObserver;
  TState_ObserverCheckResponse  ts_ObserverCheckResponse;

};
struct TState_ASTDFromCCSLSpecGuard
{
  bool  observer_response;
  TState_Observer  ts_Observer;

};
struct TState_getRemoveRod
{
  AutState  autState;

};
struct TState_getStatusUpdate
{
  AutState  autState;

};
struct TState_TransformTransitionToCcslTick_o4
{
  Timer right_clock_getRemoveRod = current_time;
  Timer left_clock_getStatusUpdate = current_time;
  TState_getStatusUpdate  ts_getStatusUpdate;
  TState_getRemoveRod  ts_getRemoveRod;

};
struct TState_getDiagnostic
{
  AutState  autState;

};
struct TState_TransformTransitionToCcslTick_o3
{
  Timer right_clock_TransformTransitionToCcslTick_o4 = current_time;
  Timer left_clock_getDiagnostic = current_time;
  TState_getDiagnostic  ts_getDiagnostic;
  TState_TransformTransitionToCcslTick_o4  ts_TransformTransitionToCcslTick_o4;

};
struct TState_getReconfig
{
  AutState  autState;

};
struct TState_TransformTransitionToCcslTick_o2
{
  Timer right_clock_TransformTransitionToCcslTick_o3 = current_time;
  Timer left_clock_getReconfig = current_time;
  TState_getReconfig  ts_getReconfig;
  TState_TransformTransitionToCcslTick_o3  ts_TransformTransitionToCcslTick_o3;

};
struct TState_getPeriodicSense
{
  AutState  autState;

};
struct TState_TransformTransitionToCcslTick_o1
{
  Timer left_clock_getPeriodicSense = current_time;
  Timer right_clock_TransformTransitionToCcslTick_o2 = current_time;
  TState_getPeriodicSense  ts_getPeriodicSense;
  TState_TransformTransitionToCcslTick_o2  ts_TransformTransitionToCcslTick_o2;

};
struct TState_getInsertRod
{
  AutState  autState;

};
struct TState_TransformTransitionToCcslTick
{
  Timer left_clock_getInsertRod = current_time;
  Timer right_clock_TransformTransitionToCcslTick_o1 = current_time;
  TState_getInsertRod  ts_getInsertRod;
  TState_TransformTransitionToCcslTick_o1  ts_TransformTransitionToCcslTick_o1;

};
struct TState_CallTransformer
{
  CallState  callState;
  TState_TransformTransitionToCcslTick  ts_TransformTransitionToCcslTick;

};
struct TState_PeriodicSenseLoop
{
  AutState  autState;

};
struct TState_ExecuteControl
{
  Timer periodic_timer = current_time;
  AutState  autState;
  TState_PeriodicSenseLoop  ts_PeriodicSenseLoop;

};
struct TState_Control
{
  TState_ExecuteControl  ts_ExecuteControl;

};
struct TState_updateTemperature
{
  AutState  autState;

};
struct TState_ExecuteDiagnostic
{
  AutState  autState;

};
struct TState_Diagnostic
{
  TState_ExecuteDiagnostic  ts_ExecuteDiagnostic;

};
struct TState_ASTDSpecPart1
{
  Timer left_clock_Diagnostic = current_time;
  Timer right_clock_updateTemperature = current_time;
  TState_Diagnostic  ts_Diagnostic;
  TState_updateTemperature  ts_updateTemperature;

};
struct TState_ASTDSpec
{
  Timer left_clock_ASTDSpecPart1 = current_time;
  Timer right_clock_Control = current_time;
  TState_ASTDSpecPart1  ts_ASTDSpecPart1;
  TState_Control  ts_Control;

};
struct TState_ASTDSpecAndTransformer
{
  Timer right_clock_CallTransformer = current_time;
  Timer left_clock_ASTDSpec = current_time;
  TState_ASTDSpec  ts_ASTDSpec;
  TState_CallTransformer  ts_CallTransformer;

};
struct TState_ASTDSpecGuard
{
  TState_ASTDSpecAndTransformer  ts_ASTDSpecAndTransformer;

};
struct TState_TCS_Observer
{
  int  d;
  int  c;
  Timer diagnostic_to_control = current_time;
  int  i;
  int  p;
  int  MIN;
  int  s;
  int  MAX;
  int  r;
  bool  accept;
  bool  withChange;
  int  nb_remove;
  std::string   clocks;
  float  temperature;
  int  nb_insert;
  int  z;
  Timer right_clock_ASTDFromCCSLSpecGuard = current_time;
  Timer left_clock_ASTDSpecGuard = current_time;
  TState_ASTDSpecGuard  ts_ASTDSpecGuard;
  TState_ASTDFromCCSLSpecGuard  ts_ASTDFromCCSLSpecGuard;

};
const std::vector<AutState>  shallow_final_ExecuteControl = {S1};
TState_TCS_Observer  ts_TCS_Observer;
std::time_t  step_time = 1.0E9;
Timer  last_event_time = 0;

int    Step()
{
	int  exec = 0;
	current_time = step_time+current_time;
	if((ts_TCS_Observer.clocks == ""  && ((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ! ts_TCS_Observer.withChange )) || (ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.MIN < ts_TCS_Observer.temperature) && (ts_TCS_Observer.temperature < ts_TCS_Observer.MAX)) )))))
	{
		if((ts_TCS_Observer.clocks == ""  && ((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ! ts_TCS_Observer.withChange )) || (ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.MIN < ts_TCS_Observer.temperature) && (ts_TCS_Observer.temperature < ts_TCS_Observer.MAX)) )))))
		{
			if(((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ! ts_TCS_Observer.withChange )) || (ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.MIN < ts_TCS_Observer.temperature) && (ts_TCS_Observer.temperature < ts_TCS_Observer.MAX)) ))))
			{
				if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ! ts_TCS_Observer.withChange )))
				{
					if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ! ts_TCS_Observer.withChange )))
					{
						if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ! ts_TCS_Observer.withChange )))
						{
							if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ! ts_TCS_Observer.withChange ))
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState = S0;
								exec = 1;
							
							}
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.left_clock_Diagnostic.reset_clock(current_time);
						}
					
					}
					if(exec)
					{
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.left_clock_ASTDSpecPart1.reset_clock(current_time);
					}
				
				}
				if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.MIN < ts_TCS_Observer.temperature) && (ts_TCS_Observer.temperature < ts_TCS_Observer.MAX)) )))
				{
					if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.MIN < ts_TCS_Observer.temperature) && (ts_TCS_Observer.temperature < ts_TCS_Observer.MAX)) )))
					{
						if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.MIN < ts_TCS_Observer.temperature) && (ts_TCS_Observer.temperature < ts_TCS_Observer.MAX)) ))
						{
							ts_TCS_Observer.diagnostic_to_control.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState = S1;
							exec = 1;
						
						}
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.right_clock_Control.reset_clock(current_time);
					}
				
				}
				if(exec)
				{
					ts_TCS_Observer.accept=true;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.left_clock_ASTDSpec.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if(ts_TCS_Observer.accept){
				cout <<" ASTD specification recognizes action\n";
				}else{
				cout <<" ASTD specification don't recognizes action\n";
				}
				
				;
			}
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
		}
	
	}
	if((ts_TCS_Observer.clocks != ""  && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState == NOTCALLED && ((((S0 == S0 && ((0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (S0 == S0 && ( (0 != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((S0 == S0 || (S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((S0 == S0 && ( (0 != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (S0 == S0 && ( (0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((S1 == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((S0 == S0 && ( (0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (S0 == S0 && ( (0 != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))))))) || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState == CALLED && ((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))))))))) || ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_ObserverCheckResponse.autState == S0)))
	{
		if((ts_TCS_Observer.clocks != ""  && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState == NOTCALLED && ((((S0 == S0 && ((0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (S0 == S0 && ( (0 != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((S0 == S0 || (S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((S0 == S0 && ( (0 != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (S0 == S0 && ( (0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((S1 == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((S0 == S0 && ( (0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (S0 == S0 && ( (0 != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))))))) || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState == CALLED && ((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))))))))) || ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_ObserverCheckResponse.autState == S0)))
		{
			if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState == NOTCALLED && ((((S0 == S0 && ((0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (S0 == S0 && ( (0 != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((S0 == S0 || (S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((S0 == S0 && ( (0 != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (S0 == S0 && ( (0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((S1 == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((S0 == S0 && ( (0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (S0 == S0 && ( (0 != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))))))) || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState == CALLED && ((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))))))))))
			{
				if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState == NOTCALLED && ((((S0 == S0 && ((0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (S0 == S0 && ( (0 != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((S0 == S0 || (S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((S0 == S0 && ( (0 != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (S0 == S0 && ( (0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((S1 == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((S0 == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((S0 == S0 && ( (0 != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (S0 == S0 && ( (0 != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))))))))
				{
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState = CALLED;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.nb_r = 0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.nb_i = 0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.diagnostic_to_control.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.right_clock_Control_CCSL.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.left_clock_Diagnostic_CCSL.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.left_clock_D_alternateWith_C.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.right_clock_S_subclock_C.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.right_clock_C_precede_D.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.left_clock_D_precede_C.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter = 0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter = 0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.right_clock_T1.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.right_clock_T2.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.left_clock_P_alternateWith_Z.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.right_clock_P_precede_Z.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.left_clock_Z_precede_P.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter = 0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter = 0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.right_clock_T3.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.left_clock_iUr.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.right_clock_T4.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.left_clock_exclusion.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.right_clock_RprecedeI.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.left_clock_IbeforeR.reset_clock(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver);
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState = S0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter = 0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState = S0;
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter = 0;
					if(((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))))))))
					{
						if((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )))
						{
							if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )))
							{
								if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ))
								{
									clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter,ts_TCS_Observer.c,ts_TCS_Observer.d,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.left_clock_D_precede_C.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
									exec = 1;
								
								}
								if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) ))
								{
									clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter,ts_TCS_Observer.d,ts_TCS_Observer.c,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.right_clock_C_precede_D.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
									exec = 1;
								
								}
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.left_clock_D_alternateWith_C.reset_clock(current_time);
							}
							if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) ))
							{
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.right_clock_S_subclock_C.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
								exec = 1;
							
							}
							ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.left_clock_Diagnostic_CCSL.reset_clock(current_time);
						}
						if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))))))
						{
							if(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0)
							{
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
								exec = 1;
							
							}else if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
							{
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
								exec = 1;
							
							}
							if((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))))))
							{
								if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )))
								{
									if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ))
									{
										clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter,ts_TCS_Observer.p,ts_TCS_Observer.z,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.left_clock_Z_precede_P.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
										exec = 1;
									
									}
									if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) ))
									{
										clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter,ts_TCS_Observer.z,ts_TCS_Observer.p,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.right_clock_P_precede_Z.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
										exec = 1;
									
									}
									ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.left_clock_P_alternateWith_Z.reset_clock(current_time);
								}
								if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))))
								{
									if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ))
									{
										ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.left_clock_iUr.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
										exec = 1;
									
									}
									if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))))
									{
										if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ))
										{
											ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.left_clock_exclusion.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
											exec = 1;
										
										}
										if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))
										{
											if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ))
											{
												clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter,ts_TCS_Observer.r,ts_TCS_Observer.i,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.left_clock_IbeforeR.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState = S0;
												exec = 1;
											
											}
											if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))
											{
												clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter,ts_TCS_Observer.i,ts_TCS_Observer.r,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.right_clock_RprecedeI.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState = S0;
												exec = 1;
											
											}
											ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.right_clock_T4.reset_clock(current_time);
										}
										ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.right_clock_T3.reset_clock(current_time);
									}
									ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.right_clock_T2.reset_clock(current_time);
								}
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.right_clock_T1.reset_clock(current_time);
							}
							ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.right_clock_Control_CCSL.reset_clock(current_time);
						}
						ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.observer_response=true;
					}
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver.reset_clock(current_time);
				}else if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState == CALLED && ((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))))))))
				{
					if(((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))))))))
					{
						if((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) )))
						{
							if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) )))
							{
								if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '0')) ))
								{
									clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter,ts_TCS_Observer.c,ts_TCS_Observer.d,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.left_clock_D_precede_C.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
									exec = 1;
								
								}
								if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.d] == '0') ) ))
								{
									clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter,ts_TCS_Observer.d,ts_TCS_Observer.c,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.right_clock_C_precede_D.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
									exec = 1;
								
								}
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.left_clock_D_alternateWith_C.reset_clock(current_time);
							}
							if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.s] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.c] == '1')) ))
							{
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.right_clock_S_subclock_C.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
								exec = 1;
							
							}
							ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.left_clock_Diagnostic_CCSL.reset_clock(current_time);
						}
						if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))))))
						{
							if(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0)
							{
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
								exec = 1;
							
							}else if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
							{
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
								exec = 1;
							
							}
							if((((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))))))
							{
								if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) )))
								{
									if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (ts_TCS_Observer.clocks[ts_TCS_Observer.p] == '0') ) ))
									{
										clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter,ts_TCS_Observer.p,ts_TCS_Observer.z,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.left_clock_Z_precede_P.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
										exec = 1;
									
									}
									if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.z] == '0') ) ))
									{
										clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter,ts_TCS_Observer.z,ts_TCS_Observer.p,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.right_clock_P_precede_Z.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
										exec = 1;
									
									}
									ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.left_clock_P_alternateWith_Z.reset_clock(current_time);
								}
								if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))))
								{
									if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (ts_TCS_Observer.clocks[ts_TCS_Observer.z]-'0') == ((ts_TCS_Observer.clocks[ts_TCS_Observer.r]-'0')+(ts_TCS_Observer.clocks[ts_TCS_Observer.i]-'0')) ) ))
									{
										ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.left_clock_iUr.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
										exec = 1;
									
									}
									if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))))
									{
										if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0')) ))
										{
											ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.left_clock_exclusion.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
											exec = 1;
										
										}
										if(((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) )))
										{
											if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (ts_TCS_Observer.clocks[ts_TCS_Observer.r] == '0') ) ))
											{
												clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter,ts_TCS_Observer.r,ts_TCS_Observer.i,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.left_clock_IbeforeR.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState = S0;
												exec = 1;
											
											}
											if((ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (ts_TCS_Observer.clocks[ts_TCS_Observer.i] == '0') ) ))
											{
												clockCounterDiff(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter,ts_TCS_Observer.i,ts_TCS_Observer.r,ts_TCS_Observer.clocks);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.right_clock_RprecedeI.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState = S0;
												exec = 1;
											
											}
											ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.right_clock_T4.reset_clock(current_time);
										}
										ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.ts_T2.right_clock_T3.reset_clock(current_time);
									}
									ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.ts_T1.right_clock_T2.reset_clock(current_time);
								}
								ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.ts_Control_CCSL.right_clock_T1.reset_clock(current_time);
							}
							ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.ts_TCS_Observer_module.right_clock_Control_CCSL.reset_clock(current_time);
						}
						ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.observer_response=true;
					}
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver.reset_clock(current_time);
				}
			
			}
			if(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_ObserverCheckResponse.autState == S0)
			{
				if(ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_ObserverCheckResponse.autState == S0)
				{
					ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.right_clock_ObserverCheckResponse.reset_clock(current_time);ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_ObserverCheckResponse.autState = S0;
					exec = 1;
				
				}
			
			}
			if((ts_TCS_Observer.accept && ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.observer_response)||(!ts_TCS_Observer.accept && !ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.observer_response)){ts_TCS_Observer.clocks = "";ts_TCS_Observer.accept=false;
			cout <<" Observer validates ASTD specification action\n";
			ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.observer_response=false;
			}else{
			cout <<" Observer invalidates ASTD specification action\n";
			}
			;
			ts_TCS_Observer.right_clock_ASTDFromCCSLSpecGuard.reset_clock(current_time);
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
	if((ts_TCS_Observer.clocks == ""  && ((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ts_TCS_Observer.withChange )) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)))))
	{
		if((ts_TCS_Observer.clocks == ""  && ((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ts_TCS_Observer.withChange )) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)))))
		{
			if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ts_TCS_Observer.withChange )))
			{
				if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ts_TCS_Observer.withChange )))
				{
					if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ts_TCS_Observer.withChange )))
					{
						if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ts_TCS_Observer.withChange )))
						{
							if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S2 && ts_TCS_Observer.withChange ))
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState = S0;
								exec = 1;
							
							}
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.left_clock_Diagnostic.reset_clock(current_time);
						}
					
					}
					if(exec)
					{
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.left_clock_ASTDSpecPart1.reset_clock(current_time);
					}
				
				}
				if(exec)
				{
					ts_TCS_Observer.accept=true;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.left_clock_ASTDSpec.reset_clock(current_time);
				}
			
			}
			if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)))
			{
				if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0))
				{
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState = CALLED;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.left_clock_getInsertRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.left_clock_getPeriodicSense.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.left_clock_getReconfig.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.left_clock_getDiagnostic.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.right_clock_getRemoveRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.left_clock_getStatusUpdate.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState = S0;
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
							{
								if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
								{
									if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
									{
										if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
										{
											ts_TCS_Observer.clocks="0110000";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.left_clock_getStatusUpdate.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState = S0;
											exec = 1;
										
										}
									
									}
									if(exec)
									{
										ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(current_time);
									}
								
								}
								if(exec)
								{
									ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(current_time);
								}
							
							}
							if(exec)
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(current_time);
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0))
				{
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
							{
								if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
								{
									if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
									{
										if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState == S0)
										{
											ts_TCS_Observer.clocks="0110000";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.left_clock_getStatusUpdate.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState = S0;
											exec = 1;
										
										}
									
									}
									if(exec)
									{
										ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(current_time);
									}
								
								}
								if(exec)
								{
									ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(current_time);
								}
							
							}
							if(exec)
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(current_time);
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if(ts_TCS_Observer.accept){
				cout <<" ASTD specification recognizes action\n";
				}else{
				cout <<" ASTD specification don't recognizes action\n";
				}
				
				;
			}
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
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
	if((ts_TCS_Observer.clocks == ""  && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1)) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)))))
	{
		if((ts_TCS_Observer.clocks == ""  && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1)) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)))))
		{
			if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1)))
			{
				if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1)))
				{
					if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1)))
					{
						if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1))
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1)
							{
								ts_TCS_Observer.nb_remove++;ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState = S0;
								exec = 1;
							
							}
						
						}
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.right_clock_Control.reset_clock(current_time);
					}
				
				}
				if(exec)
				{
					ts_TCS_Observer.accept=true;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.left_clock_ASTDSpec.reset_clock(current_time);
				}
			
			}
			if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)))
			{
				if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0))
				{
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState = CALLED;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.left_clock_getInsertRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.left_clock_getPeriodicSense.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.left_clock_getReconfig.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.left_clock_getDiagnostic.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.right_clock_getRemoveRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.left_clock_getStatusUpdate.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState = S0;
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
							{
								if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
								{
									if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
									{
										if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
										{
											ts_TCS_Observer.clocks="0000101";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.right_clock_getRemoveRod.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState = S0;
											exec = 1;
										
										}
									
									}
									if(exec)
									{
										ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(current_time);
									}
								
								}
								if(exec)
								{
									ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(current_time);
								}
							
							}
							if(exec)
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(current_time);
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0))
				{
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
							{
								if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
								{
									if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
									{
										if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState == S0)
										{
											ts_TCS_Observer.clocks="0000101";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.right_clock_getRemoveRod.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState = S0;
											exec = 1;
										
										}
									
									}
									if(exec)
									{
										ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(current_time);
									}
								
								}
								if(exec)
								{
									ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(current_time);
								}
							
							}
							if(exec)
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(current_time);
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if(ts_TCS_Observer.accept){
				cout <<" ASTD specification recognizes action\n";
				}else{
				cout <<" ASTD specification don't recognizes action\n";
				}
				
				;
			}
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    reconfig(bool  p0)
{
	int  exec = 0;
	if((ts_TCS_Observer.clocks == ""  && ((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S1) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)))))
	{
		if((ts_TCS_Observer.clocks == ""  && ((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S1) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)))))
		{
			if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S1))
			{
				if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S1))
				{
					if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S1))
					{
						if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S1))
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S1)
							{
								
								ts_TCS_Observer.withChange=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState = S2;
								exec = 1;
							
							}
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.left_clock_Diagnostic.reset_clock(current_time);
						}
					
					}
					if(exec)
					{
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.left_clock_ASTDSpecPart1.reset_clock(current_time);
					}
				
				}
				if(exec)
				{
					ts_TCS_Observer.accept=true;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.left_clock_ASTDSpec.reset_clock(current_time);
				}
			
			}
			if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)))
			{
				if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0))
				{
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState = CALLED;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.left_clock_getInsertRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.left_clock_getPeriodicSense.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.left_clock_getReconfig.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.left_clock_getDiagnostic.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.right_clock_getRemoveRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.left_clock_getStatusUpdate.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState = S0;
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)
							{
								if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)
								{
									ts_TCS_Observer.clocks="0000000";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.left_clock_getReconfig.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState = S0;
									exec = 1;
								
								}
							
							}
							if(exec)
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(current_time);
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0))
				{
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)
							{
								if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState == S0)
								{
									ts_TCS_Observer.clocks="0000000";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.left_clock_getReconfig.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState = S0;
									exec = 1;
								
								}
							
							}
							if(exec)
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(current_time);
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if(ts_TCS_Observer.accept){
				cout <<" ASTD specification recognizes action\n";
				}else{
				cout <<" ASTD specification don't recognizes action\n";
				}
				
				;
			}
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    set_temperature(float  p0)
{
	int  exec = 0;
	if((ts_TCS_Observer.clocks == ""  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_updateTemperature.autState == S0))
	{
		if((ts_TCS_Observer.clocks == ""  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_updateTemperature.autState == S0))
		{
			if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_updateTemperature.autState == S0)
			{
				if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_updateTemperature.autState == S0)
				{
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_updateTemperature.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_updateTemperature.autState == S0)
						{
							ts_TCS_Observer.temperature=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.right_clock_updateTemperature.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_updateTemperature.autState = S0;
							exec = 1;
						
						}
					
					}
					if(exec)
					{
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.left_clock_ASTDSpecPart1.reset_clock(current_time);
					}
				
				}
				if(exec)
				{
					ts_TCS_Observer.accept=true;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.left_clock_ASTDSpec.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if(ts_TCS_Observer.accept){
				cout <<" ASTD specification recognizes action\n";
				}else{
				cout <<" ASTD specification don't recognizes action\n";
				}
				
				;
			}
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
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
	if((ts_TCS_Observer.clocks == ""  && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove != 2)) ))) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState == S0)))))
	{
		if((ts_TCS_Observer.clocks == ""  && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove != 2)) ))) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState == S0)))))
		{
			if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove != 2)) ))))
			{
				if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove != 2)) ))))
				{
					if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove != 2)) ))))
					{
						if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove != 2)) )))
						{
							if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove != 2)) ))
							{
								ts_TCS_Observer.nb_insert++;ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState = S0;
								exec = 1;
							
							}
						
						}
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.right_clock_Control.reset_clock(current_time);
					}
				
				}
				if(exec)
				{
					ts_TCS_Observer.accept=true;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.left_clock_ASTDSpec.reset_clock(current_time);
				}
			
			}
			if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState == S0)))
			{
				if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0))
				{
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState = CALLED;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.left_clock_getInsertRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.left_clock_getPeriodicSense.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.left_clock_getReconfig.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.left_clock_getDiagnostic.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.right_clock_getRemoveRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.left_clock_getStatusUpdate.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState = S0;
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState == S0)
						{
							ts_TCS_Observer.clocks="0000011";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.left_clock_getInsertRod.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState = S0;
							exec = 1;
						
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState == S0))
				{
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState == S0)
						{
							ts_TCS_Observer.clocks="0000011";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.left_clock_getInsertRod.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState = S0;
							exec = 1;
						
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if(ts_TCS_Observer.accept){
				cout <<" ASTD specification recognizes action\n";
				}else{
				cout <<" ASTD specification don't recognizes action\n";
				}
				
				;
			}
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
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
	if((ts_TCS_Observer.clocks == ""  && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) ) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S0 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) )))) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0)))))
	{
		if((ts_TCS_Observer.clocks == ""  && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) ) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S0 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) )))) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0)))))
		{
			if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) ) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S0 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) )))))
			{
				if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) ) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S0 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) )))))
				{
					if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) ) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S0 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) )))))
					{
						if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState == PeriodicSenseLoop && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) ) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S0 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) ))))
						{
							if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S1 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) ))
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState = S1;
								exec = 1;
							
							}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState == S0 && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.expired(1E10, current_time) ))
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState = S1;
								exec = 1;
							
							}
						
						}
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.right_clock_Control.reset_clock(current_time);
					}
				
				}
				if(exec)
				{
					ts_TCS_Observer.accept=true;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.left_clock_ASTDSpec.reset_clock(current_time);
				}
			
			}
			if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0)))
			{
				if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0))
				{
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState = CALLED;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.left_clock_getInsertRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.left_clock_getPeriodicSense.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.left_clock_getReconfig.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.left_clock_getDiagnostic.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.right_clock_getRemoveRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.left_clock_getStatusUpdate.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState = S0;
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0)
							{
								ts_TCS_Observer.clocks="0001000";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.left_clock_getPeriodicSense.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState = S0;
								exec = 1;
							
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0))
				{
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState == S0)
							{
								ts_TCS_Observer.clocks="0001000";ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.left_clock_getPeriodicSense.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState = S0;
								exec = 1;
							
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if(ts_TCS_Observer.accept){
				cout <<" ASTD specification recognizes action\n";
				}else{
				cout <<" ASTD specification don't recognizes action\n";
				}
				
				;
			}
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
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
	if((ts_TCS_Observer.clocks == ""  && ((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S0) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)))))
	{
		if((ts_TCS_Observer.clocks == ""  && ((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S0) || ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)))))
		{
			if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S0))
			{
				if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S0))
				{
					if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S0))
					{
						if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S0))
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState == S0)
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState = S1;
								exec = 1;
							
							}
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.left_clock_Diagnostic.reset_clock(current_time);
						}
					
					}
					if(exec)
					{
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.left_clock_ASTDSpecPart1.reset_clock(current_time);
					}
				
				}
				if(exec)
				{
					ts_TCS_Observer.accept=true;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.left_clock_ASTDSpec.reset_clock(current_time);
				}
			
			}
			if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)))
			{
				if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == NOTCALLED && S0 == S0))
				{
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState = CALLED;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.left_clock_getInsertRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_getInsertRod.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.left_clock_getPeriodicSense.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_getPeriodicSense.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.left_clock_getReconfig.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_getReconfig.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.right_clock_TransformTransitionToCcslTick_o4.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.left_clock_getDiagnostic.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.right_clock_getRemoveRod.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.left_clock_getStatusUpdate.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer);
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getStatusUpdate.autState = S0;
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_TransformTransitionToCcslTick_o4.ts_getRemoveRod.autState = S0;
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
							{
								if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
								{
									if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
									{
										
										ts_TCS_Observer.clocks="1000000";
										;ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.left_clock_getDiagnostic.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState = S0;
										exec = 1;
									
									}
								
								}
								if(exec)
								{
									ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(current_time);
								}
							
							}
							if(exec)
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(current_time);
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState == CALLED && ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0))
				{
					if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
						{
							if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
							{
								if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
								{
									if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState == S0)
									{
										
										ts_TCS_Observer.clocks="1000000";
										;ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.left_clock_getDiagnostic.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.ts_TransformTransitionToCcslTick_o3.ts_getDiagnostic.autState = S0;
										exec = 1;
									
									}
								
								}
								if(exec)
								{
									ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.ts_TransformTransitionToCcslTick_o2.right_clock_TransformTransitionToCcslTick_o3.reset_clock(current_time);
								}
							
							}
							if(exec)
							{
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.ts_TransformTransitionToCcslTick_o1.right_clock_TransformTransitionToCcslTick_o2.reset_clock(current_time);
							}
						
						}
						if(exec)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.ts_TransformTransitionToCcslTick.right_clock_TransformTransitionToCcslTick_o1.reset_clock(current_time);
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
				}
			
			}
			if(exec)
			{
				
				if(ts_TCS_Observer.accept){
				cout <<" ASTD specification recognizes action\n";
				}else{
				cout <<" ASTD specification don't recognizes action\n";
				}
				
				;
			}
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
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
	ts_TCS_Observer.d = 0;
	ts_TCS_Observer.c = 1;
	ts_TCS_Observer.diagnostic_to_control.reset_clock(current_time);
	ts_TCS_Observer.i = 5;
	ts_TCS_Observer.p = 3;
	ts_TCS_Observer.MIN = MIN;
	ts_TCS_Observer.s = 2;
	ts_TCS_Observer.MAX = MAX;
	ts_TCS_Observer.r = 4;
	ts_TCS_Observer.accept = false;
	ts_TCS_Observer.withChange = false;
	ts_TCS_Observer.nb_remove = 0;
	ts_TCS_Observer.clocks = "";
	ts_TCS_Observer.temperature = ts_TCS_Observer.MIN;
	ts_TCS_Observer.nb_insert = 0;
	ts_TCS_Observer.z = 6;
	ts_TCS_Observer.right_clock_ASTDFromCCSLSpecGuard.reset_clock(current_time);
	ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.right_clock_CallTransformer.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.left_clock_ASTDSpec.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.left_clock_ASTDSpecPart1.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.right_clock_Control.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.left_clock_Diagnostic.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.right_clock_updateTemperature.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_Diagnostic.ts_ExecuteDiagnostic.autState = S0;
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_ASTDSpecPart1.ts_updateTemperature.autState = S0;
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.autState = PeriodicSenseLoop;
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.periodic_timer.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_ASTDSpec.ts_Control.ts_ExecuteControl.ts_PeriodicSenseLoop.autState = S0;
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_ASTDSpecAndTransformer.ts_CallTransformer.callState = NOTCALLED;
	ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.observer_response = false;
	ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.left_clock_CallObserver.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.right_clock_ObserverCheckResponse.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_CallObserver.callState = NOTCALLED;
	ts_TCS_Observer.ts_ASTDFromCCSLSpecGuard.ts_Observer.ts_ObserverCheckResponse.autState = S0;
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
		
		}else if(_evt.label.compare("reconfig") == 0)
		{
			bool  flag = 0;
			if(_evt.params.size() == 1)
			{
				bool  p0;
				p0 = Types::get_bool(_evt.params[0]);
				if((!(flag) && reconfig(p0)))
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
		
		}else if(_evt.label.compare("set_temperature") == 0)
		{
			bool  flag = 0;
			if(_evt.params.size() == 1)
			{
				float  p0;
				p0 = Types::get_float(_evt.params[0], flag);
				if((!(flag) && set_temperature(p0)))
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
		
		}else if(_evt.label.compare("periodic_sense") == 0)
		{
			if(periodic_sense())
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
