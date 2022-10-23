

#ifndef MACROS_H_
#define MACROS_H_

#define SET_PIN(REG, PIN_NUM) 		REG |=  (1 << PIN_NUM)
#define CLR_PIN(REG, PIN_NUM) 		REG &=~ (1 << PIN_NUM)
#define TOGGLE_PIN(REG, PIN_NUM) 	REG ^=  (1 << PIN_NUM)
#define GET_PIN(REG, PIN_NUM) 		((REG >> PIN_NUM) & 1)

#endif /* MACROS_H_ */
