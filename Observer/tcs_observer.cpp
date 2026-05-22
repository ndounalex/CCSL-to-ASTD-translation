#include "pugixml.cpp"
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
struct TState_Observer3
{
  AutState  autState;

};
struct TState_CheckViolation
{
  AutState  autState;

};
struct TState_DiagnosticExecution
{
  AutState  autState;

};
struct TState_DiagnosticGuard
{
  TState_DiagnosticExecution  ts_DiagnosticExecution;

};
struct TState_ObserverDiagnostic
{
  bool  violation;
  bool  withChange;
  bool  status;
  std::string   my_event;
  Timer left_clock_DiagnosticGuard = current_time;
  Timer right_clock_CheckViolation = current_time;
  TState_DiagnosticGuard  ts_DiagnosticGuard;
  TState_CheckViolation  ts_CheckViolation;

};
struct TState_Observer1
{
  CallState  callState;
  TState_ObserverDiagnostic  ts_ObserverDiagnostic;

};
struct TState_CheckControlViolation
{
  AutState  autState;

};
struct TState_ControlExecution
{
  AutState  autState;

};
struct TState_ControlGuard
{
  TState_ControlExecution  ts_ControlExecution;

};
struct TState_ObserverControl
{
  bool  violation;
  Timer left_clock_ControlGuard = current_time;
  Timer right_clock_CheckControlViolation = current_time;
  TState_ControlGuard  ts_ControlGuard;
  TState_CheckControlViolation  ts_CheckControlViolation;

};
struct TState_Observer2
{
  CallState  callState;
  TState_ObserverControl  ts_ObserverControl;

};
struct TState_ObserverGroup
{
  Timer left_clock_Observer2 = current_time;
  Timer right_clock_Observer1 = current_time;
  TState_Observer2  ts_Observer2;
  TState_Observer1  ts_Observer1;

};
struct TState_ObserverGuard
{
  TState_ObserverGroup  ts_ObserverGroup;

};
struct TState_Observers
{
  Timer left_clock_ObserverGuard = current_time;
  Timer right_clock_Observer3 = current_time;
  TState_ObserverGuard  ts_ObserverGuard;
  TState_Observer3  ts_Observer3;

};
struct TState_TransformTransitionToCcslTick
{
  AutState  autState;

};
struct TState_CallTransformTransition
{
  CallState  callState;
  TState_TransformTransitionToCcslTick  ts_TransformTransitionToCcslTick;

};
struct TState_CallTransformerGuard
{
  TState_CallTransformTransition  ts_CallTransformTransition;

};
struct TState_CCSLTranslationCheckResponse
{
  AutState  autState;

};
struct TState_Program
{
  Timer right_clock_CallTransformerGuard = current_time;
  Timer left_clock_CCSLTranslationCheckResponse = current_time;
  TState_CCSLTranslationCheckResponse  ts_CCSLTranslationCheckResponse;
  TState_CallTransformerGuard  ts_CallTransformerGuard;

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
struct TState_TCS_Observed_module
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
  TState_TCS_Observed_module  ts_TCS_Observed_module;

};
struct TState_ASTDSpecGuard
{
  Timer left_clock_CallObserver = current_time;
  Timer right_clock_Program = current_time;
  TState_CallObserver  ts_CallObserver;
  TState_Program  ts_Program;

};
struct TState_TCS_Observer
{
  int  i;
  float  temperature;
  int  z;
  bool  no_action;
  int  max_temp;
  Timer diagnostic_to_control = current_time;
  int  p;
  std::string   observer_response;
  int  r;
  std::string   events;
  int  c;
  int  s;
  bool  accept;
  int  d;
  bool  withChange;
  int  min_temp;
  int  nb_remove;
  std::string   inputs;
  int  nb_insert;
  Timer left_clock_ASTDSpecGuard = current_time;
  Timer right_clock_Observers = current_time;
  TState_ASTDSpecGuard  ts_ASTDSpecGuard;
  TState_Observers  ts_Observers;

};
TState_TCS_Observer  ts_TCS_Observer;
std::time_t  step_time = 1.0E9;
Timer  last_event_time = 0;

