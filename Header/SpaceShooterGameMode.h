// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "SpaceShooterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API ASpaceShooterGameMode : public AGameMode
{
	GENERATED_BODY()
		float Minimum_Interval = 0.5f;
		float Maximum_Interval = 2.0f;
		float Time_To_Interval = 30.0f;

public:


		virtual void BeginPlay() override;
		virtual void Tick(float DeltaSeconds) override;

		UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AEnemyController> EnemyBlueprint;

		UFUNCTION(BlueprintCallable, Category = "UMG Name")
			void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
		
	float EnemyTimer;
	float GameTimer;
	void IncrementScore();
	void OnGameOver();

protected:
	int Score=0;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "UMG Name")
		TSubclassOf<UUserWidget> StartingWidgetClass;
	UPROPERTY()
		UUserWidget* CurrentWidget;
	
	
};
