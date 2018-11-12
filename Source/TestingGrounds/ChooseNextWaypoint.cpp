// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("WORKING!"));
	return EBTNodeResult::Succeeded;
}

void UChooseNextWaypoint::GetPatrolPoints()
{
}

int UChooseNextWaypoint::SetNextWaypoint()
{
	return 0;
}

void UChooseNextWaypoint::CycleNextIndex(int Index)
{
}
