// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "ShipController.generated.h"

UCLASS()
class SHOOTER_API AShipController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShipController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere)
		UShapeComponent* CollisionBox;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class ABulletController> BulletBlueprint;

	UPROPERTY(EditAnywhere)
		float speed = 10.0f;

	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	void OnShoot();
	void OnRestart();

	FVector CurrentVelocity;

	bool Died;
	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);

	
	
};
