#include "MyPlayer.h"

//Establecer valores por defecto.
AMyPlayer::AMyPlayer(){

	// Activar la llamada a función Tick() en cada frame.
	PrimaryActorTick.bCanEverTick = true;

}

// Llamada al comienzo del juego o en cada spawneo.
void AMyPlayer::BeginPlay(){

	Super::BeginPlay();
	
}

// LLamada cada frame.
void AMyPlayer::Tick(float DeltaTime){

	Super::Tick(DeltaTime);

}

// Llamada para enlazar funciones al input.
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {

	// De lo que hereda de la clase padre
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	/*Se le añade el código para que busque
	 los enlaces a los ejes del input.*/
	check(PlayerInputComponent); // Comprobar contenido configurado en el editor de UE.
	// Método BindAxis para acceder a los valores de Forward/Right.
	// This para indicar que la función se ejecuta desde el objeto que la llame.
	// 3er parámetro - pasar la llamada a las funciones de la clase AMyPlayer definidas en header
	PlayerInputComponent->BindAxis("Forward", this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AMyPlayer::MoveRight);
}

void AMyPlayer::MoveForward(float amount) {
	/* No entrará en el cuerpo de está función
	si Controller no está configurado 
	O si la cantidad a mover es igual a 0. */
	if (Controller && amount) { // Detecta que el Input esté accionado y que haya movimiento.

		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
	}
}
void AMyPlayer::MoveRight(float amount) {

	if (Controller && amount) { 

		FVector rgt = GetActorRightVector();
		AddMovementInput(rgt, amount);
	}
}