int    Step()
{
	int  exec = 0;
	current_time = step_time+current_time;
	if(((ts_TCS_Observer.inputs != "")  && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.callState == NOTCALLED && (ts_TCS_Observer.inputs != "") ) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.callState == CALLED && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.ts_TransformTransitionToCcslTick.autState == S0 && (ts_TCS_Observer.inputs != "") )))))
	{
					if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.callState == NOTCALLED && (ts_TCS_Observer.inputs != "") ))
					{
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.callState = CALLED;
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.ts_TransformTransitionToCcslTick.autState = S0;
						if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.ts_TransformTransitionToCcslTick.autState == S0 && (ts_TCS_Observer.inputs != "") ))
						{
							
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.d]=='1'){
							ts_TCS_Observer.events = "diagnostic";
							}else{ts_TCS_Observer.events="";}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.c]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events = ts_TCS_Observer.events+"reconfig";
							}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.s]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events = ts_TCS_Observer.events+"status_update";
							}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.p]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events =ts_TCS_Observer.events+"periodic_sense";
							}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.r]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events = ts_TCS_Observer.events+ "remove_rod";
							}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.i]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events = ts_TCS_Observer.events+"insert_rod";
							}
							;ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.ts_TransformTransitionToCcslTick.autState = S0;
							exec = 1;
						
						}
					
					}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.callState == CALLED && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.ts_TransformTransitionToCcslTick.autState == S0 && (ts_TCS_Observer.inputs != "") )))
					{
						if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.ts_TransformTransitionToCcslTick.autState == S0 && (ts_TCS_Observer.inputs != "") ))
						{
							
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.d]=='1'){
							ts_TCS_Observer.events = "diagnostic";
							}else{ts_TCS_Observer.events="";}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.c]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events = ts_TCS_Observer.events+"reconfig";
							}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.s]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events = ts_TCS_Observer.events+"status_update";
							}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.p]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events =ts_TCS_Observer.events+"periodic_sense";
							}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.r]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events = ts_TCS_Observer.events+ "remove_rod";
							}
							if(ts_TCS_Observer.inputs[ts_TCS_Observer.i]=='1'){
							if(ts_TCS_Observer.events!=""){ts_TCS_Observer.events=ts_TCS_Observer.events+",";}
							ts_TCS_Observer.events = ts_TCS_Observer.events+"insert_rod";
							}
							;ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.ts_TransformTransitionToCcslTick.autState = S0;
							exec = 1;
						
						}
					
					}
					ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.right_clock_CallTransformerGuard.reset_clock(current_time);if(exec)
			{
				ts_TCS_Observer.ts_ASTDSpecGuard.right_clock_Program.reset_clock(current_time);
			}
		if(exec)
		{
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
		}
	
	}
	if(((ts_TCS_Observer.events != "") && (ts_TCS_Observer.observer_response != "")  && (((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.callState == NOTCALLED && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ) || (S1 == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ) || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") )) || (ts_TCS_Observer.events == "periodic_sense") || (ts_TCS_Observer.events == "insert_rod") || (ts_TCS_Observer.events == "remove_rod") )) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.callState == CALLED && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ))) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_CheckControlViolation.autState == S0 && (ts_TCS_Observer.events == "periodic_sense") || (ts_TCS_Observer.events == "insert_rod") || (ts_TCS_Observer.events == "remove_rod") )))) || ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.callState == NOTCALLED && (! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((S0 == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ) || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic")  || (S0 == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") )))) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.callState == CALLED && (! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") ))))))))
	{
				if(((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.callState == NOTCALLED && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ) || (S1 == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ) || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") )) || (ts_TCS_Observer.events == "periodic_sense") || (ts_TCS_Observer.events == "insert_rod") || (ts_TCS_Observer.events == "remove_rod") )) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.callState == CALLED && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ))) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_CheckControlViolation.autState == S0 && (ts_TCS_Observer.events == "periodic_sense") || (ts_TCS_Observer.events == "insert_rod") || (ts_TCS_Observer.events == "remove_rod") )))))
				{
					if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.callState == NOTCALLED && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((S1 == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ) || (S1 == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ) || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") )) || (ts_TCS_Observer.events == "periodic_sense") || (ts_TCS_Observer.events == "insert_rod") || (ts_TCS_Observer.events == "remove_rod") )))
					{
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.callState = CALLED;
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation = true;
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.left_clock_ControlGuard.reset_clock(ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.left_clock_Observer2);
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.right_clock_CheckControlViolation.reset_clock(ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.left_clock_Observer2);
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState = S1;
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_CheckControlViolation.autState = S0;
						if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ))))
						{
								if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ))
								{
									
									if(((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove)!=2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) =="insert_rod")){ts_TCS_Observer.nb_insert++;}
									else{
									ts_TCS_Observer.nb_remove++;
									}
									;ts_TCS_Observer.accept=true;ts_TCS_Observer.no_action=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ))
								{
									ts_TCS_Observer.accept=true;ts_TCS_Observer.no_action=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ))
								{
									ts_TCS_Observer.accept=true;ts_TCS_Observer.no_action=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}
								
								if((ts_TCS_Observer.min_temp<ts_TCS_Observer.temperature) && (ts_TCS_Observer.temperature<ts_TCS_Observer.max_temp)){
								ts_TCS_Observer.diagnostic_to_control.reset_clock(current_time);
								ts_TCS_Observer.temperature=100;
								}
								;
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.left_clock_ControlGuard.reset_clock(current_time);
						}
						if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_CheckControlViolation.autState == S0 && (ts_TCS_Observer.events == "periodic_sense") || (ts_TCS_Observer.events == "insert_rod") || (ts_TCS_Observer.events == "remove_rod") ))
						{
								
								if(ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation){cout<<"Violation dans l'execution du mode Control\n";}
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation=true;
								if(ts_TCS_Observer.no_action){
								ts_TCS_Observer.accept=false;
								}else{
								ts_TCS_Observer.no_action=true;
								}
								;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.right_clock_CheckControlViolation.reset_clock(current_time);ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_CheckControlViolation.autState = S0;
								exec = 1;
						
						}
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.left_clock_Observer2.reset_clock(current_time);
					}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.callState == CALLED && ((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ))) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_CheckControlViolation.autState == S0 && (ts_TCS_Observer.events == "periodic_sense") || (ts_TCS_Observer.events == "insert_rod") || (ts_TCS_Observer.events == "remove_rod") ))))
					{
						if((ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ))))
						{
								if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove) != 2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "insert_rod")) || (((ts_TCS_Observer.nb_remove-ts_TCS_Observer.nb_insert) != 0) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "remove_rod")) ))
								{
									
									if(((ts_TCS_Observer.nb_insert-ts_TCS_Observer.nb_remove)!=2) && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) =="insert_rod")){ts_TCS_Observer.nb_insert++;}
									else{
									ts_TCS_Observer.nb_remove++;
									}
									;ts_TCS_Observer.accept=true;ts_TCS_Observer.no_action=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState = S1;
									exec = 1;
								
								}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ))
								{
									ts_TCS_Observer.accept=true;ts_TCS_Observer.no_action=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "periodic_sense") ))
								{
									ts_TCS_Observer.accept=true;ts_TCS_Observer.no_action=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_ControlGuard.ts_ControlExecution.autState = S0;
									exec = 1;
								
								}
								
								if((ts_TCS_Observer.min_temp<ts_TCS_Observer.temperature) && (ts_TCS_Observer.temperature<ts_TCS_Observer.max_temp)){
								ts_TCS_Observer.diagnostic_to_control.reset_clock(current_time);
								ts_TCS_Observer.temperature=100;
								}
								;
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.left_clock_ControlGuard.reset_clock(current_time);
						}
						if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_CheckControlViolation.autState == S0 && (ts_TCS_Observer.events == "periodic_sense") || (ts_TCS_Observer.events == "insert_rod") || (ts_TCS_Observer.events == "remove_rod") ))
						{
								
								if(ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation){cout<<"Violation dans l'execution du mode Control\n";}
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.violation=true;
								if(ts_TCS_Observer.no_action){
								ts_TCS_Observer.accept=false;
								}else{
								ts_TCS_Observer.no_action=true;
								}
								;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.right_clock_CheckControlViolation.reset_clock(current_time);ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.ts_ObserverControl.ts_CheckControlViolation.autState = S0;
								exec = 1;
						
						}
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.left_clock_Observer2.reset_clock(current_time);
					}
				
				}
				if(((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.callState == NOTCALLED && (! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((S0 == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ) || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic")  || (S0 == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") )))) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.callState == CALLED && (! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") ))))))
				{
					if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.callState == NOTCALLED && (! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((S0 == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ) || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic")  || (S0 == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") )))))
					{
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.callState = CALLED;
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation = true;
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.withChange = true;
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.status = true;
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.my_event = " ";
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.left_clock_DiagnosticGuard.reset_clock(ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.right_clock_Observer1);
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.right_clock_CheckViolation.reset_clock(ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.right_clock_Observer1);
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState = S0;
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_CheckViolation.autState = S0;
						if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") ))))
						{
								if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ))
								{
									ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.my_event=ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(','));ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic") ))
								{
									ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.my_event=ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(','));ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") ))
								{
									
									ts_TCS_Observer.withChange=ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.status;
									;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.my_event=ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(','));ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState = S2;
									exec = 1;
								
								}
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.left_clock_DiagnosticGuard.reset_clock(current_time);
						}
						if(0)
						{
								
								if(ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation){cout<<"Violation dans l'execution du mode Diagnostic\n";}
								if(ts_TCS_Observer.no_action){
								ts_TCS_Observer.accept=false;
								}else{
								ts_TCS_Observer.no_action=true;
								}
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation=true;
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.my_event="";
								;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.right_clock_CheckViolation.reset_clock(current_time);ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_CheckViolation.autState = S0;
								exec = 1;
						
						}
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.right_clock_Observer1.reset_clock(current_time);
					}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.callState == CALLED && (! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") )))))
					{
						if((! ts_TCS_Observer.diagnostic_to_control.expired(1E11, current_time)  && ((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic") ) || (ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") ))))
						{
								if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S2 && ! ts_TCS_Observer.withChange || (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "status_update") ))
								{
									ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.my_event=ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(','));ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState = S0;
									exec = 1;
								
								}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S0 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "diagnostic") ))
								{
									ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.my_event=ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(','));ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState = S1;
									exec = 1;
								
								}else if((ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState == S1 && (ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(',')) == "reconfig") ))
								{
									
									ts_TCS_Observer.withChange=ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.status;
									;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation=false;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.my_event=ts_TCS_Observer.events.substr(0, ts_TCS_Observer.events.find(','));ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_DiagnosticGuard.ts_DiagnosticExecution.autState = S2;
									exec = 1;
								
								}
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.left_clock_DiagnosticGuard.reset_clock(current_time);
						}
						if(0)
						{
								
								if(ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation){cout<<"Violation dans l'execution du mode Diagnostic\n";}
								if(ts_TCS_Observer.no_action){
								ts_TCS_Observer.accept=false;
								}else{
								ts_TCS_Observer.no_action=true;
								}
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.violation=true;
								ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.my_event="";
								;ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.right_clock_CheckViolation.reset_clock(current_time);ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.ts_ObserverDiagnostic.ts_CheckViolation.autState = S0;
								exec = 1;
						
						}
						ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.right_clock_Observer1.reset_clock(current_time);
					}
				
				}
				if(exec)
				{
					
					if(ts_TCS_Observer.events.find(',') !=string::npos) {     ts_TCS_Observer.events.erase(0,ts_TCS_Observer.events.find(',')+1);
					 }else {ts_TCS_Observer.observer_response="";
					}
					ts_TCS_Observer.no_action = true;
					;
				}
				ts_TCS_Observer.ts_Observers.left_clock_ObserverGuard.reset_clock(current_time);if(exec)
		{
			ts_TCS_Observer.right_clock_Observers.reset_clock(current_time);
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
	if((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.callState == NOTCALLED && (((((0 != 0) || (p0[ts_TCS_Observer.c] == '0'))  && ( (0 != 1) || (p0[ts_TCS_Observer.d] == '0') ) ) && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) ) && ((( (0 != 1) || (p0[ts_TCS_Observer.p] == '0') )  && ( (0 != 0) || (p0[ts_TCS_Observer.z] == '0') ) ) && (( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) )  && (((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0'))  && (( (0 != 0) || (p0[ts_TCS_Observer.r] == '0') )  && ( (0 != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))))) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.callState == CALLED && ((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))))))))) || ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CCSLTranslationCheckResponse.autState == S0))
	{
		if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.callState == NOTCALLED && (((((0 != 0) || (p0[ts_TCS_Observer.c] == '0'))  && ( (0 != 1) || (p0[ts_TCS_Observer.d] == '0') ) ) && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) ) && ((( (0 != 1) || (p0[ts_TCS_Observer.p] == '0') )  && ( (0 != 0) || (p0[ts_TCS_Observer.z] == '0') ) ) && (( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) )  && (((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0'))  && (( (0 != 0) || (p0[ts_TCS_Observer.r] == '0') )  && ( (0 != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))))) || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.callState == CALLED && ((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))))))))))
		{
			if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.callState == NOTCALLED && (((((0 != 0) || (p0[ts_TCS_Observer.c] == '0'))  && ( (0 != 1) || (p0[ts_TCS_Observer.d] == '0') ) ) && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) ) && ((( (0 != 1) || (p0[ts_TCS_Observer.p] == '0') )  && ( (0 != 0) || (p0[ts_TCS_Observer.z] == '0') ) ) && (( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) )  && (((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0'))  && (( (0 != 0) || (p0[ts_TCS_Observer.r] == '0') )  && ( (0 != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))))))
			{
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.callState = CALLED;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.nb_r = 0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.nb_i = 0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.diagnostic_to_control.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.right_clock_Control_CCSL.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.left_clock_Diagnostic_CCSL.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.left_clock_D_alternateWith_C.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.right_clock_S_subclock_C.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.right_clock_C_precede_D.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.left_clock_D_precede_C.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter = 0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter = 0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.right_clock_T1.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.right_clock_T2.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.left_clock_P_alternateWith_Z.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.right_clock_P_precede_Z.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.left_clock_Z_precede_P.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter = 0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter = 0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.right_clock_T3.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.left_clock_iUr.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.right_clock_T4.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.left_clock_exclusion.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.right_clock_RprecedeI.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.left_clock_IbeforeR.reset_clock(ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver);
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState = S0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter = 0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState = S0;
				ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter = 0;
				if(((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))))))))
				{
					if((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) )))
					{
						if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) )))
						{
							if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ))
							{
								clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter,ts_TCS_Observer.c,ts_TCS_Observer.d,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.left_clock_D_precede_C.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
								exec = 1;
							
							}
							if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) ))
							{
								clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter,ts_TCS_Observer.d,ts_TCS_Observer.c,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.right_clock_C_precede_D.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
								exec = 1;
							
							}
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.left_clock_D_alternateWith_C.reset_clock(current_time);
						}
						if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) ))
						{
							ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.right_clock_S_subclock_C.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
							exec = 1;
						
						}
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.left_clock_Diagnostic_CCSL.reset_clock(current_time);
					}
					if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))))))
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
							exec = 1;
						
						}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
						{
							ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
							exec = 1;
						
						}
						if((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))))))
						{
							if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )))
							{
								if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ))
								{
									clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter,ts_TCS_Observer.p,ts_TCS_Observer.z,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.left_clock_Z_precede_P.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
									exec = 1;
								
								}
								if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) ))
								{
									clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter,ts_TCS_Observer.z,ts_TCS_Observer.p,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.right_clock_P_precede_Z.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
									exec = 1;
								
								}
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.left_clock_P_alternateWith_Z.reset_clock(current_time);
							}
							if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))))
							{
								if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ))
								{
									ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.left_clock_iUr.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
									exec = 1;
								
								}
								if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))))
								{
									if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ))
									{
										ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.left_clock_exclusion.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
										exec = 1;
									
									}
									if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))
									{
										if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ))
										{
											clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter,ts_TCS_Observer.r,ts_TCS_Observer.i,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.left_clock_IbeforeR.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState = S0;
											exec = 1;
										
										}
										if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))
										{
											clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter,ts_TCS_Observer.i,ts_TCS_Observer.r,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.right_clock_RprecedeI.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState = S0;
											exec = 1;
										
										}
										ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.right_clock_T4.reset_clock(current_time);
									}
									ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.right_clock_T3.reset_clock(current_time);
								}
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.right_clock_T2.reset_clock(current_time);
							}
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.right_clock_T1.reset_clock(current_time);
						}
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.right_clock_Control_CCSL.reset_clock(current_time);
					}
					
					ts_TCS_Observer.observer_response="true";
					cout<<"Action exécutée par le programme\n";
					;
				}
				ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver.reset_clock(current_time);
			}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.callState == CALLED && ((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))))))))
			{
				if(((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))))))))
				{
					if((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) )) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) )))
					{
						if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) )))
						{
							if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState == S0 && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter != 0) || (p0[ts_TCS_Observer.c] == '0')) ))
							{
								clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.counter,ts_TCS_Observer.c,ts_TCS_Observer.d,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.left_clock_D_precede_C.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_D_precede_C.autState = S0;
								exec = 1;
							
							}
							if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter != 1) || (p0[ts_TCS_Observer.d] == '0') ) ))
							{
								clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.counter,ts_TCS_Observer.d,ts_TCS_Observer.c,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.right_clock_C_precede_D.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_D_alternateWith_C.ts_C_precede_D.autState = S0;
								exec = 1;
							
							}
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.left_clock_D_alternateWith_C.reset_clock(current_time);
						}
						if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState == S0 && ((p0[ts_TCS_Observer.s] == '0') || (p0[ts_TCS_Observer.c] == '1')) ))
						{
							ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.right_clock_S_subclock_C.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Diagnostic_CCSL.ts_S_subclock_C.autState = S0;
							exec = 1;
						
						}
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.left_clock_Diagnostic_CCSL.reset_clock(current_time);
					}
					if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 || (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) )) && (((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))))))
					{
						if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0)
						{
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.reset_clock(current_time);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
							exec = 1;
						
						}else if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState == S0 && ((p0[ts_TCS_Observer.p] == '1') && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.periodic_sense_timer.expired(1E10, current_time))) ))
						{
							ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.left_clock_P_discretizedBy_10.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_P_discretizedBy_10.autState = S0;
							exec = 1;
						
						}
						if((((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))))))
						{
							if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) )))
							{
								if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter != 1) || (p0[ts_TCS_Observer.p] == '0') ) ))
								{
									clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.counter,ts_TCS_Observer.p,ts_TCS_Observer.z,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.left_clock_Z_precede_P.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_Z_precede_P.autState = S0;
									exec = 1;
								
								}
								if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter != 0) || (p0[ts_TCS_Observer.z] == '0') ) ))
								{
									clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.counter,ts_TCS_Observer.z,ts_TCS_Observer.p,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.right_clock_P_precede_Z.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_P_alternateWith_Z.ts_P_precede_Z.autState = S0;
									exec = 1;
								
								}
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.left_clock_P_alternateWith_Z.reset_clock(current_time);
							}
							if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))))
							{
								if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState == S1 && ( (p0[ts_TCS_Observer.z]-'0') == ((p0[ts_TCS_Observer.r]-'0')+(p0[ts_TCS_Observer.i]-'0')) ) ))
								{
									ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.left_clock_iUr.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_iUr.autState = S1;
									exec = 1;
								
								}
								if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ) && ((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))))
								{
									if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState == S0 && ((p0[ts_TCS_Observer.i] == '0') || (p0[ts_TCS_Observer.r] == '0')) ))
									{
										ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.left_clock_exclusion.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_exclusion.autState = S0;
										exec = 1;
									
									}
									if(((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ) && (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) )))
									{
										if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter != 0) || (p0[ts_TCS_Observer.r] == '0') ) ))
										{
											clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.counter,ts_TCS_Observer.r,ts_TCS_Observer.i,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.left_clock_IbeforeR.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_IbeforeR.autState = S0;
											exec = 1;
										
										}
										if((ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState == S0 && ( (ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter != 2) || (p0[ts_TCS_Observer.i] == '0') ) ))
										{
											clockCounterDiff(ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.counter,ts_TCS_Observer.i,ts_TCS_Observer.r,p0);ts_TCS_Observer.inputs=p0;ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.right_clock_RprecedeI.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.ts_T4.ts_RprecedeI.autState = S0;
											exec = 1;
										
										}
										ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.ts_T3.right_clock_T4.reset_clock(current_time);
									}
									ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.ts_T2.right_clock_T3.reset_clock(current_time);
								}
								ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.ts_T1.right_clock_T2.reset_clock(current_time);
							}
							ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.ts_Control_CCSL.right_clock_T1.reset_clock(current_time);
						}
						ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.ts_TCS_Observed_module.right_clock_Control_CCSL.reset_clock(current_time);
					}
					
					ts_TCS_Observer.observer_response="true";
					cout<<"Action exécutée par le programme\n";
					;
				}
				ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver.reset_clock(current_time);
			}
		
		}
		if(ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CCSLTranslationCheckResponse.autState == S0)
		{
					if(ts_TCS_Observer.observer_response==""){ts_TCS_Observer.observer_response="false";
					cout << "Action non exécutée par le programme\n" ;
					ts_TCS_Observer.inputs=p0;
					}
					;ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.left_clock_CCSLTranslationCheckResponse.reset_clock(current_time);ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CCSLTranslationCheckResponse.autState = S0;
					exec = 1;
			if(exec)
			{
				ts_TCS_Observer.ts_ASTDSpecGuard.right_clock_Program.reset_clock(current_time);
			}
		
		}
		if(exec)
		{
			ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
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
	if(ts_TCS_Observer.ts_Observers.ts_Observer3.autState == S0)
	{
				ts_TCS_Observer.temperature=p0;ts_TCS_Observer.ts_Observers.right_clock_Observer3.reset_clock(current_time);ts_TCS_Observer.ts_Observers.ts_Observer3.autState = S0;
				exec = 1;
		if(exec)
		{
			ts_TCS_Observer.right_clock_Observers.reset_clock(current_time);
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
	ts_TCS_Observer.i = i;
	ts_TCS_Observer.temperature = ts_TCS_Observer.min_temp;
	ts_TCS_Observer.z = z;
	ts_TCS_Observer.no_action = true;
	ts_TCS_Observer.max_temp = max_temp;
	ts_TCS_Observer.diagnostic_to_control.reset_clock(current_time);
	ts_TCS_Observer.p = p;
	ts_TCS_Observer.observer_response = "";
	ts_TCS_Observer.r = r;
	ts_TCS_Observer.events = "";
	ts_TCS_Observer.c = c;
	ts_TCS_Observer.s = s;
	ts_TCS_Observer.accept = false;
	ts_TCS_Observer.d = d;
	ts_TCS_Observer.withChange = false;
	ts_TCS_Observer.min_temp = min_temp;
	ts_TCS_Observer.nb_remove = 0;
	ts_TCS_Observer.inputs = "";
	ts_TCS_Observer.nb_insert = 0;
	ts_TCS_Observer.left_clock_ASTDSpecGuard.reset_clock(current_time);
	ts_TCS_Observer.right_clock_Observers.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.left_clock_CallObserver.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.right_clock_Program.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_CallObserver.callState = NOTCALLED;
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.right_clock_CallTransformerGuard.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.left_clock_CCSLTranslationCheckResponse.reset_clock(current_time);
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CCSLTranslationCheckResponse.autState = S0;
	ts_TCS_Observer.ts_ASTDSpecGuard.ts_Program.ts_CallTransformerGuard.ts_CallTransformTransition.callState = NOTCALLED;
	ts_TCS_Observer.ts_Observers.left_clock_ObserverGuard.reset_clock(current_time);
	ts_TCS_Observer.ts_Observers.right_clock_Observer3.reset_clock(current_time);
	ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.left_clock_Observer2.reset_clock(current_time);
	ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.right_clock_Observer1.reset_clock(current_time);
	ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer2.callState = NOTCALLED;
	ts_TCS_Observer.ts_Observers.ts_ObserverGuard.ts_ObserverGroup.ts_Observer1.callState = NOTCALLED;
	ts_TCS_Observer.ts_Observers.ts_Observer3.autState = S0;
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
