// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//Get Patrol Points
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();

	UPatrollingComponent* PatrolComp_Ref = ControlledPawn->FindComponentByClass<UPatrollingComponent>();
	if (!ensure(PatrolComp_Ref)) { return EBTNodeResult::Failed; }

	TArray<AActor*> PatrolPoints = PatrolComp_Ref->GetPatrolRoutes();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s doesn't have Patrol Points ASSIGNED."), *ControlledPawn->GetName());
		return EBTNodeResult::Failed;
	}
	//Set Next Waypoint
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index_Ref = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index_Ref]); //TODO Protect possible out of range search

	//Cycle the Index
	Index_Ref++;
	Index_Ref %= PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index_Ref);
	
	return EBTNodeResult::Succeeded;
}
