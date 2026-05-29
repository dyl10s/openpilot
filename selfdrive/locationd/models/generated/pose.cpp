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
void err_fun(double *nom_x, double *delta_x, double *out_3083751291667230086) {
   out_3083751291667230086[0] = delta_x[0] + nom_x[0];
   out_3083751291667230086[1] = delta_x[1] + nom_x[1];
   out_3083751291667230086[2] = delta_x[2] + nom_x[2];
   out_3083751291667230086[3] = delta_x[3] + nom_x[3];
   out_3083751291667230086[4] = delta_x[4] + nom_x[4];
   out_3083751291667230086[5] = delta_x[5] + nom_x[5];
   out_3083751291667230086[6] = delta_x[6] + nom_x[6];
   out_3083751291667230086[7] = delta_x[7] + nom_x[7];
   out_3083751291667230086[8] = delta_x[8] + nom_x[8];
   out_3083751291667230086[9] = delta_x[9] + nom_x[9];
   out_3083751291667230086[10] = delta_x[10] + nom_x[10];
   out_3083751291667230086[11] = delta_x[11] + nom_x[11];
   out_3083751291667230086[12] = delta_x[12] + nom_x[12];
   out_3083751291667230086[13] = delta_x[13] + nom_x[13];
   out_3083751291667230086[14] = delta_x[14] + nom_x[14];
   out_3083751291667230086[15] = delta_x[15] + nom_x[15];
   out_3083751291667230086[16] = delta_x[16] + nom_x[16];
   out_3083751291667230086[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8958923596036680453) {
   out_8958923596036680453[0] = -nom_x[0] + true_x[0];
   out_8958923596036680453[1] = -nom_x[1] + true_x[1];
   out_8958923596036680453[2] = -nom_x[2] + true_x[2];
   out_8958923596036680453[3] = -nom_x[3] + true_x[3];
   out_8958923596036680453[4] = -nom_x[4] + true_x[4];
   out_8958923596036680453[5] = -nom_x[5] + true_x[5];
   out_8958923596036680453[6] = -nom_x[6] + true_x[6];
   out_8958923596036680453[7] = -nom_x[7] + true_x[7];
   out_8958923596036680453[8] = -nom_x[8] + true_x[8];
   out_8958923596036680453[9] = -nom_x[9] + true_x[9];
   out_8958923596036680453[10] = -nom_x[10] + true_x[10];
   out_8958923596036680453[11] = -nom_x[11] + true_x[11];
   out_8958923596036680453[12] = -nom_x[12] + true_x[12];
   out_8958923596036680453[13] = -nom_x[13] + true_x[13];
   out_8958923596036680453[14] = -nom_x[14] + true_x[14];
   out_8958923596036680453[15] = -nom_x[15] + true_x[15];
   out_8958923596036680453[16] = -nom_x[16] + true_x[16];
   out_8958923596036680453[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3451746955233961922) {
   out_3451746955233961922[0] = 1.0;
   out_3451746955233961922[1] = 0.0;
   out_3451746955233961922[2] = 0.0;
   out_3451746955233961922[3] = 0.0;
   out_3451746955233961922[4] = 0.0;
   out_3451746955233961922[5] = 0.0;
   out_3451746955233961922[6] = 0.0;
   out_3451746955233961922[7] = 0.0;
   out_3451746955233961922[8] = 0.0;
   out_3451746955233961922[9] = 0.0;
   out_3451746955233961922[10] = 0.0;
   out_3451746955233961922[11] = 0.0;
   out_3451746955233961922[12] = 0.0;
   out_3451746955233961922[13] = 0.0;
   out_3451746955233961922[14] = 0.0;
   out_3451746955233961922[15] = 0.0;
   out_3451746955233961922[16] = 0.0;
   out_3451746955233961922[17] = 0.0;
   out_3451746955233961922[18] = 0.0;
   out_3451746955233961922[19] = 1.0;
   out_3451746955233961922[20] = 0.0;
   out_3451746955233961922[21] = 0.0;
   out_3451746955233961922[22] = 0.0;
   out_3451746955233961922[23] = 0.0;
   out_3451746955233961922[24] = 0.0;
   out_3451746955233961922[25] = 0.0;
   out_3451746955233961922[26] = 0.0;
   out_3451746955233961922[27] = 0.0;
   out_3451746955233961922[28] = 0.0;
   out_3451746955233961922[29] = 0.0;
   out_3451746955233961922[30] = 0.0;
   out_3451746955233961922[31] = 0.0;
   out_3451746955233961922[32] = 0.0;
   out_3451746955233961922[33] = 0.0;
   out_3451746955233961922[34] = 0.0;
   out_3451746955233961922[35] = 0.0;
   out_3451746955233961922[36] = 0.0;
   out_3451746955233961922[37] = 0.0;
   out_3451746955233961922[38] = 1.0;
   out_3451746955233961922[39] = 0.0;
   out_3451746955233961922[40] = 0.0;
   out_3451746955233961922[41] = 0.0;
   out_3451746955233961922[42] = 0.0;
   out_3451746955233961922[43] = 0.0;
   out_3451746955233961922[44] = 0.0;
   out_3451746955233961922[45] = 0.0;
   out_3451746955233961922[46] = 0.0;
   out_3451746955233961922[47] = 0.0;
   out_3451746955233961922[48] = 0.0;
   out_3451746955233961922[49] = 0.0;
   out_3451746955233961922[50] = 0.0;
   out_3451746955233961922[51] = 0.0;
   out_3451746955233961922[52] = 0.0;
   out_3451746955233961922[53] = 0.0;
   out_3451746955233961922[54] = 0.0;
   out_3451746955233961922[55] = 0.0;
   out_3451746955233961922[56] = 0.0;
   out_3451746955233961922[57] = 1.0;
   out_3451746955233961922[58] = 0.0;
   out_3451746955233961922[59] = 0.0;
   out_3451746955233961922[60] = 0.0;
   out_3451746955233961922[61] = 0.0;
   out_3451746955233961922[62] = 0.0;
   out_3451746955233961922[63] = 0.0;
   out_3451746955233961922[64] = 0.0;
   out_3451746955233961922[65] = 0.0;
   out_3451746955233961922[66] = 0.0;
   out_3451746955233961922[67] = 0.0;
   out_3451746955233961922[68] = 0.0;
   out_3451746955233961922[69] = 0.0;
   out_3451746955233961922[70] = 0.0;
   out_3451746955233961922[71] = 0.0;
   out_3451746955233961922[72] = 0.0;
   out_3451746955233961922[73] = 0.0;
   out_3451746955233961922[74] = 0.0;
   out_3451746955233961922[75] = 0.0;
   out_3451746955233961922[76] = 1.0;
   out_3451746955233961922[77] = 0.0;
   out_3451746955233961922[78] = 0.0;
   out_3451746955233961922[79] = 0.0;
   out_3451746955233961922[80] = 0.0;
   out_3451746955233961922[81] = 0.0;
   out_3451746955233961922[82] = 0.0;
   out_3451746955233961922[83] = 0.0;
   out_3451746955233961922[84] = 0.0;
   out_3451746955233961922[85] = 0.0;
   out_3451746955233961922[86] = 0.0;
   out_3451746955233961922[87] = 0.0;
   out_3451746955233961922[88] = 0.0;
   out_3451746955233961922[89] = 0.0;
   out_3451746955233961922[90] = 0.0;
   out_3451746955233961922[91] = 0.0;
   out_3451746955233961922[92] = 0.0;
   out_3451746955233961922[93] = 0.0;
   out_3451746955233961922[94] = 0.0;
   out_3451746955233961922[95] = 1.0;
   out_3451746955233961922[96] = 0.0;
   out_3451746955233961922[97] = 0.0;
   out_3451746955233961922[98] = 0.0;
   out_3451746955233961922[99] = 0.0;
   out_3451746955233961922[100] = 0.0;
   out_3451746955233961922[101] = 0.0;
   out_3451746955233961922[102] = 0.0;
   out_3451746955233961922[103] = 0.0;
   out_3451746955233961922[104] = 0.0;
   out_3451746955233961922[105] = 0.0;
   out_3451746955233961922[106] = 0.0;
   out_3451746955233961922[107] = 0.0;
   out_3451746955233961922[108] = 0.0;
   out_3451746955233961922[109] = 0.0;
   out_3451746955233961922[110] = 0.0;
   out_3451746955233961922[111] = 0.0;
   out_3451746955233961922[112] = 0.0;
   out_3451746955233961922[113] = 0.0;
   out_3451746955233961922[114] = 1.0;
   out_3451746955233961922[115] = 0.0;
   out_3451746955233961922[116] = 0.0;
   out_3451746955233961922[117] = 0.0;
   out_3451746955233961922[118] = 0.0;
   out_3451746955233961922[119] = 0.0;
   out_3451746955233961922[120] = 0.0;
   out_3451746955233961922[121] = 0.0;
   out_3451746955233961922[122] = 0.0;
   out_3451746955233961922[123] = 0.0;
   out_3451746955233961922[124] = 0.0;
   out_3451746955233961922[125] = 0.0;
   out_3451746955233961922[126] = 0.0;
   out_3451746955233961922[127] = 0.0;
   out_3451746955233961922[128] = 0.0;
   out_3451746955233961922[129] = 0.0;
   out_3451746955233961922[130] = 0.0;
   out_3451746955233961922[131] = 0.0;
   out_3451746955233961922[132] = 0.0;
   out_3451746955233961922[133] = 1.0;
   out_3451746955233961922[134] = 0.0;
   out_3451746955233961922[135] = 0.0;
   out_3451746955233961922[136] = 0.0;
   out_3451746955233961922[137] = 0.0;
   out_3451746955233961922[138] = 0.0;
   out_3451746955233961922[139] = 0.0;
   out_3451746955233961922[140] = 0.0;
   out_3451746955233961922[141] = 0.0;
   out_3451746955233961922[142] = 0.0;
   out_3451746955233961922[143] = 0.0;
   out_3451746955233961922[144] = 0.0;
   out_3451746955233961922[145] = 0.0;
   out_3451746955233961922[146] = 0.0;
   out_3451746955233961922[147] = 0.0;
   out_3451746955233961922[148] = 0.0;
   out_3451746955233961922[149] = 0.0;
   out_3451746955233961922[150] = 0.0;
   out_3451746955233961922[151] = 0.0;
   out_3451746955233961922[152] = 1.0;
   out_3451746955233961922[153] = 0.0;
   out_3451746955233961922[154] = 0.0;
   out_3451746955233961922[155] = 0.0;
   out_3451746955233961922[156] = 0.0;
   out_3451746955233961922[157] = 0.0;
   out_3451746955233961922[158] = 0.0;
   out_3451746955233961922[159] = 0.0;
   out_3451746955233961922[160] = 0.0;
   out_3451746955233961922[161] = 0.0;
   out_3451746955233961922[162] = 0.0;
   out_3451746955233961922[163] = 0.0;
   out_3451746955233961922[164] = 0.0;
   out_3451746955233961922[165] = 0.0;
   out_3451746955233961922[166] = 0.0;
   out_3451746955233961922[167] = 0.0;
   out_3451746955233961922[168] = 0.0;
   out_3451746955233961922[169] = 0.0;
   out_3451746955233961922[170] = 0.0;
   out_3451746955233961922[171] = 1.0;
   out_3451746955233961922[172] = 0.0;
   out_3451746955233961922[173] = 0.0;
   out_3451746955233961922[174] = 0.0;
   out_3451746955233961922[175] = 0.0;
   out_3451746955233961922[176] = 0.0;
   out_3451746955233961922[177] = 0.0;
   out_3451746955233961922[178] = 0.0;
   out_3451746955233961922[179] = 0.0;
   out_3451746955233961922[180] = 0.0;
   out_3451746955233961922[181] = 0.0;
   out_3451746955233961922[182] = 0.0;
   out_3451746955233961922[183] = 0.0;
   out_3451746955233961922[184] = 0.0;
   out_3451746955233961922[185] = 0.0;
   out_3451746955233961922[186] = 0.0;
   out_3451746955233961922[187] = 0.0;
   out_3451746955233961922[188] = 0.0;
   out_3451746955233961922[189] = 0.0;
   out_3451746955233961922[190] = 1.0;
   out_3451746955233961922[191] = 0.0;
   out_3451746955233961922[192] = 0.0;
   out_3451746955233961922[193] = 0.0;
   out_3451746955233961922[194] = 0.0;
   out_3451746955233961922[195] = 0.0;
   out_3451746955233961922[196] = 0.0;
   out_3451746955233961922[197] = 0.0;
   out_3451746955233961922[198] = 0.0;
   out_3451746955233961922[199] = 0.0;
   out_3451746955233961922[200] = 0.0;
   out_3451746955233961922[201] = 0.0;
   out_3451746955233961922[202] = 0.0;
   out_3451746955233961922[203] = 0.0;
   out_3451746955233961922[204] = 0.0;
   out_3451746955233961922[205] = 0.0;
   out_3451746955233961922[206] = 0.0;
   out_3451746955233961922[207] = 0.0;
   out_3451746955233961922[208] = 0.0;
   out_3451746955233961922[209] = 1.0;
   out_3451746955233961922[210] = 0.0;
   out_3451746955233961922[211] = 0.0;
   out_3451746955233961922[212] = 0.0;
   out_3451746955233961922[213] = 0.0;
   out_3451746955233961922[214] = 0.0;
   out_3451746955233961922[215] = 0.0;
   out_3451746955233961922[216] = 0.0;
   out_3451746955233961922[217] = 0.0;
   out_3451746955233961922[218] = 0.0;
   out_3451746955233961922[219] = 0.0;
   out_3451746955233961922[220] = 0.0;
   out_3451746955233961922[221] = 0.0;
   out_3451746955233961922[222] = 0.0;
   out_3451746955233961922[223] = 0.0;
   out_3451746955233961922[224] = 0.0;
   out_3451746955233961922[225] = 0.0;
   out_3451746955233961922[226] = 0.0;
   out_3451746955233961922[227] = 0.0;
   out_3451746955233961922[228] = 1.0;
   out_3451746955233961922[229] = 0.0;
   out_3451746955233961922[230] = 0.0;
   out_3451746955233961922[231] = 0.0;
   out_3451746955233961922[232] = 0.0;
   out_3451746955233961922[233] = 0.0;
   out_3451746955233961922[234] = 0.0;
   out_3451746955233961922[235] = 0.0;
   out_3451746955233961922[236] = 0.0;
   out_3451746955233961922[237] = 0.0;
   out_3451746955233961922[238] = 0.0;
   out_3451746955233961922[239] = 0.0;
   out_3451746955233961922[240] = 0.0;
   out_3451746955233961922[241] = 0.0;
   out_3451746955233961922[242] = 0.0;
   out_3451746955233961922[243] = 0.0;
   out_3451746955233961922[244] = 0.0;
   out_3451746955233961922[245] = 0.0;
   out_3451746955233961922[246] = 0.0;
   out_3451746955233961922[247] = 1.0;
   out_3451746955233961922[248] = 0.0;
   out_3451746955233961922[249] = 0.0;
   out_3451746955233961922[250] = 0.0;
   out_3451746955233961922[251] = 0.0;
   out_3451746955233961922[252] = 0.0;
   out_3451746955233961922[253] = 0.0;
   out_3451746955233961922[254] = 0.0;
   out_3451746955233961922[255] = 0.0;
   out_3451746955233961922[256] = 0.0;
   out_3451746955233961922[257] = 0.0;
   out_3451746955233961922[258] = 0.0;
   out_3451746955233961922[259] = 0.0;
   out_3451746955233961922[260] = 0.0;
   out_3451746955233961922[261] = 0.0;
   out_3451746955233961922[262] = 0.0;
   out_3451746955233961922[263] = 0.0;
   out_3451746955233961922[264] = 0.0;
   out_3451746955233961922[265] = 0.0;
   out_3451746955233961922[266] = 1.0;
   out_3451746955233961922[267] = 0.0;
   out_3451746955233961922[268] = 0.0;
   out_3451746955233961922[269] = 0.0;
   out_3451746955233961922[270] = 0.0;
   out_3451746955233961922[271] = 0.0;
   out_3451746955233961922[272] = 0.0;
   out_3451746955233961922[273] = 0.0;
   out_3451746955233961922[274] = 0.0;
   out_3451746955233961922[275] = 0.0;
   out_3451746955233961922[276] = 0.0;
   out_3451746955233961922[277] = 0.0;
   out_3451746955233961922[278] = 0.0;
   out_3451746955233961922[279] = 0.0;
   out_3451746955233961922[280] = 0.0;
   out_3451746955233961922[281] = 0.0;
   out_3451746955233961922[282] = 0.0;
   out_3451746955233961922[283] = 0.0;
   out_3451746955233961922[284] = 0.0;
   out_3451746955233961922[285] = 1.0;
   out_3451746955233961922[286] = 0.0;
   out_3451746955233961922[287] = 0.0;
   out_3451746955233961922[288] = 0.0;
   out_3451746955233961922[289] = 0.0;
   out_3451746955233961922[290] = 0.0;
   out_3451746955233961922[291] = 0.0;
   out_3451746955233961922[292] = 0.0;
   out_3451746955233961922[293] = 0.0;
   out_3451746955233961922[294] = 0.0;
   out_3451746955233961922[295] = 0.0;
   out_3451746955233961922[296] = 0.0;
   out_3451746955233961922[297] = 0.0;
   out_3451746955233961922[298] = 0.0;
   out_3451746955233961922[299] = 0.0;
   out_3451746955233961922[300] = 0.0;
   out_3451746955233961922[301] = 0.0;
   out_3451746955233961922[302] = 0.0;
   out_3451746955233961922[303] = 0.0;
   out_3451746955233961922[304] = 1.0;
   out_3451746955233961922[305] = 0.0;
   out_3451746955233961922[306] = 0.0;
   out_3451746955233961922[307] = 0.0;
   out_3451746955233961922[308] = 0.0;
   out_3451746955233961922[309] = 0.0;
   out_3451746955233961922[310] = 0.0;
   out_3451746955233961922[311] = 0.0;
   out_3451746955233961922[312] = 0.0;
   out_3451746955233961922[313] = 0.0;
   out_3451746955233961922[314] = 0.0;
   out_3451746955233961922[315] = 0.0;
   out_3451746955233961922[316] = 0.0;
   out_3451746955233961922[317] = 0.0;
   out_3451746955233961922[318] = 0.0;
   out_3451746955233961922[319] = 0.0;
   out_3451746955233961922[320] = 0.0;
   out_3451746955233961922[321] = 0.0;
   out_3451746955233961922[322] = 0.0;
   out_3451746955233961922[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_9153581491484683214) {
   out_9153581491484683214[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_9153581491484683214[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_9153581491484683214[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_9153581491484683214[3] = dt*state[12] + state[3];
   out_9153581491484683214[4] = dt*state[13] + state[4];
   out_9153581491484683214[5] = dt*state[14] + state[5];
   out_9153581491484683214[6] = state[6];
   out_9153581491484683214[7] = state[7];
   out_9153581491484683214[8] = state[8];
   out_9153581491484683214[9] = state[9];
   out_9153581491484683214[10] = state[10];
   out_9153581491484683214[11] = state[11];
   out_9153581491484683214[12] = state[12];
   out_9153581491484683214[13] = state[13];
   out_9153581491484683214[14] = state[14];
   out_9153581491484683214[15] = state[15];
   out_9153581491484683214[16] = state[16];
   out_9153581491484683214[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1650230700148071035) {
   out_1650230700148071035[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1650230700148071035[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1650230700148071035[2] = 0;
   out_1650230700148071035[3] = 0;
   out_1650230700148071035[4] = 0;
   out_1650230700148071035[5] = 0;
   out_1650230700148071035[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1650230700148071035[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1650230700148071035[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1650230700148071035[9] = 0;
   out_1650230700148071035[10] = 0;
   out_1650230700148071035[11] = 0;
   out_1650230700148071035[12] = 0;
   out_1650230700148071035[13] = 0;
   out_1650230700148071035[14] = 0;
   out_1650230700148071035[15] = 0;
   out_1650230700148071035[16] = 0;
   out_1650230700148071035[17] = 0;
   out_1650230700148071035[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1650230700148071035[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1650230700148071035[20] = 0;
   out_1650230700148071035[21] = 0;
   out_1650230700148071035[22] = 0;
   out_1650230700148071035[23] = 0;
   out_1650230700148071035[24] = 0;
   out_1650230700148071035[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1650230700148071035[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1650230700148071035[27] = 0;
   out_1650230700148071035[28] = 0;
   out_1650230700148071035[29] = 0;
   out_1650230700148071035[30] = 0;
   out_1650230700148071035[31] = 0;
   out_1650230700148071035[32] = 0;
   out_1650230700148071035[33] = 0;
   out_1650230700148071035[34] = 0;
   out_1650230700148071035[35] = 0;
   out_1650230700148071035[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1650230700148071035[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1650230700148071035[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1650230700148071035[39] = 0;
   out_1650230700148071035[40] = 0;
   out_1650230700148071035[41] = 0;
   out_1650230700148071035[42] = 0;
   out_1650230700148071035[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1650230700148071035[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1650230700148071035[45] = 0;
   out_1650230700148071035[46] = 0;
   out_1650230700148071035[47] = 0;
   out_1650230700148071035[48] = 0;
   out_1650230700148071035[49] = 0;
   out_1650230700148071035[50] = 0;
   out_1650230700148071035[51] = 0;
   out_1650230700148071035[52] = 0;
   out_1650230700148071035[53] = 0;
   out_1650230700148071035[54] = 0;
   out_1650230700148071035[55] = 0;
   out_1650230700148071035[56] = 0;
   out_1650230700148071035[57] = 1;
   out_1650230700148071035[58] = 0;
   out_1650230700148071035[59] = 0;
   out_1650230700148071035[60] = 0;
   out_1650230700148071035[61] = 0;
   out_1650230700148071035[62] = 0;
   out_1650230700148071035[63] = 0;
   out_1650230700148071035[64] = 0;
   out_1650230700148071035[65] = 0;
   out_1650230700148071035[66] = dt;
   out_1650230700148071035[67] = 0;
   out_1650230700148071035[68] = 0;
   out_1650230700148071035[69] = 0;
   out_1650230700148071035[70] = 0;
   out_1650230700148071035[71] = 0;
   out_1650230700148071035[72] = 0;
   out_1650230700148071035[73] = 0;
   out_1650230700148071035[74] = 0;
   out_1650230700148071035[75] = 0;
   out_1650230700148071035[76] = 1;
   out_1650230700148071035[77] = 0;
   out_1650230700148071035[78] = 0;
   out_1650230700148071035[79] = 0;
   out_1650230700148071035[80] = 0;
   out_1650230700148071035[81] = 0;
   out_1650230700148071035[82] = 0;
   out_1650230700148071035[83] = 0;
   out_1650230700148071035[84] = 0;
   out_1650230700148071035[85] = dt;
   out_1650230700148071035[86] = 0;
   out_1650230700148071035[87] = 0;
   out_1650230700148071035[88] = 0;
   out_1650230700148071035[89] = 0;
   out_1650230700148071035[90] = 0;
   out_1650230700148071035[91] = 0;
   out_1650230700148071035[92] = 0;
   out_1650230700148071035[93] = 0;
   out_1650230700148071035[94] = 0;
   out_1650230700148071035[95] = 1;
   out_1650230700148071035[96] = 0;
   out_1650230700148071035[97] = 0;
   out_1650230700148071035[98] = 0;
   out_1650230700148071035[99] = 0;
   out_1650230700148071035[100] = 0;
   out_1650230700148071035[101] = 0;
   out_1650230700148071035[102] = 0;
   out_1650230700148071035[103] = 0;
   out_1650230700148071035[104] = dt;
   out_1650230700148071035[105] = 0;
   out_1650230700148071035[106] = 0;
   out_1650230700148071035[107] = 0;
   out_1650230700148071035[108] = 0;
   out_1650230700148071035[109] = 0;
   out_1650230700148071035[110] = 0;
   out_1650230700148071035[111] = 0;
   out_1650230700148071035[112] = 0;
   out_1650230700148071035[113] = 0;
   out_1650230700148071035[114] = 1;
   out_1650230700148071035[115] = 0;
   out_1650230700148071035[116] = 0;
   out_1650230700148071035[117] = 0;
   out_1650230700148071035[118] = 0;
   out_1650230700148071035[119] = 0;
   out_1650230700148071035[120] = 0;
   out_1650230700148071035[121] = 0;
   out_1650230700148071035[122] = 0;
   out_1650230700148071035[123] = 0;
   out_1650230700148071035[124] = 0;
   out_1650230700148071035[125] = 0;
   out_1650230700148071035[126] = 0;
   out_1650230700148071035[127] = 0;
   out_1650230700148071035[128] = 0;
   out_1650230700148071035[129] = 0;
   out_1650230700148071035[130] = 0;
   out_1650230700148071035[131] = 0;
   out_1650230700148071035[132] = 0;
   out_1650230700148071035[133] = 1;
   out_1650230700148071035[134] = 0;
   out_1650230700148071035[135] = 0;
   out_1650230700148071035[136] = 0;
   out_1650230700148071035[137] = 0;
   out_1650230700148071035[138] = 0;
   out_1650230700148071035[139] = 0;
   out_1650230700148071035[140] = 0;
   out_1650230700148071035[141] = 0;
   out_1650230700148071035[142] = 0;
   out_1650230700148071035[143] = 0;
   out_1650230700148071035[144] = 0;
   out_1650230700148071035[145] = 0;
   out_1650230700148071035[146] = 0;
   out_1650230700148071035[147] = 0;
   out_1650230700148071035[148] = 0;
   out_1650230700148071035[149] = 0;
   out_1650230700148071035[150] = 0;
   out_1650230700148071035[151] = 0;
   out_1650230700148071035[152] = 1;
   out_1650230700148071035[153] = 0;
   out_1650230700148071035[154] = 0;
   out_1650230700148071035[155] = 0;
   out_1650230700148071035[156] = 0;
   out_1650230700148071035[157] = 0;
   out_1650230700148071035[158] = 0;
   out_1650230700148071035[159] = 0;
   out_1650230700148071035[160] = 0;
   out_1650230700148071035[161] = 0;
   out_1650230700148071035[162] = 0;
   out_1650230700148071035[163] = 0;
   out_1650230700148071035[164] = 0;
   out_1650230700148071035[165] = 0;
   out_1650230700148071035[166] = 0;
   out_1650230700148071035[167] = 0;
   out_1650230700148071035[168] = 0;
   out_1650230700148071035[169] = 0;
   out_1650230700148071035[170] = 0;
   out_1650230700148071035[171] = 1;
   out_1650230700148071035[172] = 0;
   out_1650230700148071035[173] = 0;
   out_1650230700148071035[174] = 0;
   out_1650230700148071035[175] = 0;
   out_1650230700148071035[176] = 0;
   out_1650230700148071035[177] = 0;
   out_1650230700148071035[178] = 0;
   out_1650230700148071035[179] = 0;
   out_1650230700148071035[180] = 0;
   out_1650230700148071035[181] = 0;
   out_1650230700148071035[182] = 0;
   out_1650230700148071035[183] = 0;
   out_1650230700148071035[184] = 0;
   out_1650230700148071035[185] = 0;
   out_1650230700148071035[186] = 0;
   out_1650230700148071035[187] = 0;
   out_1650230700148071035[188] = 0;
   out_1650230700148071035[189] = 0;
   out_1650230700148071035[190] = 1;
   out_1650230700148071035[191] = 0;
   out_1650230700148071035[192] = 0;
   out_1650230700148071035[193] = 0;
   out_1650230700148071035[194] = 0;
   out_1650230700148071035[195] = 0;
   out_1650230700148071035[196] = 0;
   out_1650230700148071035[197] = 0;
   out_1650230700148071035[198] = 0;
   out_1650230700148071035[199] = 0;
   out_1650230700148071035[200] = 0;
   out_1650230700148071035[201] = 0;
   out_1650230700148071035[202] = 0;
   out_1650230700148071035[203] = 0;
   out_1650230700148071035[204] = 0;
   out_1650230700148071035[205] = 0;
   out_1650230700148071035[206] = 0;
   out_1650230700148071035[207] = 0;
   out_1650230700148071035[208] = 0;
   out_1650230700148071035[209] = 1;
   out_1650230700148071035[210] = 0;
   out_1650230700148071035[211] = 0;
   out_1650230700148071035[212] = 0;
   out_1650230700148071035[213] = 0;
   out_1650230700148071035[214] = 0;
   out_1650230700148071035[215] = 0;
   out_1650230700148071035[216] = 0;
   out_1650230700148071035[217] = 0;
   out_1650230700148071035[218] = 0;
   out_1650230700148071035[219] = 0;
   out_1650230700148071035[220] = 0;
   out_1650230700148071035[221] = 0;
   out_1650230700148071035[222] = 0;
   out_1650230700148071035[223] = 0;
   out_1650230700148071035[224] = 0;
   out_1650230700148071035[225] = 0;
   out_1650230700148071035[226] = 0;
   out_1650230700148071035[227] = 0;
   out_1650230700148071035[228] = 1;
   out_1650230700148071035[229] = 0;
   out_1650230700148071035[230] = 0;
   out_1650230700148071035[231] = 0;
   out_1650230700148071035[232] = 0;
   out_1650230700148071035[233] = 0;
   out_1650230700148071035[234] = 0;
   out_1650230700148071035[235] = 0;
   out_1650230700148071035[236] = 0;
   out_1650230700148071035[237] = 0;
   out_1650230700148071035[238] = 0;
   out_1650230700148071035[239] = 0;
   out_1650230700148071035[240] = 0;
   out_1650230700148071035[241] = 0;
   out_1650230700148071035[242] = 0;
   out_1650230700148071035[243] = 0;
   out_1650230700148071035[244] = 0;
   out_1650230700148071035[245] = 0;
   out_1650230700148071035[246] = 0;
   out_1650230700148071035[247] = 1;
   out_1650230700148071035[248] = 0;
   out_1650230700148071035[249] = 0;
   out_1650230700148071035[250] = 0;
   out_1650230700148071035[251] = 0;
   out_1650230700148071035[252] = 0;
   out_1650230700148071035[253] = 0;
   out_1650230700148071035[254] = 0;
   out_1650230700148071035[255] = 0;
   out_1650230700148071035[256] = 0;
   out_1650230700148071035[257] = 0;
   out_1650230700148071035[258] = 0;
   out_1650230700148071035[259] = 0;
   out_1650230700148071035[260] = 0;
   out_1650230700148071035[261] = 0;
   out_1650230700148071035[262] = 0;
   out_1650230700148071035[263] = 0;
   out_1650230700148071035[264] = 0;
   out_1650230700148071035[265] = 0;
   out_1650230700148071035[266] = 1;
   out_1650230700148071035[267] = 0;
   out_1650230700148071035[268] = 0;
   out_1650230700148071035[269] = 0;
   out_1650230700148071035[270] = 0;
   out_1650230700148071035[271] = 0;
   out_1650230700148071035[272] = 0;
   out_1650230700148071035[273] = 0;
   out_1650230700148071035[274] = 0;
   out_1650230700148071035[275] = 0;
   out_1650230700148071035[276] = 0;
   out_1650230700148071035[277] = 0;
   out_1650230700148071035[278] = 0;
   out_1650230700148071035[279] = 0;
   out_1650230700148071035[280] = 0;
   out_1650230700148071035[281] = 0;
   out_1650230700148071035[282] = 0;
   out_1650230700148071035[283] = 0;
   out_1650230700148071035[284] = 0;
   out_1650230700148071035[285] = 1;
   out_1650230700148071035[286] = 0;
   out_1650230700148071035[287] = 0;
   out_1650230700148071035[288] = 0;
   out_1650230700148071035[289] = 0;
   out_1650230700148071035[290] = 0;
   out_1650230700148071035[291] = 0;
   out_1650230700148071035[292] = 0;
   out_1650230700148071035[293] = 0;
   out_1650230700148071035[294] = 0;
   out_1650230700148071035[295] = 0;
   out_1650230700148071035[296] = 0;
   out_1650230700148071035[297] = 0;
   out_1650230700148071035[298] = 0;
   out_1650230700148071035[299] = 0;
   out_1650230700148071035[300] = 0;
   out_1650230700148071035[301] = 0;
   out_1650230700148071035[302] = 0;
   out_1650230700148071035[303] = 0;
   out_1650230700148071035[304] = 1;
   out_1650230700148071035[305] = 0;
   out_1650230700148071035[306] = 0;
   out_1650230700148071035[307] = 0;
   out_1650230700148071035[308] = 0;
   out_1650230700148071035[309] = 0;
   out_1650230700148071035[310] = 0;
   out_1650230700148071035[311] = 0;
   out_1650230700148071035[312] = 0;
   out_1650230700148071035[313] = 0;
   out_1650230700148071035[314] = 0;
   out_1650230700148071035[315] = 0;
   out_1650230700148071035[316] = 0;
   out_1650230700148071035[317] = 0;
   out_1650230700148071035[318] = 0;
   out_1650230700148071035[319] = 0;
   out_1650230700148071035[320] = 0;
   out_1650230700148071035[321] = 0;
   out_1650230700148071035[322] = 0;
   out_1650230700148071035[323] = 1;
}
void h_4(double *state, double *unused, double *out_7718420596511956484) {
   out_7718420596511956484[0] = state[6] + state[9];
   out_7718420596511956484[1] = state[7] + state[10];
   out_7718420596511956484[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_9146915311723630973) {
   out_9146915311723630973[0] = 0;
   out_9146915311723630973[1] = 0;
   out_9146915311723630973[2] = 0;
   out_9146915311723630973[3] = 0;
   out_9146915311723630973[4] = 0;
   out_9146915311723630973[5] = 0;
   out_9146915311723630973[6] = 1;
   out_9146915311723630973[7] = 0;
   out_9146915311723630973[8] = 0;
   out_9146915311723630973[9] = 1;
   out_9146915311723630973[10] = 0;
   out_9146915311723630973[11] = 0;
   out_9146915311723630973[12] = 0;
   out_9146915311723630973[13] = 0;
   out_9146915311723630973[14] = 0;
   out_9146915311723630973[15] = 0;
   out_9146915311723630973[16] = 0;
   out_9146915311723630973[17] = 0;
   out_9146915311723630973[18] = 0;
   out_9146915311723630973[19] = 0;
   out_9146915311723630973[20] = 0;
   out_9146915311723630973[21] = 0;
   out_9146915311723630973[22] = 0;
   out_9146915311723630973[23] = 0;
   out_9146915311723630973[24] = 0;
   out_9146915311723630973[25] = 1;
   out_9146915311723630973[26] = 0;
   out_9146915311723630973[27] = 0;
   out_9146915311723630973[28] = 1;
   out_9146915311723630973[29] = 0;
   out_9146915311723630973[30] = 0;
   out_9146915311723630973[31] = 0;
   out_9146915311723630973[32] = 0;
   out_9146915311723630973[33] = 0;
   out_9146915311723630973[34] = 0;
   out_9146915311723630973[35] = 0;
   out_9146915311723630973[36] = 0;
   out_9146915311723630973[37] = 0;
   out_9146915311723630973[38] = 0;
   out_9146915311723630973[39] = 0;
   out_9146915311723630973[40] = 0;
   out_9146915311723630973[41] = 0;
   out_9146915311723630973[42] = 0;
   out_9146915311723630973[43] = 0;
   out_9146915311723630973[44] = 1;
   out_9146915311723630973[45] = 0;
   out_9146915311723630973[46] = 0;
   out_9146915311723630973[47] = 1;
   out_9146915311723630973[48] = 0;
   out_9146915311723630973[49] = 0;
   out_9146915311723630973[50] = 0;
   out_9146915311723630973[51] = 0;
   out_9146915311723630973[52] = 0;
   out_9146915311723630973[53] = 0;
}
void h_10(double *state, double *unused, double *out_5513215277046893653) {
   out_5513215277046893653[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5513215277046893653[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5513215277046893653[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_1077084666490538527) {
   out_1077084666490538527[0] = 0;
   out_1077084666490538527[1] = 9.8100000000000005*cos(state[1]);
   out_1077084666490538527[2] = 0;
   out_1077084666490538527[3] = 0;
   out_1077084666490538527[4] = -state[8];
   out_1077084666490538527[5] = state[7];
   out_1077084666490538527[6] = 0;
   out_1077084666490538527[7] = state[5];
   out_1077084666490538527[8] = -state[4];
   out_1077084666490538527[9] = 0;
   out_1077084666490538527[10] = 0;
   out_1077084666490538527[11] = 0;
   out_1077084666490538527[12] = 1;
   out_1077084666490538527[13] = 0;
   out_1077084666490538527[14] = 0;
   out_1077084666490538527[15] = 1;
   out_1077084666490538527[16] = 0;
   out_1077084666490538527[17] = 0;
   out_1077084666490538527[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_1077084666490538527[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_1077084666490538527[20] = 0;
   out_1077084666490538527[21] = state[8];
   out_1077084666490538527[22] = 0;
   out_1077084666490538527[23] = -state[6];
   out_1077084666490538527[24] = -state[5];
   out_1077084666490538527[25] = 0;
   out_1077084666490538527[26] = state[3];
   out_1077084666490538527[27] = 0;
   out_1077084666490538527[28] = 0;
   out_1077084666490538527[29] = 0;
   out_1077084666490538527[30] = 0;
   out_1077084666490538527[31] = 1;
   out_1077084666490538527[32] = 0;
   out_1077084666490538527[33] = 0;
   out_1077084666490538527[34] = 1;
   out_1077084666490538527[35] = 0;
   out_1077084666490538527[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_1077084666490538527[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_1077084666490538527[38] = 0;
   out_1077084666490538527[39] = -state[7];
   out_1077084666490538527[40] = state[6];
   out_1077084666490538527[41] = 0;
   out_1077084666490538527[42] = state[4];
   out_1077084666490538527[43] = -state[3];
   out_1077084666490538527[44] = 0;
   out_1077084666490538527[45] = 0;
   out_1077084666490538527[46] = 0;
   out_1077084666490538527[47] = 0;
   out_1077084666490538527[48] = 0;
   out_1077084666490538527[49] = 0;
   out_1077084666490538527[50] = 1;
   out_1077084666490538527[51] = 0;
   out_1077084666490538527[52] = 0;
   out_1077084666490538527[53] = 1;
}
void h_13(double *state, double *unused, double *out_399423813345080057) {
   out_399423813345080057[0] = state[3];
   out_399423813345080057[1] = state[4];
   out_399423813345080057[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6087554936653587842) {
   out_6087554936653587842[0] = 0;
   out_6087554936653587842[1] = 0;
   out_6087554936653587842[2] = 0;
   out_6087554936653587842[3] = 1;
   out_6087554936653587842[4] = 0;
   out_6087554936653587842[5] = 0;
   out_6087554936653587842[6] = 0;
   out_6087554936653587842[7] = 0;
   out_6087554936653587842[8] = 0;
   out_6087554936653587842[9] = 0;
   out_6087554936653587842[10] = 0;
   out_6087554936653587842[11] = 0;
   out_6087554936653587842[12] = 0;
   out_6087554936653587842[13] = 0;
   out_6087554936653587842[14] = 0;
   out_6087554936653587842[15] = 0;
   out_6087554936653587842[16] = 0;
   out_6087554936653587842[17] = 0;
   out_6087554936653587842[18] = 0;
   out_6087554936653587842[19] = 0;
   out_6087554936653587842[20] = 0;
   out_6087554936653587842[21] = 0;
   out_6087554936653587842[22] = 1;
   out_6087554936653587842[23] = 0;
   out_6087554936653587842[24] = 0;
   out_6087554936653587842[25] = 0;
   out_6087554936653587842[26] = 0;
   out_6087554936653587842[27] = 0;
   out_6087554936653587842[28] = 0;
   out_6087554936653587842[29] = 0;
   out_6087554936653587842[30] = 0;
   out_6087554936653587842[31] = 0;
   out_6087554936653587842[32] = 0;
   out_6087554936653587842[33] = 0;
   out_6087554936653587842[34] = 0;
   out_6087554936653587842[35] = 0;
   out_6087554936653587842[36] = 0;
   out_6087554936653587842[37] = 0;
   out_6087554936653587842[38] = 0;
   out_6087554936653587842[39] = 0;
   out_6087554936653587842[40] = 0;
   out_6087554936653587842[41] = 1;
   out_6087554936653587842[42] = 0;
   out_6087554936653587842[43] = 0;
   out_6087554936653587842[44] = 0;
   out_6087554936653587842[45] = 0;
   out_6087554936653587842[46] = 0;
   out_6087554936653587842[47] = 0;
   out_6087554936653587842[48] = 0;
   out_6087554936653587842[49] = 0;
   out_6087554936653587842[50] = 0;
   out_6087554936653587842[51] = 0;
   out_6087554936653587842[52] = 0;
   out_6087554936653587842[53] = 0;
}
void h_14(double *state, double *unused, double *out_1933161813507433673) {
   out_1933161813507433673[0] = state[6];
   out_1933161813507433673[1] = state[7];
   out_1933161813507433673[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5336587905646436114) {
   out_5336587905646436114[0] = 0;
   out_5336587905646436114[1] = 0;
   out_5336587905646436114[2] = 0;
   out_5336587905646436114[3] = 0;
   out_5336587905646436114[4] = 0;
   out_5336587905646436114[5] = 0;
   out_5336587905646436114[6] = 1;
   out_5336587905646436114[7] = 0;
   out_5336587905646436114[8] = 0;
   out_5336587905646436114[9] = 0;
   out_5336587905646436114[10] = 0;
   out_5336587905646436114[11] = 0;
   out_5336587905646436114[12] = 0;
   out_5336587905646436114[13] = 0;
   out_5336587905646436114[14] = 0;
   out_5336587905646436114[15] = 0;
   out_5336587905646436114[16] = 0;
   out_5336587905646436114[17] = 0;
   out_5336587905646436114[18] = 0;
   out_5336587905646436114[19] = 0;
   out_5336587905646436114[20] = 0;
   out_5336587905646436114[21] = 0;
   out_5336587905646436114[22] = 0;
   out_5336587905646436114[23] = 0;
   out_5336587905646436114[24] = 0;
   out_5336587905646436114[25] = 1;
   out_5336587905646436114[26] = 0;
   out_5336587905646436114[27] = 0;
   out_5336587905646436114[28] = 0;
   out_5336587905646436114[29] = 0;
   out_5336587905646436114[30] = 0;
   out_5336587905646436114[31] = 0;
   out_5336587905646436114[32] = 0;
   out_5336587905646436114[33] = 0;
   out_5336587905646436114[34] = 0;
   out_5336587905646436114[35] = 0;
   out_5336587905646436114[36] = 0;
   out_5336587905646436114[37] = 0;
   out_5336587905646436114[38] = 0;
   out_5336587905646436114[39] = 0;
   out_5336587905646436114[40] = 0;
   out_5336587905646436114[41] = 0;
   out_5336587905646436114[42] = 0;
   out_5336587905646436114[43] = 0;
   out_5336587905646436114[44] = 1;
   out_5336587905646436114[45] = 0;
   out_5336587905646436114[46] = 0;
   out_5336587905646436114[47] = 0;
   out_5336587905646436114[48] = 0;
   out_5336587905646436114[49] = 0;
   out_5336587905646436114[50] = 0;
   out_5336587905646436114[51] = 0;
   out_5336587905646436114[52] = 0;
   out_5336587905646436114[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3083751291667230086) {
  err_fun(nom_x, delta_x, out_3083751291667230086);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8958923596036680453) {
  inv_err_fun(nom_x, true_x, out_8958923596036680453);
}
void pose_H_mod_fun(double *state, double *out_3451746955233961922) {
  H_mod_fun(state, out_3451746955233961922);
}
void pose_f_fun(double *state, double dt, double *out_9153581491484683214) {
  f_fun(state,  dt, out_9153581491484683214);
}
void pose_F_fun(double *state, double dt, double *out_1650230700148071035) {
  F_fun(state,  dt, out_1650230700148071035);
}
void pose_h_4(double *state, double *unused, double *out_7718420596511956484) {
  h_4(state, unused, out_7718420596511956484);
}
void pose_H_4(double *state, double *unused, double *out_9146915311723630973) {
  H_4(state, unused, out_9146915311723630973);
}
void pose_h_10(double *state, double *unused, double *out_5513215277046893653) {
  h_10(state, unused, out_5513215277046893653);
}
void pose_H_10(double *state, double *unused, double *out_1077084666490538527) {
  H_10(state, unused, out_1077084666490538527);
}
void pose_h_13(double *state, double *unused, double *out_399423813345080057) {
  h_13(state, unused, out_399423813345080057);
}
void pose_H_13(double *state, double *unused, double *out_6087554936653587842) {
  H_13(state, unused, out_6087554936653587842);
}
void pose_h_14(double *state, double *unused, double *out_1933161813507433673) {
  h_14(state, unused, out_1933161813507433673);
}
void pose_H_14(double *state, double *unused, double *out_5336587905646436114) {
  H_14(state, unused, out_5336587905646436114);
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
