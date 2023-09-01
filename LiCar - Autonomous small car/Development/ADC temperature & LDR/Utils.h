/*
 * Utils.h
 *
 * Created: 9/23/2020 7:25:55 PM
 *  Author: amr
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(reg,bit)   ((reg) |= (1<<bit))
#define CLEAR_BIT(reg,bit)   (reg&= ~(1<<bit))
#define TOGGLE_BIT(reg,bit)   (reg ^= (1<<bit))
#define READ_BIT(reg,bit)   ((reg >> bit)&1)
#define WRITE_BIT(reg,bit,val) ((reg &= (~(1<<bit))) | (val << bit))



#endif /* UTILS_H_ */
