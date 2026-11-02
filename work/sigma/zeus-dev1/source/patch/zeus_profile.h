/* Explicit development profile. Usages are Zeus HID usages, not physical names.
 * Factory firmware assigns its two main shift groups to usages 13 and 14.
 * Console destinations are the 14 HID button usages in Sigma's own descriptor.
 * User profiles can change Zeus usages; live correlation is required.
 */
#ifndef ZEUS_PROFILE_H
#define ZEUS_PROFILE_H
#define ZEUS_TIMEOUT_TICKS 250u
#define ZEUS_MAP_AXES 1
static const unsigned char zeus_button_usages[14] = {
    1, 2, 3, 4, 13, 14, 5, 6, 7, 8, 9, 10, 11, 12
};
/* Zero disables a hat direction until physical/firmware assignment is verified. */
static const unsigned char zeus_hat_usages[4] = { 0, 0, 0, 0 }; /* up,right,down,left */
#endif
