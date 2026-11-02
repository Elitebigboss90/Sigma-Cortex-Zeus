/* Development profile: live captures003/005/007/008 establish paddle and
 * seven-way usages for the user's current saved wheel profile.
 * Other numbered buttons retain a documented provisional mapping.
 */
#ifndef ZEUS_PROFILE_H
#define ZEUS_PROFILE_H
#define ZEUS_TIMEOUT_TICKS 250u
#define ZEUS_MAP_AXES 1
static const unsigned char zeus_button_usages[14] = {
    1, 2, 3, 4, 14, 13, 5, 6, 7, 8, 9, 10, 11, 12
};
static const unsigned char zeus_hat_usages[4] = { 44, 47, 46, 45 }; /* up,right,down,left */
static const unsigned char zeus_hat_secondary[4] = { 63, 66, 65, 64 };
/* Additional sources for console button usages11/12 (left/right stick click). */
static const unsigned char zeus_center_usages[2] = { 43, 48 };
#endif
