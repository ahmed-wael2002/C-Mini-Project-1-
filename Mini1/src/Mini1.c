/*
 ============================================================================
 Name        : Mini1.c
 Author      : Ahmed Wael
 Version     :
 Copyright   : Your copyright notice
 Description : Mini-Project (1)
 ============================================================================
 */

#include <stdio.h>

enum state{ON=1, OFF=0}; // Enumeration to signify on/off action of

struct vehicle {
	enum state engine;
	enum state ac;
	enum state engine_temp_controller;
	char speed;
	char room_temp;
	char engine_temp;
};

// Function Prototypes
void get_vehicle_status(struct vehicle* v);
void show_sensors_set (struct vehicle* v);
void show_main_menu(struct vehicle *v);
void set_traffic_light(struct vehicle *v, char op);


void main(void){
	struct vehicle v = {OFF, OFF, OFF, 15, 15, 100};
	show_main_menu(&v);

	char main_menu_op = 1;
	while (1){

		printf("a. Turn on the engine\n");
		printf("b. Turn off the engine\n");
		printf("c. Quit the system\n");
		fflush(stdout);
		scanf(" %c", &main_menu_op);

		switch (main_menu_op){
		case'a':
		case'A':
			// Turn on the engine
			printf("\n*** Turning on the engine!\n");
			v->engine = ON;
			show_sensors_set(&v);

		case'b':
		case'B':
			// Turn off the engine
			printf("\n*** Turning off the engine!\n");
			show_main_menu(&v);

		case'c':
		case'C':
			printf("\n**Quitting the system\n");
			return;

		default:
			printf("\nInvalid Operator!\n");
			show_main_menu(&v);
		}
	}
}


/*** Funtion to print the status of the vehicle ***/
void get_vehicle_status(struct vehicle* v){
	// Engine
	v->engine==1? printf("Engine is ON\n")
				: printf("Engine is OFF\n");

	// AC
	v->ac==1? printf("AC is ON\n")
			: printf("AC IS OFF\n");

	// Vehicle speed
	printf("Vehicle Speed:\t%d Km/hr\n", v->speed);

	// Room Temperature
	printf("Room Temperature:\t%d C\n", v->room_temp);

	// Engine Temperature Controller
	v->engine_temp_controller==1? printf("Engine Temperature Controller is ON\n")
								: printf("Engine Temperature Controller is OFF\n");

	// Engine Temperature
	printf("Engine Temperature:\t%d C\n\n", v->engine_temp);

	fflush(stdout);
}

/*** Function to trigger main menu ***/

/*** (Function) Vehicle Sensors set operation ***/
void show_main_menu(struct vehicle *v){
	char main_menu_op;
			printf("a. Turn on the engine\n");
			printf("b. Turn off the engine\n");
			printf("c. Quit the system\n");
			fflush(stdout);
			scanf(" %c", &main_menu_op);

			switch (main_menu_op){
			case'a':
			case'A':
				// Turn on the engine
				printf("\n*** Turning on the engine!\n");
				v->engine = ON;
				show_sensors_set(&v);
				break;
			case'b':
			case'B':
				// Turn off the engine
				printf("\n*** Turning off the engine!\n");
				show_main_menu(&v);
				break;

			case'c':
			case'C':
				printf("\n**Quitting the system\n");
				return;
			default:
				printf("\nInvalid Operator!\n");
				show_main_menu(&v);
			}
}

void show_sensors_set (struct vehicle *v){
	if (v->engine==0)
		return;


	char op;
	printf("\na. Turn off the engine\n");
	printf("b. Set the traffic light color\n");
	printf("c. Set the room temperature\n");
	printf("d. Set the engine temperature\n");
	fflush(stdout);
	scanf(" %c", &op);

	switch(op){
	case'a':
	case'A':
		show_main_menu(&v);
		break;

	case'b':
	case'B':
		printf("Enter the required color: ");
		fflush(stdout);
		scanf(" %c", &op);
		set_traffic_light(&v, &op);
		break;


	case'c':
	case'C':
		set_room_temperature(&v);
		break;

	case'd':
	case'D':
		set_engine_temperature(&v);
		break;

	default:
		printf("\nInvalid Operator!\n");
	}

	show_sensors_set(&v);
}

void set_traffic_light(struct vehicle *v, char op){
	switch(op){
	case'g':
	case'G':
		v->speed = 100;
		break;

	case'o':
	case'O':
		v->speed = 30;
		break;

	case'r':
	case'R':
		v->speed = 0;
		break;

	default:
		printf("\nInvalid Operation!\n");
	}
	get_vehicle_status(&v);

}

void set_room_temperature (struct vehicle *v){
	char temp;
	printf("Enter room temperature: ");
	fflush(stdout);
	scanf("%d", &temp);

	if (temp<10 || temp>30){
		v->ac = ON;
		v->room_temp = 20;
	}
	else
		v->ac = OFF;
	get_vehicle_status(&v);
}

void set_engine_temperature (struct vehicle *v){
	if (v->speed == 30){
		if (v->ac == OFF){
			v->ac = ON;
			v->room_temp = v->room_temp * (5/4) + 1;
		}

		if (v->engine_temp_controller == OFF){
			v->engine_temp_controller = ON;
			v->engine_temp = v->engine_temp * (5/4) + 1;
		}
	}
}











