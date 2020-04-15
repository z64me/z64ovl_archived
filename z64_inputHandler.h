#ifndef Z64INPUT_H
#define Z64INPUT_H

#define STATE_UP 0
#define STATE_PRESSED 1
#define STATE_DOWN 2

typedef struct {
	uint8_t buttonState;
	float invokeTime; // It is best to not overwrite this, just store a separate time for last [good] invoke time. Ask Drahsid for logic help if needed
	float timeDown; // This does not work for cyclic holding, for that use the suggestion proposed above. Use this if you just need to detect button holding
} button_t;

typedef struct {
	button_t a;
	button_t b;
	button_t z;
	button_t s;
	button_t du;
	button_t dd;
	button_t dl;
	button_t dr;
#ifdef DEBUG
	button_t pad[2];
#endif
	button_t l;
	button_t r;
	button_t cu;
	button_t cd;
	button_t cl;
	button_t cr;
	float jx, jy;
	z64_controller_t* controller;
#ifdef DEBUG
	uint64_t end;
#endif
} z64_inputHandler_t;

void construct_button_t(button_t* button) {
	button->buttonState = STATE_UP;
	button->invokeTime = 0;
	button->timeDown = 0;
}

void construct_z64_inputHandler_t(z64_inputHandler_t* inputHandler, z64_controller_t* controller) {
	construct_button_t(&inputHandler->a);
	construct_button_t(&inputHandler->b);
	construct_button_t(&inputHandler->z);
	construct_button_t(&inputHandler->s);
	construct_button_t(&inputHandler->du);
	construct_button_t(&inputHandler->dd);
	construct_button_t(&inputHandler->dl);
	construct_button_t(&inputHandler->dr);
	construct_button_t(&inputHandler->l);
	construct_button_t(&inputHandler->r);
	construct_button_t(&inputHandler->cu);
	construct_button_t(&inputHandler->cd);
	construct_button_t(&inputHandler->cl);
	construct_button_t(&inputHandler->cr);
	inputHandler->jx = 0;
	inputHandler->jy = 0;
	inputHandler->controller = controller;
#ifdef DEBUG
	inputHandler->end = 0xDEADBEEFBEEFDEAD;
#endif
}

void updateButton(button_t* thisButton, uint8_t buttonDown, float currentTime) {
	switch (thisButton->buttonState) 
	{
		case(STATE_UP):
			if (buttonDown) {
				thisButton->buttonState = STATE_PRESSED;
				thisButton->invokeTime = currentTime;
			}
			break;

		case(STATE_PRESSED):
			if (buttonDown) thisButton->buttonState = STATE_DOWN;
			else {
				thisButton->buttonState = STATE_UP;
				thisButton->invokeTime = 0;
			}
			break;

		case(STATE_DOWN):
			if (buttonDown) {
				thisButton->timeDown = currentTime - thisButton->invokeTime;
			}
			else {
				thisButton->buttonState = STATE_UP;
				thisButton->invokeTime = 0;
			}
			break;
	}
}

void update_z64_inputHandler_t(z64_inputHandler_t* inputHandler, float currentTime) {
	uint8_t buttonDown = inputHandler->controller->a;
	updateButton(&inputHandler->a, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->b;
	updateButton(&inputHandler->b, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->z;
	updateButton(&inputHandler->z, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->s;
	updateButton(&inputHandler->b, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->b;
	updateButton(&inputHandler->s, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->du;
	updateButton(&inputHandler->du, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->dd;
	updateButton(&inputHandler->dd, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->dl;
	updateButton(&inputHandler->dl, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->dr;
	updateButton(&inputHandler->dr, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->l;
	updateButton(&inputHandler->l, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->r;
	updateButton(&inputHandler->r, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->cu;
	updateButton(&inputHandler->cu, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->cd;
	updateButton(&inputHandler->cd, buttonDown, currentTime);
	
	buttonDown = inputHandler->controller->cl;
	updateButton(&inputHandler->cl, buttonDown, currentTime);

	buttonDown = inputHandler->controller->cr;
	updateButton(&inputHandler->cr, buttonDown, currentTime);

	inputHandler->jx = (float)inputHandler->controller->x * 0.0078125f;
	inputHandler->jy = (float)inputHandler->controller->y * 0.0078125f;
}

#endif


