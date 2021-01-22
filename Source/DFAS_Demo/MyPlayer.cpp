#include "MyPlayer.h"

//Establecer valores por defecto.
AMyPlayer::AMyPlayer(){

	// Activar la llamada a funci�n Tick() en cada frame.
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
	/*Se le a�ade el c�digo para que busque
	 los enlaces a los ejes del input.*/
	check(PlayerInputComponent); // Comprobar contenido configurado en el editor de UE.
	// M�todo BindAxis para acceder a los valores de Forward/Right.
	// This para indicar que la funci�n se ejecuta desde el objeto que la llame.
	// 3er par�metro - pasar la llamada a las funciones de la clase AMyPlayer definidas en header
	PlayerInputComponent->BindAxis("Forward", this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AMyPlayer::MoveRight);
}

void AMyPlayer::MoveForward(float amount) {
	/* No entrar� en el cuerpo de est� funci�n
	si Controller no est� configurado 
	O si la cantidad a mover es igual a 0. */
	if (Controller && amount) { // Detecta que el Input est� accionado y que haya movimiento.

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



