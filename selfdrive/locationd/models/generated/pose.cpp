#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2367672105654731741) {
   out_2367672105654731741[0] = delta_x[0] + nom_x[0];
   out_2367672105654731741[1] = delta_x[1] + nom_x[1];
   out_2367672105654731741[2] = delta_x[2] + nom_x[2];
   out_2367672105654731741[3] = delta_x[3] + nom_x[3];
   out_2367672105654731741[4] = delta_x[4] + nom_x[4];
   out_2367672105654731741[5] = delta_x[5] + nom_x[5];
   out_2367672105654731741[6] = delta_x[6] + nom_x[6];
   out_2367672105654731741[7] = delta_x[7] + nom_x[7];
   out_2367672105654731741[8] = delta_x[8] + nom_x[8];
   out_2367672105654731741[9] = delta_x[9] + nom_x[9];
   out_2367672105654731741[10] = delta_x[10] + nom_x[10];
   out_2367672105654731741[11] = delta_x[11] + nom_x[11];
   out_2367672105654731741[12] = delta_x[12] + nom_x[12];
   out_2367672105654731741[13] = delta_x[13] + nom_x[13];
   out_2367672105654731741[14] = delta_x[14] + nom_x[14];
   out_2367672105654731741[15] = delta_x[15] + nom_x[15];
   out_2367672105654731741[16] = delta_x[16] + nom_x[16];
   out_2367672105654731741[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5219205296235492699) {
   out_5219205296235492699[0] = -nom_x[0] + true_x[0];
   out_5219205296235492699[1] = -nom_x[1] + true_x[1];
   out_5219205296235492699[2] = -nom_x[2] + true_x[2];
   out_5219205296235492699[3] = -nom_x[3] + true_x[3];
   out_5219205296235492699[4] = -nom_x[4] + true_x[4];
   out_5219205296235492699[5] = -nom_x[5] + true_x[5];
   out_5219205296235492699[6] = -nom_x[6] + true_x[6];
   out_5219205296235492699[7] = -nom_x[7] + true_x[7];
   out_5219205296235492699[8] = -nom_x[8] + true_x[8];
   out_5219205296235492699[9] = -nom_x[9] + true_x[9];
   out_5219205296235492699[10] = -nom_x[10] + true_x[10];
   out_5219205296235492699[11] = -nom_x[11] + true_x[11];
   out_5219205296235492699[12] = -nom_x[12] + true_x[12];
   out_5219205296235492699[13] = -nom_x[13] + true_x[13];
   out_5219205296235492699[14] = -nom_x[14] + true_x[14];
   out_5219205296235492699[15] = -nom_x[15] + true_x[15];
   out_5219205296235492699[16] = -nom_x[16] + true_x[16];
   out_5219205296235492699[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7701265832873588876) {
   out_7701265832873588876[0] = 1.0;
   out_7701265832873588876[1] = 0.0;
   out_7701265832873588876[2] = 0.0;
   out_7701265832873588876[3] = 0.0;
   out_7701265832873588876[4] = 0.0;
   out_7701265832873588876[5] = 0.0;
   out_7701265832873588876[6] = 0.0;
   out_7701265832873588876[7] = 0.0;
   out_7701265832873588876[8] = 0.0;
   out_7701265832873588876[9] = 0.0;
   out_7701265832873588876[10] = 0.0;
   out_7701265832873588876[11] = 0.0;
   out_7701265832873588876[12] = 0.0;
   out_7701265832873588876[13] = 0.0;
   out_7701265832873588876[14] = 0.0;
   out_7701265832873588876[15] = 0.0;
   out_7701265832873588876[16] = 0.0;
   out_7701265832873588876[17] = 0.0;
   out_7701265832873588876[18] = 0.0;
   out_7701265832873588876[19] = 1.0;
   out_7701265832873588876[20] = 0.0;
   out_7701265832873588876[21] = 0.0;
   out_7701265832873588876[22] = 0.0;
   out_7701265832873588876[23] = 0.0;
   out_7701265832873588876[24] = 0.0;
   out_7701265832873588876[25] = 0.0;
   out_7701265832873588876[26] = 0.0;
   out_7701265832873588876[27] = 0.0;
   out_7701265832873588876[28] = 0.0;
   out_7701265832873588876[29] = 0.0;
   out_7701265832873588876[30] = 0.0;
   out_7701265832873588876[31] = 0.0;
   out_7701265832873588876[32] = 0.0;
   out_7701265832873588876[33] = 0.0;
   out_7701265832873588876[34] = 0.0;
   out_7701265832873588876[35] = 0.0;
   out_7701265832873588876[36] = 0.0;
   out_7701265832873588876[37] = 0.0;
   out_7701265832873588876[38] = 1.0;
   out_7701265832873588876[39] = 0.0;
   out_7701265832873588876[40] = 0.0;
   out_7701265832873588876[41] = 0.0;
   out_7701265832873588876[42] = 0.0;
   out_7701265832873588876[43] = 0.0;
   out_7701265832873588876[44] = 0.0;
   out_7701265832873588876[45] = 0.0;
   out_7701265832873588876[46] = 0.0;
   out_7701265832873588876[47] = 0.0;
   out_7701265832873588876[48] = 0.0;
   out_7701265832873588876[49] = 0.0;
   out_7701265832873588876[50] = 0.0;
   out_7701265832873588876[51] = 0.0;
   out_7701265832873588876[52] = 0.0;
   out_7701265832873588876[53] = 0.0;
   out_7701265832873588876[54] = 0.0;
   out_7701265832873588876[55] = 0.0;
   out_7701265832873588876[56] = 0.0;
   out_7701265832873588876[57] = 1.0;
   out_7701265832873588876[58] = 0.0;
   out_7701265832873588876[59] = 0.0;
   out_7701265832873588876[60] = 0.0;
   out_7701265832873588876[61] = 0.0;
   out_7701265832873588876[62] = 0.0;
   out_7701265832873588876[63] = 0.0;
   out_7701265832873588876[64] = 0.0;
   out_7701265832873588876[65] = 0.0;
   out_7701265832873588876[66] = 0.0;
   out_7701265832873588876[67] = 0.0;
   out_7701265832873588876[68] = 0.0;
   out_7701265832873588876[69] = 0.0;
   out_7701265832873588876[70] = 0.0;
   out_7701265832873588876[71] = 0.0;
   out_7701265832873588876[72] = 0.0;
   out_7701265832873588876[73] = 0.0;
   out_7701265832873588876[74] = 0.0;
   out_7701265832873588876[75] = 0.0;
   out_7701265832873588876[76] = 1.0;
   out_7701265832873588876[77] = 0.0;
   out_7701265832873588876[78] = 0.0;
   out_7701265832873588876[79] = 0.0;
   out_7701265832873588876[80] = 0.0;
   out_7701265832873588876[81] = 0.0;
   out_7701265832873588876[82] = 0.0;
   out_7701265832873588876[83] = 0.0;
   out_7701265832873588876[84] = 0.0;
   out_7701265832873588876[85] = 0.0;
   out_7701265832873588876[86] = 0.0;
   out_7701265832873588876[87] = 0.0;
   out_7701265832873588876[88] = 0.0;
   out_7701265832873588876[89] = 0.0;
   out_7701265832873588876[90] = 0.0;
   out_7701265832873588876[91] = 0.0;
   out_7701265832873588876[92] = 0.0;
   out_7701265832873588876[93] = 0.0;
   out_7701265832873588876[94] = 0.0;
   out_7701265832873588876[95] = 1.0;
   out_7701265832873588876[96] = 0.0;
   out_7701265832873588876[97] = 0.0;
   out_7701265832873588876[98] = 0.0;
   out_7701265832873588876[99] = 0.0;
   out_7701265832873588876[100] = 0.0;
   out_7701265832873588876[101] = 0.0;
   out_7701265832873588876[102] = 0.0;
   out_7701265832873588876[103] = 0.0;
   out_7701265832873588876[104] = 0.0;
   out_7701265832873588876[105] = 0.0;
   out_7701265832873588876[106] = 0.0;
   out_7701265832873588876[107] = 0.0;
   out_7701265832873588876[108] = 0.0;
   out_7701265832873588876[109] = 0.0;
   out_7701265832873588876[110] = 0.0;
   out_7701265832873588876[111] = 0.0;
   out_7701265832873588876[112] = 0.0;
   out_7701265832873588876[113] = 0.0;
   out_7701265832873588876[114] = 1.0;
   out_7701265832873588876[115] = 0.0;
   out_7701265832873588876[116] = 0.0;
   out_7701265832873588876[117] = 0.0;
   out_7701265832873588876[118] = 0.0;
   out_7701265832873588876[119] = 0.0;
   out_7701265832873588876[120] = 0.0;
   out_7701265832873588876[121] = 0.0;
   out_7701265832873588876[122] = 0.0;
   out_7701265832873588876[123] = 0.0;
   out_7701265832873588876[124] = 0.0;
   out_7701265832873588876[125] = 0.0;
   out_7701265832873588876[126] = 0.0;
   out_7701265832873588876[127] = 0.0;
   out_7701265832873588876[128] = 0.0;
   out_7701265832873588876[129] = 0.0;
   out_7701265832873588876[130] = 0.0;
   out_7701265832873588876[131] = 0.0;
   out_7701265832873588876[132] = 0.0;
   out_7701265832873588876[133] = 1.0;
   out_7701265832873588876[134] = 0.0;
   out_7701265832873588876[135] = 0.0;
   out_7701265832873588876[136] = 0.0;
   out_7701265832873588876[137] = 0.0;
   out_7701265832873588876[138] = 0.0;
   out_7701265832873588876[139] = 0.0;
   out_7701265832873588876[140] = 0.0;
   out_7701265832873588876[141] = 0.0;
   out_7701265832873588876[142] = 0.0;
   out_7701265832873588876[143] = 0.0;
   out_7701265832873588876[144] = 0.0;
   out_7701265832873588876[145] = 0.0;
   out_7701265832873588876[146] = 0.0;
   out_7701265832873588876[147] = 0.0;
   out_7701265832873588876[148] = 0.0;
   out_7701265832873588876[149] = 0.0;
   out_7701265832873588876[150] = 0.0;
   out_7701265832873588876[151] = 0.0;
   out_7701265832873588876[152] = 1.0;
   out_7701265832873588876[153] = 0.0;
   out_7701265832873588876[154] = 0.0;
   out_7701265832873588876[155] = 0.0;
   out_7701265832873588876[156] = 0.0;
   out_7701265832873588876[157] = 0.0;
   out_7701265832873588876[158] = 0.0;
   out_7701265832873588876[159] = 0.0;
   out_7701265832873588876[160] = 0.0;
   out_7701265832873588876[161] = 0.0;
   out_7701265832873588876[162] = 0.0;
   out_7701265832873588876[163] = 0.0;
   out_7701265832873588876[164] = 0.0;
   out_7701265832873588876[165] = 0.0;
   out_7701265832873588876[166] = 0.0;
   out_7701265832873588876[167] = 0.0;
   out_7701265832873588876[168] = 0.0;
   out_7701265832873588876[169] = 0.0;
   out_7701265832873588876[170] = 0.0;
   out_7701265832873588876[171] = 1.0;
   out_7701265832873588876[172] = 0.0;
   out_7701265832873588876[173] = 0.0;
   out_7701265832873588876[174] = 0.0;
   out_7701265832873588876[175] = 0.0;
   out_7701265832873588876[176] = 0.0;
   out_7701265832873588876[177] = 0.0;
   out_7701265832873588876[178] = 0.0;
   out_7701265832873588876[179] = 0.0;
   out_7701265832873588876[180] = 0.0;
   out_7701265832873588876[181] = 0.0;
   out_7701265832873588876[182] = 0.0;
   out_7701265832873588876[183] = 0.0;
   out_7701265832873588876[184] = 0.0;
   out_7701265832873588876[185] = 0.0;
   out_7701265832873588876[186] = 0.0;
   out_7701265832873588876[187] = 0.0;
   out_7701265832873588876[188] = 0.0;
   out_7701265832873588876[189] = 0.0;
   out_7701265832873588876[190] = 1.0;
   out_7701265832873588876[191] = 0.0;
   out_7701265832873588876[192] = 0.0;
   out_7701265832873588876[193] = 0.0;
   out_7701265832873588876[194] = 0.0;
   out_7701265832873588876[195] = 0.0;
   out_7701265832873588876[196] = 0.0;
   out_7701265832873588876[197] = 0.0;
   out_7701265832873588876[198] = 0.0;
   out_7701265832873588876[199] = 0.0;
   out_7701265832873588876[200] = 0.0;
   out_7701265832873588876[201] = 0.0;
   out_7701265832873588876[202] = 0.0;
   out_7701265832873588876[203] = 0.0;
   out_7701265832873588876[204] = 0.0;
   out_7701265832873588876[205] = 0.0;
   out_7701265832873588876[206] = 0.0;
   out_7701265832873588876[207] = 0.0;
   out_7701265832873588876[208] = 0.0;
   out_7701265832873588876[209] = 1.0;
   out_7701265832873588876[210] = 0.0;
   out_7701265832873588876[211] = 0.0;
   out_7701265832873588876[212] = 0.0;
   out_7701265832873588876[213] = 0.0;
   out_7701265832873588876[214] = 0.0;
   out_7701265832873588876[215] = 0.0;
   out_7701265832873588876[216] = 0.0;
   out_7701265832873588876[217] = 0.0;
   out_7701265832873588876[218] = 0.0;
   out_7701265832873588876[219] = 0.0;
   out_7701265832873588876[220] = 0.0;
   out_7701265832873588876[221] = 0.0;
   out_7701265832873588876[222] = 0.0;
   out_7701265832873588876[223] = 0.0;
   out_7701265832873588876[224] = 0.0;
   out_7701265832873588876[225] = 0.0;
   out_7701265832873588876[226] = 0.0;
   out_7701265832873588876[227] = 0.0;
   out_7701265832873588876[228] = 1.0;
   out_7701265832873588876[229] = 0.0;
   out_7701265832873588876[230] = 0.0;
   out_7701265832873588876[231] = 0.0;
   out_7701265832873588876[232] = 0.0;
   out_7701265832873588876[233] = 0.0;
   out_7701265832873588876[234] = 0.0;
   out_7701265832873588876[235] = 0.0;
   out_7701265832873588876[236] = 0.0;
   out_7701265832873588876[237] = 0.0;
   out_7701265832873588876[238] = 0.0;
   out_7701265832873588876[239] = 0.0;
   out_7701265832873588876[240] = 0.0;
   out_7701265832873588876[241] = 0.0;
   out_7701265832873588876[242] = 0.0;
   out_7701265832873588876[243] = 0.0;
   out_7701265832873588876[244] = 0.0;
   out_7701265832873588876[245] = 0.0;
   out_7701265832873588876[246] = 0.0;
   out_7701265832873588876[247] = 1.0;
   out_7701265832873588876[248] = 0.0;
   out_7701265832873588876[249] = 0.0;
   out_7701265832873588876[250] = 0.0;
   out_7701265832873588876[251] = 0.0;
   out_7701265832873588876[252] = 0.0;
   out_7701265832873588876[253] = 0.0;
   out_7701265832873588876[254] = 0.0;
   out_7701265832873588876[255] = 0.0;
   out_7701265832873588876[256] = 0.0;
   out_7701265832873588876[257] = 0.0;
   out_7701265832873588876[258] = 0.0;
   out_7701265832873588876[259] = 0.0;
   out_7701265832873588876[260] = 0.0;
   out_7701265832873588876[261] = 0.0;
   out_7701265832873588876[262] = 0.0;
   out_7701265832873588876[263] = 0.0;
   out_7701265832873588876[264] = 0.0;
   out_7701265832873588876[265] = 0.0;
   out_7701265832873588876[266] = 1.0;
   out_7701265832873588876[267] = 0.0;
   out_7701265832873588876[268] = 0.0;
   out_7701265832873588876[269] = 0.0;
   out_7701265832873588876[270] = 0.0;
   out_7701265832873588876[271] = 0.0;
   out_7701265832873588876[272] = 0.0;
   out_7701265832873588876[273] = 0.0;
   out_7701265832873588876[274] = 0.0;
   out_7701265832873588876[275] = 0.0;
   out_7701265832873588876[276] = 0.0;
   out_7701265832873588876[277] = 0.0;
   out_7701265832873588876[278] = 0.0;
   out_7701265832873588876[279] = 0.0;
   out_7701265832873588876[280] = 0.0;
   out_7701265832873588876[281] = 0.0;
   out_7701265832873588876[282] = 0.0;
   out_7701265832873588876[283] = 0.0;
   out_7701265832873588876[284] = 0.0;
   out_7701265832873588876[285] = 1.0;
   out_7701265832873588876[286] = 0.0;
   out_7701265832873588876[287] = 0.0;
   out_7701265832873588876[288] = 0.0;
   out_7701265832873588876[289] = 0.0;
   out_7701265832873588876[290] = 0.0;
   out_7701265832873588876[291] = 0.0;
   out_7701265832873588876[292] = 0.0;
   out_7701265832873588876[293] = 0.0;
   out_7701265832873588876[294] = 0.0;
   out_7701265832873588876[295] = 0.0;
   out_7701265832873588876[296] = 0.0;
   out_7701265832873588876[297] = 0.0;
   out_7701265832873588876[298] = 0.0;
   out_7701265832873588876[299] = 0.0;
   out_7701265832873588876[300] = 0.0;
   out_7701265832873588876[301] = 0.0;
   out_7701265832873588876[302] = 0.0;
   out_7701265832873588876[303] = 0.0;
   out_7701265832873588876[304] = 1.0;
   out_7701265832873588876[305] = 0.0;
   out_7701265832873588876[306] = 0.0;
   out_7701265832873588876[307] = 0.0;
   out_7701265832873588876[308] = 0.0;
   out_7701265832873588876[309] = 0.0;
   out_7701265832873588876[310] = 0.0;
   out_7701265832873588876[311] = 0.0;
   out_7701265832873588876[312] = 0.0;
   out_7701265832873588876[313] = 0.0;
   out_7701265832873588876[314] = 0.0;
   out_7701265832873588876[315] = 0.0;
   out_7701265832873588876[316] = 0.0;
   out_7701265832873588876[317] = 0.0;
   out_7701265832873588876[318] = 0.0;
   out_7701265832873588876[319] = 0.0;
   out_7701265832873588876[320] = 0.0;
   out_7701265832873588876[321] = 0.0;
   out_7701265832873588876[322] = 0.0;
   out_7701265832873588876[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2925592785824916722) {
   out_2925592785824916722[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2925592785824916722[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2925592785824916722[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2925592785824916722[3] = dt*state[12] + state[3];
   out_2925592785824916722[4] = dt*state[13] + state[4];
   out_2925592785824916722[5] = dt*state[14] + state[5];
   out_2925592785824916722[6] = state[6];
   out_2925592785824916722[7] = state[7];
   out_2925592785824916722[8] = state[8];
   out_2925592785824916722[9] = state[9];
   out_2925592785824916722[10] = state[10];
   out_2925592785824916722[11] = state[11];
   out_2925592785824916722[12] = state[12];
   out_2925592785824916722[13] = state[13];
   out_2925592785824916722[14] = state[14];
   out_2925592785824916722[15] = state[15];
   out_2925592785824916722[16] = state[16];
   out_2925592785824916722[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6409294416375959373) {
   out_6409294416375959373[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6409294416375959373[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6409294416375959373[2] = 0;
   out_6409294416375959373[3] = 0;
   out_6409294416375959373[4] = 0;
   out_6409294416375959373[5] = 0;
   out_6409294416375959373[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6409294416375959373[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6409294416375959373[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6409294416375959373[9] = 0;
   out_6409294416375959373[10] = 0;
   out_6409294416375959373[11] = 0;
   out_6409294416375959373[12] = 0;
   out_6409294416375959373[13] = 0;
   out_6409294416375959373[14] = 0;
   out_6409294416375959373[15] = 0;
   out_6409294416375959373[16] = 0;
   out_6409294416375959373[17] = 0;
   out_6409294416375959373[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6409294416375959373[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6409294416375959373[20] = 0;
   out_6409294416375959373[21] = 0;
   out_6409294416375959373[22] = 0;
   out_6409294416375959373[23] = 0;
   out_6409294416375959373[24] = 0;
   out_6409294416375959373[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6409294416375959373[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6409294416375959373[27] = 0;
   out_6409294416375959373[28] = 0;
   out_6409294416375959373[29] = 0;
   out_6409294416375959373[30] = 0;
   out_6409294416375959373[31] = 0;
   out_6409294416375959373[32] = 0;
   out_6409294416375959373[33] = 0;
   out_6409294416375959373[34] = 0;
   out_6409294416375959373[35] = 0;
   out_6409294416375959373[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6409294416375959373[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6409294416375959373[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6409294416375959373[39] = 0;
   out_6409294416375959373[40] = 0;
   out_6409294416375959373[41] = 0;
   out_6409294416375959373[42] = 0;
   out_6409294416375959373[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6409294416375959373[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6409294416375959373[45] = 0;
   out_6409294416375959373[46] = 0;
   out_6409294416375959373[47] = 0;
   out_6409294416375959373[48] = 0;
   out_6409294416375959373[49] = 0;
   out_6409294416375959373[50] = 0;
   out_6409294416375959373[51] = 0;
   out_6409294416375959373[52] = 0;
   out_6409294416375959373[53] = 0;
   out_6409294416375959373[54] = 0;
   out_6409294416375959373[55] = 0;
   out_6409294416375959373[56] = 0;
   out_6409294416375959373[57] = 1;
   out_6409294416375959373[58] = 0;
   out_6409294416375959373[59] = 0;
   out_6409294416375959373[60] = 0;
   out_6409294416375959373[61] = 0;
   out_6409294416375959373[62] = 0;
   out_6409294416375959373[63] = 0;
   out_6409294416375959373[64] = 0;
   out_6409294416375959373[65] = 0;
   out_6409294416375959373[66] = dt;
   out_6409294416375959373[67] = 0;
   out_6409294416375959373[68] = 0;
   out_6409294416375959373[69] = 0;
   out_6409294416375959373[70] = 0;
   out_6409294416375959373[71] = 0;
   out_6409294416375959373[72] = 0;
   out_6409294416375959373[73] = 0;
   out_6409294416375959373[74] = 0;
   out_6409294416375959373[75] = 0;
   out_6409294416375959373[76] = 1;
   out_6409294416375959373[77] = 0;
   out_6409294416375959373[78] = 0;
   out_6409294416375959373[79] = 0;
   out_6409294416375959373[80] = 0;
   out_6409294416375959373[81] = 0;
   out_6409294416375959373[82] = 0;
   out_6409294416375959373[83] = 0;
   out_6409294416375959373[84] = 0;
   out_6409294416375959373[85] = dt;
   out_6409294416375959373[86] = 0;
   out_6409294416375959373[87] = 0;
   out_6409294416375959373[88] = 0;
   out_6409294416375959373[89] = 0;
   out_6409294416375959373[90] = 0;
   out_6409294416375959373[91] = 0;
   out_6409294416375959373[92] = 0;
   out_6409294416375959373[93] = 0;
   out_6409294416375959373[94] = 0;
   out_6409294416375959373[95] = 1;
   out_6409294416375959373[96] = 0;
   out_6409294416375959373[97] = 0;
   out_6409294416375959373[98] = 0;
   out_6409294416375959373[99] = 0;
   out_6409294416375959373[100] = 0;
   out_6409294416375959373[101] = 0;
   out_6409294416375959373[102] = 0;
   out_6409294416375959373[103] = 0;
   out_6409294416375959373[104] = dt;
   out_6409294416375959373[105] = 0;
   out_6409294416375959373[106] = 0;
   out_6409294416375959373[107] = 0;
   out_6409294416375959373[108] = 0;
   out_6409294416375959373[109] = 0;
   out_6409294416375959373[110] = 0;
   out_6409294416375959373[111] = 0;
   out_6409294416375959373[112] = 0;
   out_6409294416375959373[113] = 0;
   out_6409294416375959373[114] = 1;
   out_6409294416375959373[115] = 0;
   out_6409294416375959373[116] = 0;
   out_6409294416375959373[117] = 0;
   out_6409294416375959373[118] = 0;
   out_6409294416375959373[119] = 0;
   out_6409294416375959373[120] = 0;
   out_6409294416375959373[121] = 0;
   out_6409294416375959373[122] = 0;
   out_6409294416375959373[123] = 0;
   out_6409294416375959373[124] = 0;
   out_6409294416375959373[125] = 0;
   out_6409294416375959373[126] = 0;
   out_6409294416375959373[127] = 0;
   out_6409294416375959373[128] = 0;
   out_6409294416375959373[129] = 0;
   out_6409294416375959373[130] = 0;
   out_6409294416375959373[131] = 0;
   out_6409294416375959373[132] = 0;
   out_6409294416375959373[133] = 1;
   out_6409294416375959373[134] = 0;
   out_6409294416375959373[135] = 0;
   out_6409294416375959373[136] = 0;
   out_6409294416375959373[137] = 0;
   out_6409294416375959373[138] = 0;
   out_6409294416375959373[139] = 0;
   out_6409294416375959373[140] = 0;
   out_6409294416375959373[141] = 0;
   out_6409294416375959373[142] = 0;
   out_6409294416375959373[143] = 0;
   out_6409294416375959373[144] = 0;
   out_6409294416375959373[145] = 0;
   out_6409294416375959373[146] = 0;
   out_6409294416375959373[147] = 0;
   out_6409294416375959373[148] = 0;
   out_6409294416375959373[149] = 0;
   out_6409294416375959373[150] = 0;
   out_6409294416375959373[151] = 0;
   out_6409294416375959373[152] = 1;
   out_6409294416375959373[153] = 0;
   out_6409294416375959373[154] = 0;
   out_6409294416375959373[155] = 0;
   out_6409294416375959373[156] = 0;
   out_6409294416375959373[157] = 0;
   out_6409294416375959373[158] = 0;
   out_6409294416375959373[159] = 0;
   out_6409294416375959373[160] = 0;
   out_6409294416375959373[161] = 0;
   out_6409294416375959373[162] = 0;
   out_6409294416375959373[163] = 0;
   out_6409294416375959373[164] = 0;
   out_6409294416375959373[165] = 0;
   out_6409294416375959373[166] = 0;
   out_6409294416375959373[167] = 0;
   out_6409294416375959373[168] = 0;
   out_6409294416375959373[169] = 0;
   out_6409294416375959373[170] = 0;
   out_6409294416375959373[171] = 1;
   out_6409294416375959373[172] = 0;
   out_6409294416375959373[173] = 0;
   out_6409294416375959373[174] = 0;
   out_6409294416375959373[175] = 0;
   out_6409294416375959373[176] = 0;
   out_6409294416375959373[177] = 0;
   out_6409294416375959373[178] = 0;
   out_6409294416375959373[179] = 0;
   out_6409294416375959373[180] = 0;
   out_6409294416375959373[181] = 0;
   out_6409294416375959373[182] = 0;
   out_6409294416375959373[183] = 0;
   out_6409294416375959373[184] = 0;
   out_6409294416375959373[185] = 0;
   out_6409294416375959373[186] = 0;
   out_6409294416375959373[187] = 0;
   out_6409294416375959373[188] = 0;
   out_6409294416375959373[189] = 0;
   out_6409294416375959373[190] = 1;
   out_6409294416375959373[191] = 0;
   out_6409294416375959373[192] = 0;
   out_6409294416375959373[193] = 0;
   out_6409294416375959373[194] = 0;
   out_6409294416375959373[195] = 0;
   out_6409294416375959373[196] = 0;
   out_6409294416375959373[197] = 0;
   out_6409294416375959373[198] = 0;
   out_6409294416375959373[199] = 0;
   out_6409294416375959373[200] = 0;
   out_6409294416375959373[201] = 0;
   out_6409294416375959373[202] = 0;
   out_6409294416375959373[203] = 0;
   out_6409294416375959373[204] = 0;
   out_6409294416375959373[205] = 0;
   out_6409294416375959373[206] = 0;
   out_6409294416375959373[207] = 0;
   out_6409294416375959373[208] = 0;
   out_6409294416375959373[209] = 1;
   out_6409294416375959373[210] = 0;
   out_6409294416375959373[211] = 0;
   out_6409294416375959373[212] = 0;
   out_6409294416375959373[213] = 0;
   out_6409294416375959373[214] = 0;
   out_6409294416375959373[215] = 0;
   out_6409294416375959373[216] = 0;
   out_6409294416375959373[217] = 0;
   out_6409294416375959373[218] = 0;
   out_6409294416375959373[219] = 0;
   out_6409294416375959373[220] = 0;
   out_6409294416375959373[221] = 0;
   out_6409294416375959373[222] = 0;
   out_6409294416375959373[223] = 0;
   out_6409294416375959373[224] = 0;
   out_6409294416375959373[225] = 0;
   out_6409294416375959373[226] = 0;
   out_6409294416375959373[227] = 0;
   out_6409294416375959373[228] = 1;
   out_6409294416375959373[229] = 0;
   out_6409294416375959373[230] = 0;
   out_6409294416375959373[231] = 0;
   out_6409294416375959373[232] = 0;
   out_6409294416375959373[233] = 0;
   out_6409294416375959373[234] = 0;
   out_6409294416375959373[235] = 0;
   out_6409294416375959373[236] = 0;
   out_6409294416375959373[237] = 0;
   out_6409294416375959373[238] = 0;
   out_6409294416375959373[239] = 0;
   out_6409294416375959373[240] = 0;
   out_6409294416375959373[241] = 0;
   out_6409294416375959373[242] = 0;
   out_6409294416375959373[243] = 0;
   out_6409294416375959373[244] = 0;
   out_6409294416375959373[245] = 0;
   out_6409294416375959373[246] = 0;
   out_6409294416375959373[247] = 1;
   out_6409294416375959373[248] = 0;
   out_6409294416375959373[249] = 0;
   out_6409294416375959373[250] = 0;
   out_6409294416375959373[251] = 0;
   out_6409294416375959373[252] = 0;
   out_6409294416375959373[253] = 0;
   out_6409294416375959373[254] = 0;
   out_6409294416375959373[255] = 0;
   out_6409294416375959373[256] = 0;
   out_6409294416375959373[257] = 0;
   out_6409294416375959373[258] = 0;
   out_6409294416375959373[259] = 0;
   out_6409294416375959373[260] = 0;
   out_6409294416375959373[261] = 0;
   out_6409294416375959373[262] = 0;
   out_6409294416375959373[263] = 0;
   out_6409294416375959373[264] = 0;
   out_6409294416375959373[265] = 0;
   out_6409294416375959373[266] = 1;
   out_6409294416375959373[267] = 0;
   out_6409294416375959373[268] = 0;
   out_6409294416375959373[269] = 0;
   out_6409294416375959373[270] = 0;
   out_6409294416375959373[271] = 0;
   out_6409294416375959373[272] = 0;
   out_6409294416375959373[273] = 0;
   out_6409294416375959373[274] = 0;
   out_6409294416375959373[275] = 0;
   out_6409294416375959373[276] = 0;
   out_6409294416375959373[277] = 0;
   out_6409294416375959373[278] = 0;
   out_6409294416375959373[279] = 0;
   out_6409294416375959373[280] = 0;
   out_6409294416375959373[281] = 0;
   out_6409294416375959373[282] = 0;
   out_6409294416375959373[283] = 0;
   out_6409294416375959373[284] = 0;
   out_6409294416375959373[285] = 1;
   out_6409294416375959373[286] = 0;
   out_6409294416375959373[287] = 0;
   out_6409294416375959373[288] = 0;
   out_6409294416375959373[289] = 0;
   out_6409294416375959373[290] = 0;
   out_6409294416375959373[291] = 0;
   out_6409294416375959373[292] = 0;
   out_6409294416375959373[293] = 0;
   out_6409294416375959373[294] = 0;
   out_6409294416375959373[295] = 0;
   out_6409294416375959373[296] = 0;
   out_6409294416375959373[297] = 0;
   out_6409294416375959373[298] = 0;
   out_6409294416375959373[299] = 0;
   out_6409294416375959373[300] = 0;
   out_6409294416375959373[301] = 0;
   out_6409294416375959373[302] = 0;
   out_6409294416375959373[303] = 0;
   out_6409294416375959373[304] = 1;
   out_6409294416375959373[305] = 0;
   out_6409294416375959373[306] = 0;
   out_6409294416375959373[307] = 0;
   out_6409294416375959373[308] = 0;
   out_6409294416375959373[309] = 0;
   out_6409294416375959373[310] = 0;
   out_6409294416375959373[311] = 0;
   out_6409294416375959373[312] = 0;
   out_6409294416375959373[313] = 0;
   out_6409294416375959373[314] = 0;
   out_6409294416375959373[315] = 0;
   out_6409294416375959373[316] = 0;
   out_6409294416375959373[317] = 0;
   out_6409294416375959373[318] = 0;
   out_6409294416375959373[319] = 0;
   out_6409294416375959373[320] = 0;
   out_6409294416375959373[321] = 0;
   out_6409294416375959373[322] = 0;
   out_6409294416375959373[323] = 1;
}
void h_4(double *state, double *unused, double *out_915233285986441516) {
   out_915233285986441516[0] = state[6] + state[9];
   out_915233285986441516[1] = state[7] + state[10];
   out_915233285986441516[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8851967337240186650) {
   out_8851967337240186650[0] = 0;
   out_8851967337240186650[1] = 0;
   out_8851967337240186650[2] = 0;
   out_8851967337240186650[3] = 0;
   out_8851967337240186650[4] = 0;
   out_8851967337240186650[5] = 0;
   out_8851967337240186650[6] = 1;
   out_8851967337240186650[7] = 0;
   out_8851967337240186650[8] = 0;
   out_8851967337240186650[9] = 1;
   out_8851967337240186650[10] = 0;
   out_8851967337240186650[11] = 0;
   out_8851967337240186650[12] = 0;
   out_8851967337240186650[13] = 0;
   out_8851967337240186650[14] = 0;
   out_8851967337240186650[15] = 0;
   out_8851967337240186650[16] = 0;
   out_8851967337240186650[17] = 0;
   out_8851967337240186650[18] = 0;
   out_8851967337240186650[19] = 0;
   out_8851967337240186650[20] = 0;
   out_8851967337240186650[21] = 0;
   out_8851967337240186650[22] = 0;
   out_8851967337240186650[23] = 0;
   out_8851967337240186650[24] = 0;
   out_8851967337240186650[25] = 1;
   out_8851967337240186650[26] = 0;
   out_8851967337240186650[27] = 0;
   out_8851967337240186650[28] = 1;
   out_8851967337240186650[29] = 0;
   out_8851967337240186650[30] = 0;
   out_8851967337240186650[31] = 0;
   out_8851967337240186650[32] = 0;
   out_8851967337240186650[33] = 0;
   out_8851967337240186650[34] = 0;
   out_8851967337240186650[35] = 0;
   out_8851967337240186650[36] = 0;
   out_8851967337240186650[37] = 0;
   out_8851967337240186650[38] = 0;
   out_8851967337240186650[39] = 0;
   out_8851967337240186650[40] = 0;
   out_8851967337240186650[41] = 0;
   out_8851967337240186650[42] = 0;
   out_8851967337240186650[43] = 0;
   out_8851967337240186650[44] = 1;
   out_8851967337240186650[45] = 0;
   out_8851967337240186650[46] = 0;
   out_8851967337240186650[47] = 1;
   out_8851967337240186650[48] = 0;
   out_8851967337240186650[49] = 0;
   out_8851967337240186650[50] = 0;
   out_8851967337240186650[51] = 0;
   out_8851967337240186650[52] = 0;
   out_8851967337240186650[53] = 0;
}
void h_10(double *state, double *unused, double *out_1698568734316977875) {
   out_1698568734316977875[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1698568734316977875[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1698568734316977875[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2859565754749971930) {
   out_2859565754749971930[0] = 0;
   out_2859565754749971930[1] = 9.8100000000000005*cos(state[1]);
   out_2859565754749971930[2] = 0;
   out_2859565754749971930[3] = 0;
   out_2859565754749971930[4] = -state[8];
   out_2859565754749971930[5] = state[7];
   out_2859565754749971930[6] = 0;
   out_2859565754749971930[7] = state[5];
   out_2859565754749971930[8] = -state[4];
   out_2859565754749971930[9] = 0;
   out_2859565754749971930[10] = 0;
   out_2859565754749971930[11] = 0;
   out_2859565754749971930[12] = 1;
   out_2859565754749971930[13] = 0;
   out_2859565754749971930[14] = 0;
   out_2859565754749971930[15] = 1;
   out_2859565754749971930[16] = 0;
   out_2859565754749971930[17] = 0;
   out_2859565754749971930[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2859565754749971930[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2859565754749971930[20] = 0;
   out_2859565754749971930[21] = state[8];
   out_2859565754749971930[22] = 0;
   out_2859565754749971930[23] = -state[6];
   out_2859565754749971930[24] = -state[5];
   out_2859565754749971930[25] = 0;
   out_2859565754749971930[26] = state[3];
   out_2859565754749971930[27] = 0;
   out_2859565754749971930[28] = 0;
   out_2859565754749971930[29] = 0;
   out_2859565754749971930[30] = 0;
   out_2859565754749971930[31] = 1;
   out_2859565754749971930[32] = 0;
   out_2859565754749971930[33] = 0;
   out_2859565754749971930[34] = 1;
   out_2859565754749971930[35] = 0;
   out_2859565754749971930[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2859565754749971930[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2859565754749971930[38] = 0;
   out_2859565754749971930[39] = -state[7];
   out_2859565754749971930[40] = state[6];
   out_2859565754749971930[41] = 0;
   out_2859565754749971930[42] = state[4];
   out_2859565754749971930[43] = -state[3];
   out_2859565754749971930[44] = 0;
   out_2859565754749971930[45] = 0;
   out_2859565754749971930[46] = 0;
   out_2859565754749971930[47] = 0;
   out_2859565754749971930[48] = 0;
   out_2859565754749971930[49] = 0;
   out_2859565754749971930[50] = 1;
   out_2859565754749971930[51] = 0;
   out_2859565754749971930[52] = 0;
   out_2859565754749971930[53] = 1;
}
void h_13(double *state, double *unused, double *out_4058736517215946312) {
   out_4058736517215946312[0] = state[3];
   out_4058736517215946312[1] = state[4];
   out_4058736517215946312[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6382502911137032165) {
   out_6382502911137032165[0] = 0;
   out_6382502911137032165[1] = 0;
   out_6382502911137032165[2] = 0;
   out_6382502911137032165[3] = 1;
   out_6382502911137032165[4] = 0;
   out_6382502911137032165[5] = 0;
   out_6382502911137032165[6] = 0;
   out_6382502911137032165[7] = 0;
   out_6382502911137032165[8] = 0;
   out_6382502911137032165[9] = 0;
   out_6382502911137032165[10] = 0;
   out_6382502911137032165[11] = 0;
   out_6382502911137032165[12] = 0;
   out_6382502911137032165[13] = 0;
   out_6382502911137032165[14] = 0;
   out_6382502911137032165[15] = 0;
   out_6382502911137032165[16] = 0;
   out_6382502911137032165[17] = 0;
   out_6382502911137032165[18] = 0;
   out_6382502911137032165[19] = 0;
   out_6382502911137032165[20] = 0;
   out_6382502911137032165[21] = 0;
   out_6382502911137032165[22] = 1;
   out_6382502911137032165[23] = 0;
   out_6382502911137032165[24] = 0;
   out_6382502911137032165[25] = 0;
   out_6382502911137032165[26] = 0;
   out_6382502911137032165[27] = 0;
   out_6382502911137032165[28] = 0;
   out_6382502911137032165[29] = 0;
   out_6382502911137032165[30] = 0;
   out_6382502911137032165[31] = 0;
   out_6382502911137032165[32] = 0;
   out_6382502911137032165[33] = 0;
   out_6382502911137032165[34] = 0;
   out_6382502911137032165[35] = 0;
   out_6382502911137032165[36] = 0;
   out_6382502911137032165[37] = 0;
   out_6382502911137032165[38] = 0;
   out_6382502911137032165[39] = 0;
   out_6382502911137032165[40] = 0;
   out_6382502911137032165[41] = 1;
   out_6382502911137032165[42] = 0;
   out_6382502911137032165[43] = 0;
   out_6382502911137032165[44] = 0;
   out_6382502911137032165[45] = 0;
   out_6382502911137032165[46] = 0;
   out_6382502911137032165[47] = 0;
   out_6382502911137032165[48] = 0;
   out_6382502911137032165[49] = 0;
   out_6382502911137032165[50] = 0;
   out_6382502911137032165[51] = 0;
   out_6382502911137032165[52] = 0;
   out_6382502911137032165[53] = 0;
}
void h_14(double *state, double *unused, double *out_6181664354414385783) {
   out_6181664354414385783[0] = state[6];
   out_6181664354414385783[1] = state[7];
   out_6181664354414385783[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8416850810595303051) {
   out_8416850810595303051[0] = 0;
   out_8416850810595303051[1] = 0;
   out_8416850810595303051[2] = 0;
   out_8416850810595303051[3] = 0;
   out_8416850810595303051[4] = 0;
   out_8416850810595303051[5] = 0;
   out_8416850810595303051[6] = 1;
   out_8416850810595303051[7] = 0;
   out_8416850810595303051[8] = 0;
   out_8416850810595303051[9] = 0;
   out_8416850810595303051[10] = 0;
   out_8416850810595303051[11] = 0;
   out_8416850810595303051[12] = 0;
   out_8416850810595303051[13] = 0;
   out_8416850810595303051[14] = 0;
   out_8416850810595303051[15] = 0;
   out_8416850810595303051[16] = 0;
   out_8416850810595303051[17] = 0;
   out_8416850810595303051[18] = 0;
   out_8416850810595303051[19] = 0;
   out_8416850810595303051[20] = 0;
   out_8416850810595303051[21] = 0;
   out_8416850810595303051[22] = 0;
   out_8416850810595303051[23] = 0;
   out_8416850810595303051[24] = 0;
   out_8416850810595303051[25] = 1;
   out_8416850810595303051[26] = 0;
   out_8416850810595303051[27] = 0;
   out_8416850810595303051[28] = 0;
   out_8416850810595303051[29] = 0;
   out_8416850810595303051[30] = 0;
   out_8416850810595303051[31] = 0;
   out_8416850810595303051[32] = 0;
   out_8416850810595303051[33] = 0;
   out_8416850810595303051[34] = 0;
   out_8416850810595303051[35] = 0;
   out_8416850810595303051[36] = 0;
   out_8416850810595303051[37] = 0;
   out_8416850810595303051[38] = 0;
   out_8416850810595303051[39] = 0;
   out_8416850810595303051[40] = 0;
   out_8416850810595303051[41] = 0;
   out_8416850810595303051[42] = 0;
   out_8416850810595303051[43] = 0;
   out_8416850810595303051[44] = 1;
   out_8416850810595303051[45] = 0;
   out_8416850810595303051[46] = 0;
   out_8416850810595303051[47] = 0;
   out_8416850810595303051[48] = 0;
   out_8416850810595303051[49] = 0;
   out_8416850810595303051[50] = 0;
   out_8416850810595303051[51] = 0;
   out_8416850810595303051[52] = 0;
   out_8416850810595303051[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_2367672105654731741) {
  err_fun(nom_x, delta_x, out_2367672105654731741);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5219205296235492699) {
  inv_err_fun(nom_x, true_x, out_5219205296235492699);
}
void pose_H_mod_fun(double *state, double *out_7701265832873588876) {
  H_mod_fun(state, out_7701265832873588876);
}
void pose_f_fun(double *state, double dt, double *out_2925592785824916722) {
  f_fun(state,  dt, out_2925592785824916722);
}
void pose_F_fun(double *state, double dt, double *out_6409294416375959373) {
  F_fun(state,  dt, out_6409294416375959373);
}
void pose_h_4(double *state, double *unused, double *out_915233285986441516) {
  h_4(state, unused, out_915233285986441516);
}
void pose_H_4(double *state, double *unused, double *out_8851967337240186650) {
  H_4(state, unused, out_8851967337240186650);
}
void pose_h_10(double *state, double *unused, double *out_1698568734316977875) {
  h_10(state, unused, out_1698568734316977875);
}
void pose_H_10(double *state, double *unused, double *out_2859565754749971930) {
  H_10(state, unused, out_2859565754749971930);
}
void pose_h_13(double *state, double *unused, double *out_4058736517215946312) {
  h_13(state, unused, out_4058736517215946312);
}
void pose_H_13(double *state, double *unused, double *out_6382502911137032165) {
  H_13(state, unused, out_6382502911137032165);
}
void pose_h_14(double *state, double *unused, double *out_6181664354414385783) {
  h_14(state, unused, out_6181664354414385783);
}
void pose_H_14(double *state, double *unused, double *out_8416850810595303051) {
  H_14(state, unused, out_8416850810595303051);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
