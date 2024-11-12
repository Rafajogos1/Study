#include <stdio.h>

/* By using a single variable and using its bits as flags, we can make code be much more efficient. */
/* By having one variable, we can use its bits as flags instead. */
/* Since flags usually only take "ON" and "OFF" values, bits are perfect for this since they are in binary. */

#define ACTIVE (1 << 0) 	/* 00000001 */
#define SUBSCRIBED (1 << 1) /* 00000010 */
#define VERIFIED (1 << 2) 	/* 00000100 */
#define ADMIN (1 << 3) 		/* 00001000 */

/* This function compares the value of variable against the value of the flag and prints the active flags.*/
/* @param user The flag variable. */
void	print_flags(char user)
{
	if (user & ACTIVE)
		printf("ACTIVE\n");
	if (user & SUBSCRIBED)
		printf("SUBSCRIBED\n");
	if (user & VERIFIED)
		printf("VERIFIED\n");
	if (user & ADMIN)
		printf("ADMIN\n");
	printf("\n");
}

/* In this context, here's how the bitwise operators affect flags. */
/* Since they affect each bit, the result of the flags depends on the bit that we're considering for that specific flag, and the corresponding bit on the flag variable. */
/* By using '&', if both bits are 1, then we have "1 & 1", which is 1. This way we can check if a flag is turned on by using this operator. */
/* By using '|', only one bit needs to be 1, which is always true, so it turns on the flag. */
/* By using '^', which only returns 1 if the bits are different, we can toggle the flag. If they are, it turns on the flag, if not, it turns it off. */
/* By using '~' along with "&=", we can turn the flag off, because we'll be comparing against the flag's opposite.*/

int	main()
{
	char	user = 0; /* char is only 1 byte, while int is 4.*/

	print_flags(user);
	user |= ACTIVE; /* Here we turn on ACTIVE. */
	print_flags(user);
	user |= SUBSCRIBED; /* Here we turn on SUBSCRIBED. */
	print_flags(user);
	user |= VERIFIED; /* Here we turn on VERIFIED. */
	print_flags(user);
	if (user & ADMIN) /* Here we check if ADMIN is turned on and turn it off, if it is. */
		user &= ~ADMIN;
	print_flags(user);
	user ^= SUBSCRIBED; /* Here we toggle the SUBSCRIBED flag. */
	print_flags(user);
	if (user & VERIFIED) /* Here we print that the user is verified if the flag VERIFIED is turned on. */
		printf("User is verified.\n");
	print_flags(user);
}