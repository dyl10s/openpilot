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
void err_fun(double *nom_x, double *delta_x, double *out_7641933708620610052) {
   out_7641933708620610052[0] = delta_x[0] + nom_x[0];
   out_7641933708620610052[1] = delta_x[1] + nom_x[1];
   out_7641933708620610052[2] = delta_x[2] + nom_x[2];
   out_7641933708620610052[3] = delta_x[3] + nom_x[3];
   out_7641933708620610052[4] = delta_x[4] + nom_x[4];
   out_7641933708620610052[5] = delta_x[5] + nom_x[5];
   out_7641933708620610052[6] = delta_x[6] + nom_x[6];
   out_7641933708620610052[7] = delta_x[7] + nom_x[7];
   out_7641933708620610052[8] = delta_x[8] + nom_x[8];
   out_7641933708620610052[9] = delta_x[9] + nom_x[9];
   out_7641933708620610052[10] = delta_x[10] + nom_x[10];
   out_7641933708620610052[11] = delta_x[11] + nom_x[11];
   out_7641933708620610052[12] = delta_x[12] + nom_x[12];
   out_7641933708620610052[13] = delta_x[13] + nom_x[13];
   out_7641933708620610052[14] = delta_x[14] + nom_x[14];
   out_7641933708620610052[15] = delta_x[15] + nom_x[15];
   out_7641933708620610052[16] = delta_x[16] + nom_x[16];
   out_7641933708620610052[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9128860405088658984) {
   out_9128860405088658984[0] = -nom_x[0] + true_x[0];
   out_9128860405088658984[1] = -nom_x[1] + true_x[1];
   out_9128860405088658984[2] = -nom_x[2] + true_x[2];
   out_9128860405088658984[3] = -nom_x[3] + true_x[3];
   out_9128860405088658984[4] = -nom_x[4] + true_x[4];
   out_9128860405088658984[5] = -nom_x[5] + true_x[5];
   out_9128860405088658984[6] = -nom_x[6] + true_x[6];
   out_9128860405088658984[7] = -nom_x[7] + true_x[7];
   out_9128860405088658984[8] = -nom_x[8] + true_x[8];
   out_9128860405088658984[9] = -nom_x[9] + true_x[9];
   out_9128860405088658984[10] = -nom_x[10] + true_x[10];
   out_9128860405088658984[11] = -nom_x[11] + true_x[11];
   out_9128860405088658984[12] = -nom_x[12] + true_x[12];
   out_9128860405088658984[13] = -nom_x[13] + true_x[13];
   out_9128860405088658984[14] = -nom_x[14] + true_x[14];
   out_9128860405088658984[15] = -nom_x[15] + true_x[15];
   out_9128860405088658984[16] = -nom_x[16] + true_x[16];
   out_9128860405088658984[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3103725176518788441) {
   out_3103725176518788441[0] = 1.0;
   out_3103725176518788441[1] = 0.0;
   out_3103725176518788441[2] = 0.0;
   out_3103725176518788441[3] = 0.0;
   out_3103725176518788441[4] = 0.0;
   out_3103725176518788441[5] = 0.0;
   out_3103725176518788441[6] = 0.0;
   out_3103725176518788441[7] = 0.0;
   out_3103725176518788441[8] = 0.0;
   out_3103725176518788441[9] = 0.0;
   out_3103725176518788441[10] = 0.0;
   out_3103725176518788441[11] = 0.0;
   out_3103725176518788441[12] = 0.0;
   out_3103725176518788441[13] = 0.0;
   out_3103725176518788441[14] = 0.0;
   out_3103725176518788441[15] = 0.0;
   out_3103725176518788441[16] = 0.0;
   out_3103725176518788441[17] = 0.0;
   out_3103725176518788441[18] = 0.0;
   out_3103725176518788441[19] = 1.0;
   out_3103725176518788441[20] = 0.0;
   out_3103725176518788441[21] = 0.0;
   out_3103725176518788441[22] = 0.0;
   out_3103725176518788441[23] = 0.0;
   out_3103725176518788441[24] = 0.0;
   out_3103725176518788441[25] = 0.0;
   out_3103725176518788441[26] = 0.0;
   out_3103725176518788441[27] = 0.0;
   out_3103725176518788441[28] = 0.0;
   out_3103725176518788441[29] = 0.0;
   out_3103725176518788441[30] = 0.0;
   out_3103725176518788441[31] = 0.0;
   out_3103725176518788441[32] = 0.0;
   out_3103725176518788441[33] = 0.0;
   out_3103725176518788441[34] = 0.0;
   out_3103725176518788441[35] = 0.0;
   out_3103725176518788441[36] = 0.0;
   out_3103725176518788441[37] = 0.0;
   out_3103725176518788441[38] = 1.0;
   out_3103725176518788441[39] = 0.0;
   out_3103725176518788441[40] = 0.0;
   out_3103725176518788441[41] = 0.0;
   out_3103725176518788441[42] = 0.0;
   out_3103725176518788441[43] = 0.0;
   out_3103725176518788441[44] = 0.0;
   out_3103725176518788441[45] = 0.0;
   out_3103725176518788441[46] = 0.0;
   out_3103725176518788441[47] = 0.0;
   out_3103725176518788441[48] = 0.0;
   out_3103725176518788441[49] = 0.0;
   out_3103725176518788441[50] = 0.0;
   out_3103725176518788441[51] = 0.0;
   out_3103725176518788441[52] = 0.0;
   out_3103725176518788441[53] = 0.0;
   out_3103725176518788441[54] = 0.0;
   out_3103725176518788441[55] = 0.0;
   out_3103725176518788441[56] = 0.0;
   out_3103725176518788441[57] = 1.0;
   out_3103725176518788441[58] = 0.0;
   out_3103725176518788441[59] = 0.0;
   out_3103725176518788441[60] = 0.0;
   out_3103725176518788441[61] = 0.0;
   out_3103725176518788441[62] = 0.0;
   out_3103725176518788441[63] = 0.0;
   out_3103725176518788441[64] = 0.0;
   out_3103725176518788441[65] = 0.0;
   out_3103725176518788441[66] = 0.0;
   out_3103725176518788441[67] = 0.0;
   out_3103725176518788441[68] = 0.0;
   out_3103725176518788441[69] = 0.0;
   out_3103725176518788441[70] = 0.0;
   out_3103725176518788441[71] = 0.0;
   out_3103725176518788441[72] = 0.0;
   out_3103725176518788441[73] = 0.0;
   out_3103725176518788441[74] = 0.0;
   out_3103725176518788441[75] = 0.0;
   out_3103725176518788441[76] = 1.0;
   out_3103725176518788441[77] = 0.0;
   out_3103725176518788441[78] = 0.0;
   out_3103725176518788441[79] = 0.0;
   out_3103725176518788441[80] = 0.0;
   out_3103725176518788441[81] = 0.0;
   out_3103725176518788441[82] = 0.0;
   out_3103725176518788441[83] = 0.0;
   out_3103725176518788441[84] = 0.0;
   out_3103725176518788441[85] = 0.0;
   out_3103725176518788441[86] = 0.0;
   out_3103725176518788441[87] = 0.0;
   out_3103725176518788441[88] = 0.0;
   out_3103725176518788441[89] = 0.0;
   out_3103725176518788441[90] = 0.0;
   out_3103725176518788441[91] = 0.0;
   out_3103725176518788441[92] = 0.0;
   out_3103725176518788441[93] = 0.0;
   out_3103725176518788441[94] = 0.0;
   out_3103725176518788441[95] = 1.0;
   out_3103725176518788441[96] = 0.0;
   out_3103725176518788441[97] = 0.0;
   out_3103725176518788441[98] = 0.0;
   out_3103725176518788441[99] = 0.0;
   out_3103725176518788441[100] = 0.0;
   out_3103725176518788441[101] = 0.0;
   out_3103725176518788441[102] = 0.0;
   out_3103725176518788441[103] = 0.0;
   out_3103725176518788441[104] = 0.0;
   out_3103725176518788441[105] = 0.0;
   out_3103725176518788441[106] = 0.0;
   out_3103725176518788441[107] = 0.0;
   out_3103725176518788441[108] = 0.0;
   out_3103725176518788441[109] = 0.0;
   out_3103725176518788441[110] = 0.0;
   out_3103725176518788441[111] = 0.0;
   out_3103725176518788441[112] = 0.0;
   out_3103725176518788441[113] = 0.0;
   out_3103725176518788441[114] = 1.0;
   out_3103725176518788441[115] = 0.0;
   out_3103725176518788441[116] = 0.0;
   out_3103725176518788441[117] = 0.0;
   out_3103725176518788441[118] = 0.0;
   out_3103725176518788441[119] = 0.0;
   out_3103725176518788441[120] = 0.0;
   out_3103725176518788441[121] = 0.0;
   out_3103725176518788441[122] = 0.0;
   out_3103725176518788441[123] = 0.0;
   out_3103725176518788441[124] = 0.0;
   out_3103725176518788441[125] = 0.0;
   out_3103725176518788441[126] = 0.0;
   out_3103725176518788441[127] = 0.0;
   out_3103725176518788441[128] = 0.0;
   out_3103725176518788441[129] = 0.0;
   out_3103725176518788441[130] = 0.0;
   out_3103725176518788441[131] = 0.0;
   out_3103725176518788441[132] = 0.0;
   out_3103725176518788441[133] = 1.0;
   out_3103725176518788441[134] = 0.0;
   out_3103725176518788441[135] = 0.0;
   out_3103725176518788441[136] = 0.0;
   out_3103725176518788441[137] = 0.0;
   out_3103725176518788441[138] = 0.0;
   out_3103725176518788441[139] = 0.0;
   out_3103725176518788441[140] = 0.0;
   out_3103725176518788441[141] = 0.0;
   out_3103725176518788441[142] = 0.0;
   out_3103725176518788441[143] = 0.0;
   out_3103725176518788441[144] = 0.0;
   out_3103725176518788441[145] = 0.0;
   out_3103725176518788441[146] = 0.0;
   out_3103725176518788441[147] = 0.0;
   out_3103725176518788441[148] = 0.0;
   out_3103725176518788441[149] = 0.0;
   out_3103725176518788441[150] = 0.0;
   out_3103725176518788441[151] = 0.0;
   out_3103725176518788441[152] = 1.0;
   out_3103725176518788441[153] = 0.0;
   out_3103725176518788441[154] = 0.0;
   out_3103725176518788441[155] = 0.0;
   out_3103725176518788441[156] = 0.0;
   out_3103725176518788441[157] = 0.0;
   out_3103725176518788441[158] = 0.0;
   out_3103725176518788441[159] = 0.0;
   out_3103725176518788441[160] = 0.0;
   out_3103725176518788441[161] = 0.0;
   out_3103725176518788441[162] = 0.0;
   out_3103725176518788441[163] = 0.0;
   out_3103725176518788441[164] = 0.0;
   out_3103725176518788441[165] = 0.0;
   out_3103725176518788441[166] = 0.0;
   out_3103725176518788441[167] = 0.0;
   out_3103725176518788441[168] = 0.0;
   out_3103725176518788441[169] = 0.0;
   out_3103725176518788441[170] = 0.0;
   out_3103725176518788441[171] = 1.0;
   out_3103725176518788441[172] = 0.0;
   out_3103725176518788441[173] = 0.0;
   out_3103725176518788441[174] = 0.0;
   out_3103725176518788441[175] = 0.0;
   out_3103725176518788441[176] = 0.0;
   out_3103725176518788441[177] = 0.0;
   out_3103725176518788441[178] = 0.0;
   out_3103725176518788441[179] = 0.0;
   out_3103725176518788441[180] = 0.0;
   out_3103725176518788441[181] = 0.0;
   out_3103725176518788441[182] = 0.0;
   out_3103725176518788441[183] = 0.0;
   out_3103725176518788441[184] = 0.0;
   out_3103725176518788441[185] = 0.0;
   out_3103725176518788441[186] = 0.0;
   out_3103725176518788441[187] = 0.0;
   out_3103725176518788441[188] = 0.0;
   out_3103725176518788441[189] = 0.0;
   out_3103725176518788441[190] = 1.0;
   out_3103725176518788441[191] = 0.0;
   out_3103725176518788441[192] = 0.0;
   out_3103725176518788441[193] = 0.0;
   out_3103725176518788441[194] = 0.0;
   out_3103725176518788441[195] = 0.0;
   out_3103725176518788441[196] = 0.0;
   out_3103725176518788441[197] = 0.0;
   out_3103725176518788441[198] = 0.0;
   out_3103725176518788441[199] = 0.0;
   out_3103725176518788441[200] = 0.0;
   out_3103725176518788441[201] = 0.0;
   out_3103725176518788441[202] = 0.0;
   out_3103725176518788441[203] = 0.0;
   out_3103725176518788441[204] = 0.0;
   out_3103725176518788441[205] = 0.0;
   out_3103725176518788441[206] = 0.0;
   out_3103725176518788441[207] = 0.0;
   out_3103725176518788441[208] = 0.0;
   out_3103725176518788441[209] = 1.0;
   out_3103725176518788441[210] = 0.0;
   out_3103725176518788441[211] = 0.0;
   out_3103725176518788441[212] = 0.0;
   out_3103725176518788441[213] = 0.0;
   out_3103725176518788441[214] = 0.0;
   out_3103725176518788441[215] = 0.0;
   out_3103725176518788441[216] = 0.0;
   out_3103725176518788441[217] = 0.0;
   out_3103725176518788441[218] = 0.0;
   out_3103725176518788441[219] = 0.0;
   out_3103725176518788441[220] = 0.0;
   out_3103725176518788441[221] = 0.0;
   out_3103725176518788441[222] = 0.0;
   out_3103725176518788441[223] = 0.0;
   out_3103725176518788441[224] = 0.0;
   out_3103725176518788441[225] = 0.0;
   out_3103725176518788441[226] = 0.0;
   out_3103725176518788441[227] = 0.0;
   out_3103725176518788441[228] = 1.0;
   out_3103725176518788441[229] = 0.0;
   out_3103725176518788441[230] = 0.0;
   out_3103725176518788441[231] = 0.0;
   out_3103725176518788441[232] = 0.0;
   out_3103725176518788441[233] = 0.0;
   out_3103725176518788441[234] = 0.0;
   out_3103725176518788441[235] = 0.0;
   out_3103725176518788441[236] = 0.0;
   out_3103725176518788441[237] = 0.0;
   out_3103725176518788441[238] = 0.0;
   out_3103725176518788441[239] = 0.0;
   out_3103725176518788441[240] = 0.0;
   out_3103725176518788441[241] = 0.0;
   out_3103725176518788441[242] = 0.0;
   out_3103725176518788441[243] = 0.0;
   out_3103725176518788441[244] = 0.0;
   out_3103725176518788441[245] = 0.0;
   out_3103725176518788441[246] = 0.0;
   out_3103725176518788441[247] = 1.0;
   out_3103725176518788441[248] = 0.0;
   out_3103725176518788441[249] = 0.0;
   out_3103725176518788441[250] = 0.0;
   out_3103725176518788441[251] = 0.0;
   out_3103725176518788441[252] = 0.0;
   out_3103725176518788441[253] = 0.0;
   out_3103725176518788441[254] = 0.0;
   out_3103725176518788441[255] = 0.0;
   out_3103725176518788441[256] = 0.0;
   out_3103725176518788441[257] = 0.0;
   out_3103725176518788441[258] = 0.0;
   out_3103725176518788441[259] = 0.0;
   out_3103725176518788441[260] = 0.0;
   out_3103725176518788441[261] = 0.0;
   out_3103725176518788441[262] = 0.0;
   out_3103725176518788441[263] = 0.0;
   out_3103725176518788441[264] = 0.0;
   out_3103725176518788441[265] = 0.0;
   out_3103725176518788441[266] = 1.0;
   out_3103725176518788441[267] = 0.0;
   out_3103725176518788441[268] = 0.0;
   out_3103725176518788441[269] = 0.0;
   out_3103725176518788441[270] = 0.0;
   out_3103725176518788441[271] = 0.0;
   out_3103725176518788441[272] = 0.0;
   out_3103725176518788441[273] = 0.0;
   out_3103725176518788441[274] = 0.0;
   out_3103725176518788441[275] = 0.0;
   out_3103725176518788441[276] = 0.0;
   out_3103725176518788441[277] = 0.0;
   out_3103725176518788441[278] = 0.0;
   out_3103725176518788441[279] = 0.0;
   out_3103725176518788441[280] = 0.0;
   out_3103725176518788441[281] = 0.0;
   out_3103725176518788441[282] = 0.0;
   out_3103725176518788441[283] = 0.0;
   out_3103725176518788441[284] = 0.0;
   out_3103725176518788441[285] = 1.0;
   out_3103725176518788441[286] = 0.0;
   out_3103725176518788441[287] = 0.0;
   out_3103725176518788441[288] = 0.0;
   out_3103725176518788441[289] = 0.0;
   out_3103725176518788441[290] = 0.0;
   out_3103725176518788441[291] = 0.0;
   out_3103725176518788441[292] = 0.0;
   out_3103725176518788441[293] = 0.0;
   out_3103725176518788441[294] = 0.0;
   out_3103725176518788441[295] = 0.0;
   out_3103725176518788441[296] = 0.0;
   out_3103725176518788441[297] = 0.0;
   out_3103725176518788441[298] = 0.0;
   out_3103725176518788441[299] = 0.0;
   out_3103725176518788441[300] = 0.0;
   out_3103725176518788441[301] = 0.0;
   out_3103725176518788441[302] = 0.0;
   out_3103725176518788441[303] = 0.0;
   out_3103725176518788441[304] = 1.0;
   out_3103725176518788441[305] = 0.0;
   out_3103725176518788441[306] = 0.0;
   out_3103725176518788441[307] = 0.0;
   out_3103725176518788441[308] = 0.0;
   out_3103725176518788441[309] = 0.0;
   out_3103725176518788441[310] = 0.0;
   out_3103725176518788441[311] = 0.0;
   out_3103725176518788441[312] = 0.0;
   out_3103725176518788441[313] = 0.0;
   out_3103725176518788441[314] = 0.0;
   out_3103725176518788441[315] = 0.0;
   out_3103725176518788441[316] = 0.0;
   out_3103725176518788441[317] = 0.0;
   out_3103725176518788441[318] = 0.0;
   out_3103725176518788441[319] = 0.0;
   out_3103725176518788441[320] = 0.0;
   out_3103725176518788441[321] = 0.0;
   out_3103725176518788441[322] = 0.0;
   out_3103725176518788441[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5259001848744899041) {
   out_5259001848744899041[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5259001848744899041[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5259001848744899041[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5259001848744899041[3] = dt*state[12] + state[3];
   out_5259001848744899041[4] = dt*state[13] + state[4];
   out_5259001848744899041[5] = dt*state[14] + state[5];
   out_5259001848744899041[6] = state[6];
   out_5259001848744899041[7] = state[7];
   out_5259001848744899041[8] = state[8];
   out_5259001848744899041[9] = state[9];
   out_5259001848744899041[10] = state[10];
   out_5259001848744899041[11] = state[11];
   out_5259001848744899041[12] = state[12];
   out_5259001848744899041[13] = state[13];
   out_5259001848744899041[14] = state[14];
   out_5259001848744899041[15] = state[15];
   out_5259001848744899041[16] = state[16];
   out_5259001848744899041[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6765250644485775616) {
   out_6765250644485775616[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6765250644485775616[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6765250644485775616[2] = 0;
   out_6765250644485775616[3] = 0;
   out_6765250644485775616[4] = 0;
   out_6765250644485775616[5] = 0;
   out_6765250644485775616[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6765250644485775616[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6765250644485775616[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6765250644485775616[9] = 0;
   out_6765250644485775616[10] = 0;
   out_6765250644485775616[11] = 0;
   out_6765250644485775616[12] = 0;
   out_6765250644485775616[13] = 0;
   out_6765250644485775616[14] = 0;
   out_6765250644485775616[15] = 0;
   out_6765250644485775616[16] = 0;
   out_6765250644485775616[17] = 0;
   out_6765250644485775616[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6765250644485775616[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6765250644485775616[20] = 0;
   out_6765250644485775616[21] = 0;
   out_6765250644485775616[22] = 0;
   out_6765250644485775616[23] = 0;
   out_6765250644485775616[24] = 0;
   out_6765250644485775616[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6765250644485775616[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6765250644485775616[27] = 0;
   out_6765250644485775616[28] = 0;
   out_6765250644485775616[29] = 0;
   out_6765250644485775616[30] = 0;
   out_6765250644485775616[31] = 0;
   out_6765250644485775616[32] = 0;
   out_6765250644485775616[33] = 0;
   out_6765250644485775616[34] = 0;
   out_6765250644485775616[35] = 0;
   out_6765250644485775616[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6765250644485775616[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6765250644485775616[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6765250644485775616[39] = 0;
   out_6765250644485775616[40] = 0;
   out_6765250644485775616[41] = 0;
   out_6765250644485775616[42] = 0;
   out_6765250644485775616[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6765250644485775616[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6765250644485775616[45] = 0;
   out_6765250644485775616[46] = 0;
   out_6765250644485775616[47] = 0;
   out_6765250644485775616[48] = 0;
   out_6765250644485775616[49] = 0;
   out_6765250644485775616[50] = 0;
   out_6765250644485775616[51] = 0;
   out_6765250644485775616[52] = 0;
   out_6765250644485775616[53] = 0;
   out_6765250644485775616[54] = 0;
   out_6765250644485775616[55] = 0;
   out_6765250644485775616[56] = 0;
   out_6765250644485775616[57] = 1;
   out_6765250644485775616[58] = 0;
   out_6765250644485775616[59] = 0;
   out_6765250644485775616[60] = 0;
   out_6765250644485775616[61] = 0;
   out_6765250644485775616[62] = 0;
   out_6765250644485775616[63] = 0;
   out_6765250644485775616[64] = 0;
   out_6765250644485775616[65] = 0;
   out_6765250644485775616[66] = dt;
   out_6765250644485775616[67] = 0;
   out_6765250644485775616[68] = 0;
   out_6765250644485775616[69] = 0;
   out_6765250644485775616[70] = 0;
   out_6765250644485775616[71] = 0;
   out_6765250644485775616[72] = 0;
   out_6765250644485775616[73] = 0;
   out_6765250644485775616[74] = 0;
   out_6765250644485775616[75] = 0;
   out_6765250644485775616[76] = 1;
   out_6765250644485775616[77] = 0;
   out_6765250644485775616[78] = 0;
   out_6765250644485775616[79] = 0;
   out_6765250644485775616[80] = 0;
   out_6765250644485775616[81] = 0;
   out_6765250644485775616[82] = 0;
   out_6765250644485775616[83] = 0;
   out_6765250644485775616[84] = 0;
   out_6765250644485775616[85] = dt;
   out_6765250644485775616[86] = 0;
   out_6765250644485775616[87] = 0;
   out_6765250644485775616[88] = 0;
   out_6765250644485775616[89] = 0;
   out_6765250644485775616[90] = 0;
   out_6765250644485775616[91] = 0;
   out_6765250644485775616[92] = 0;
   out_6765250644485775616[93] = 0;
   out_6765250644485775616[94] = 0;
   out_6765250644485775616[95] = 1;
   out_6765250644485775616[96] = 0;
   out_6765250644485775616[97] = 0;
   out_6765250644485775616[98] = 0;
   out_6765250644485775616[99] = 0;
   out_6765250644485775616[100] = 0;
   out_6765250644485775616[101] = 0;
   out_6765250644485775616[102] = 0;
   out_6765250644485775616[103] = 0;
   out_6765250644485775616[104] = dt;
   out_6765250644485775616[105] = 0;
   out_6765250644485775616[106] = 0;
   out_6765250644485775616[107] = 0;
   out_6765250644485775616[108] = 0;
   out_6765250644485775616[109] = 0;
   out_6765250644485775616[110] = 0;
   out_6765250644485775616[111] = 0;
   out_6765250644485775616[112] = 0;
   out_6765250644485775616[113] = 0;
   out_6765250644485775616[114] = 1;
   out_6765250644485775616[115] = 0;
   out_6765250644485775616[116] = 0;
   out_6765250644485775616[117] = 0;
   out_6765250644485775616[118] = 0;
   out_6765250644485775616[119] = 0;
   out_6765250644485775616[120] = 0;
   out_6765250644485775616[121] = 0;
   out_6765250644485775616[122] = 0;
   out_6765250644485775616[123] = 0;
   out_6765250644485775616[124] = 0;
   out_6765250644485775616[125] = 0;
   out_6765250644485775616[126] = 0;
   out_6765250644485775616[127] = 0;
   out_6765250644485775616[128] = 0;
   out_6765250644485775616[129] = 0;
   out_6765250644485775616[130] = 0;
   out_6765250644485775616[131] = 0;
   out_6765250644485775616[132] = 0;
   out_6765250644485775616[133] = 1;
   out_6765250644485775616[134] = 0;
   out_6765250644485775616[135] = 0;
   out_6765250644485775616[136] = 0;
   out_6765250644485775616[137] = 0;
   out_6765250644485775616[138] = 0;
   out_6765250644485775616[139] = 0;
   out_6765250644485775616[140] = 0;
   out_6765250644485775616[141] = 0;
   out_6765250644485775616[142] = 0;
   out_6765250644485775616[143] = 0;
   out_6765250644485775616[144] = 0;
   out_6765250644485775616[145] = 0;
   out_6765250644485775616[146] = 0;
   out_6765250644485775616[147] = 0;
   out_6765250644485775616[148] = 0;
   out_6765250644485775616[149] = 0;
   out_6765250644485775616[150] = 0;
   out_6765250644485775616[151] = 0;
   out_6765250644485775616[152] = 1;
   out_6765250644485775616[153] = 0;
   out_6765250644485775616[154] = 0;
   out_6765250644485775616[155] = 0;
   out_6765250644485775616[156] = 0;
   out_6765250644485775616[157] = 0;
   out_6765250644485775616[158] = 0;
   out_6765250644485775616[159] = 0;
   out_6765250644485775616[160] = 0;
   out_6765250644485775616[161] = 0;
   out_6765250644485775616[162] = 0;
   out_6765250644485775616[163] = 0;
   out_6765250644485775616[164] = 0;
   out_6765250644485775616[165] = 0;
   out_6765250644485775616[166] = 0;
   out_6765250644485775616[167] = 0;
   out_6765250644485775616[168] = 0;
   out_6765250644485775616[169] = 0;
   out_6765250644485775616[170] = 0;
   out_6765250644485775616[171] = 1;
   out_6765250644485775616[172] = 0;
   out_6765250644485775616[173] = 0;
   out_6765250644485775616[174] = 0;
   out_6765250644485775616[175] = 0;
   out_6765250644485775616[176] = 0;
   out_6765250644485775616[177] = 0;
   out_6765250644485775616[178] = 0;
   out_6765250644485775616[179] = 0;
   out_6765250644485775616[180] = 0;
   out_6765250644485775616[181] = 0;
   out_6765250644485775616[182] = 0;
   out_6765250644485775616[183] = 0;
   out_6765250644485775616[184] = 0;
   out_6765250644485775616[185] = 0;
   out_6765250644485775616[186] = 0;
   out_6765250644485775616[187] = 0;
   out_6765250644485775616[188] = 0;
   out_6765250644485775616[189] = 0;
   out_6765250644485775616[190] = 1;
   out_6765250644485775616[191] = 0;
   out_6765250644485775616[192] = 0;
   out_6765250644485775616[193] = 0;
   out_6765250644485775616[194] = 0;
   out_6765250644485775616[195] = 0;
   out_6765250644485775616[196] = 0;
   out_6765250644485775616[197] = 0;
   out_6765250644485775616[198] = 0;
   out_6765250644485775616[199] = 0;
   out_6765250644485775616[200] = 0;
   out_6765250644485775616[201] = 0;
   out_6765250644485775616[202] = 0;
   out_6765250644485775616[203] = 0;
   out_6765250644485775616[204] = 0;
   out_6765250644485775616[205] = 0;
   out_6765250644485775616[206] = 0;
   out_6765250644485775616[207] = 0;
   out_6765250644485775616[208] = 0;
   out_6765250644485775616[209] = 1;
   out_6765250644485775616[210] = 0;
   out_6765250644485775616[211] = 0;
   out_6765250644485775616[212] = 0;
   out_6765250644485775616[213] = 0;
   out_6765250644485775616[214] = 0;
   out_6765250644485775616[215] = 0;
   out_6765250644485775616[216] = 0;
   out_6765250644485775616[217] = 0;
   out_6765250644485775616[218] = 0;
   out_6765250644485775616[219] = 0;
   out_6765250644485775616[220] = 0;
   out_6765250644485775616[221] = 0;
   out_6765250644485775616[222] = 0;
   out_6765250644485775616[223] = 0;
   out_6765250644485775616[224] = 0;
   out_6765250644485775616[225] = 0;
   out_6765250644485775616[226] = 0;
   out_6765250644485775616[227] = 0;
   out_6765250644485775616[228] = 1;
   out_6765250644485775616[229] = 0;
   out_6765250644485775616[230] = 0;
   out_6765250644485775616[231] = 0;
   out_6765250644485775616[232] = 0;
   out_6765250644485775616[233] = 0;
   out_6765250644485775616[234] = 0;
   out_6765250644485775616[235] = 0;
   out_6765250644485775616[236] = 0;
   out_6765250644485775616[237] = 0;
   out_6765250644485775616[238] = 0;
   out_6765250644485775616[239] = 0;
   out_6765250644485775616[240] = 0;
   out_6765250644485775616[241] = 0;
   out_6765250644485775616[242] = 0;
   out_6765250644485775616[243] = 0;
   out_6765250644485775616[244] = 0;
   out_6765250644485775616[245] = 0;
   out_6765250644485775616[246] = 0;
   out_6765250644485775616[247] = 1;
   out_6765250644485775616[248] = 0;
   out_6765250644485775616[249] = 0;
   out_6765250644485775616[250] = 0;
   out_6765250644485775616[251] = 0;
   out_6765250644485775616[252] = 0;
   out_6765250644485775616[253] = 0;
   out_6765250644485775616[254] = 0;
   out_6765250644485775616[255] = 0;
   out_6765250644485775616[256] = 0;
   out_6765250644485775616[257] = 0;
   out_6765250644485775616[258] = 0;
   out_6765250644485775616[259] = 0;
   out_6765250644485775616[260] = 0;
   out_6765250644485775616[261] = 0;
   out_6765250644485775616[262] = 0;
   out_6765250644485775616[263] = 0;
   out_6765250644485775616[264] = 0;
   out_6765250644485775616[265] = 0;
   out_6765250644485775616[266] = 1;
   out_6765250644485775616[267] = 0;
   out_6765250644485775616[268] = 0;
   out_6765250644485775616[269] = 0;
   out_6765250644485775616[270] = 0;
   out_6765250644485775616[271] = 0;
   out_6765250644485775616[272] = 0;
   out_6765250644485775616[273] = 0;
   out_6765250644485775616[274] = 0;
   out_6765250644485775616[275] = 0;
   out_6765250644485775616[276] = 0;
   out_6765250644485775616[277] = 0;
   out_6765250644485775616[278] = 0;
   out_6765250644485775616[279] = 0;
   out_6765250644485775616[280] = 0;
   out_6765250644485775616[281] = 0;
   out_6765250644485775616[282] = 0;
   out_6765250644485775616[283] = 0;
   out_6765250644485775616[284] = 0;
   out_6765250644485775616[285] = 1;
   out_6765250644485775616[286] = 0;
   out_6765250644485775616[287] = 0;
   out_6765250644485775616[288] = 0;
   out_6765250644485775616[289] = 0;
   out_6765250644485775616[290] = 0;
   out_6765250644485775616[291] = 0;
   out_6765250644485775616[292] = 0;
   out_6765250644485775616[293] = 0;
   out_6765250644485775616[294] = 0;
   out_6765250644485775616[295] = 0;
   out_6765250644485775616[296] = 0;
   out_6765250644485775616[297] = 0;
   out_6765250644485775616[298] = 0;
   out_6765250644485775616[299] = 0;
   out_6765250644485775616[300] = 0;
   out_6765250644485775616[301] = 0;
   out_6765250644485775616[302] = 0;
   out_6765250644485775616[303] = 0;
   out_6765250644485775616[304] = 1;
   out_6765250644485775616[305] = 0;
   out_6765250644485775616[306] = 0;
   out_6765250644485775616[307] = 0;
   out_6765250644485775616[308] = 0;
   out_6765250644485775616[309] = 0;
   out_6765250644485775616[310] = 0;
   out_6765250644485775616[311] = 0;
   out_6765250644485775616[312] = 0;
   out_6765250644485775616[313] = 0;
   out_6765250644485775616[314] = 0;
   out_6765250644485775616[315] = 0;
   out_6765250644485775616[316] = 0;
   out_6765250644485775616[317] = 0;
   out_6765250644485775616[318] = 0;
   out_6765250644485775616[319] = 0;
   out_6765250644485775616[320] = 0;
   out_6765250644485775616[321] = 0;
   out_6765250644485775616[322] = 0;
   out_6765250644485775616[323] = 1;
}
void h_4(double *state, double *unused, double *out_6349780411594345580) {
   out_6349780411594345580[0] = state[6] + state[9];
   out_6349780411594345580[1] = state[7] + state[10];
   out_6349780411594345580[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4301672658401686545) {
   out_4301672658401686545[0] = 0;
   out_4301672658401686545[1] = 0;
   out_4301672658401686545[2] = 0;
   out_4301672658401686545[3] = 0;
   out_4301672658401686545[4] = 0;
   out_4301672658401686545[5] = 0;
   out_4301672658401686545[6] = 1;
   out_4301672658401686545[7] = 0;
   out_4301672658401686545[8] = 0;
   out_4301672658401686545[9] = 1;
   out_4301672658401686545[10] = 0;
   out_4301672658401686545[11] = 0;
   out_4301672658401686545[12] = 0;
   out_4301672658401686545[13] = 0;
   out_4301672658401686545[14] = 0;
   out_4301672658401686545[15] = 0;
   out_4301672658401686545[16] = 0;
   out_4301672658401686545[17] = 0;
   out_4301672658401686545[18] = 0;
   out_4301672658401686545[19] = 0;
   out_4301672658401686545[20] = 0;
   out_4301672658401686545[21] = 0;
   out_4301672658401686545[22] = 0;
   out_4301672658401686545[23] = 0;
   out_4301672658401686545[24] = 0;
   out_4301672658401686545[25] = 1;
   out_4301672658401686545[26] = 0;
   out_4301672658401686545[27] = 0;
   out_4301672658401686545[28] = 1;
   out_4301672658401686545[29] = 0;
   out_4301672658401686545[30] = 0;
   out_4301672658401686545[31] = 0;
   out_4301672658401686545[32] = 0;
   out_4301672658401686545[33] = 0;
   out_4301672658401686545[34] = 0;
   out_4301672658401686545[35] = 0;
   out_4301672658401686545[36] = 0;
   out_4301672658401686545[37] = 0;
   out_4301672658401686545[38] = 0;
   out_4301672658401686545[39] = 0;
   out_4301672658401686545[40] = 0;
   out_4301672658401686545[41] = 0;
   out_4301672658401686545[42] = 0;
   out_4301672658401686545[43] = 0;
   out_4301672658401686545[44] = 1;
   out_4301672658401686545[45] = 0;
   out_4301672658401686545[46] = 0;
   out_4301672658401686545[47] = 1;
   out_4301672658401686545[48] = 0;
   out_4301672658401686545[49] = 0;
   out_4301672658401686545[50] = 0;
   out_4301672658401686545[51] = 0;
   out_4301672658401686545[52] = 0;
   out_4301672658401686545[53] = 0;
}
void h_10(double *state, double *unused, double *out_1522297241205058892) {
   out_1522297241205058892[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1522297241205058892[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1522297241205058892[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2231099772160491337) {
   out_2231099772160491337[0] = 0;
   out_2231099772160491337[1] = 9.8100000000000005*cos(state[1]);
   out_2231099772160491337[2] = 0;
   out_2231099772160491337[3] = 0;
   out_2231099772160491337[4] = -state[8];
   out_2231099772160491337[5] = state[7];
   out_2231099772160491337[6] = 0;
   out_2231099772160491337[7] = state[5];
   out_2231099772160491337[8] = -state[4];
   out_2231099772160491337[9] = 0;
   out_2231099772160491337[10] = 0;
   out_2231099772160491337[11] = 0;
   out_2231099772160491337[12] = 1;
   out_2231099772160491337[13] = 0;
   out_2231099772160491337[14] = 0;
   out_2231099772160491337[15] = 1;
   out_2231099772160491337[16] = 0;
   out_2231099772160491337[17] = 0;
   out_2231099772160491337[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2231099772160491337[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2231099772160491337[20] = 0;
   out_2231099772160491337[21] = state[8];
   out_2231099772160491337[22] = 0;
   out_2231099772160491337[23] = -state[6];
   out_2231099772160491337[24] = -state[5];
   out_2231099772160491337[25] = 0;
   out_2231099772160491337[26] = state[3];
   out_2231099772160491337[27] = 0;
   out_2231099772160491337[28] = 0;
   out_2231099772160491337[29] = 0;
   out_2231099772160491337[30] = 0;
   out_2231099772160491337[31] = 1;
   out_2231099772160491337[32] = 0;
   out_2231099772160491337[33] = 0;
   out_2231099772160491337[34] = 1;
   out_2231099772160491337[35] = 0;
   out_2231099772160491337[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2231099772160491337[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2231099772160491337[38] = 0;
   out_2231099772160491337[39] = -state[7];
   out_2231099772160491337[40] = state[6];
   out_2231099772160491337[41] = 0;
   out_2231099772160491337[42] = state[4];
   out_2231099772160491337[43] = -state[3];
   out_2231099772160491337[44] = 0;
   out_2231099772160491337[45] = 0;
   out_2231099772160491337[46] = 0;
   out_2231099772160491337[47] = 0;
   out_2231099772160491337[48] = 0;
   out_2231099772160491337[49] = 0;
   out_2231099772160491337[50] = 1;
   out_2231099772160491337[51] = 0;
   out_2231099772160491337[52] = 0;
   out_2231099772160491337[53] = 1;
}
void h_13(double *state, double *unused, double *out_9186389196897638740) {
   out_9186389196897638740[0] = state[3];
   out_9186389196897638740[1] = state[4];
   out_9186389196897638740[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7513946483734019346) {
   out_7513946483734019346[0] = 0;
   out_7513946483734019346[1] = 0;
   out_7513946483734019346[2] = 0;
   out_7513946483734019346[3] = 1;
   out_7513946483734019346[4] = 0;
   out_7513946483734019346[5] = 0;
   out_7513946483734019346[6] = 0;
   out_7513946483734019346[7] = 0;
   out_7513946483734019346[8] = 0;
   out_7513946483734019346[9] = 0;
   out_7513946483734019346[10] = 0;
   out_7513946483734019346[11] = 0;
   out_7513946483734019346[12] = 0;
   out_7513946483734019346[13] = 0;
   out_7513946483734019346[14] = 0;
   out_7513946483734019346[15] = 0;
   out_7513946483734019346[16] = 0;
   out_7513946483734019346[17] = 0;
   out_7513946483734019346[18] = 0;
   out_7513946483734019346[19] = 0;
   out_7513946483734019346[20] = 0;
   out_7513946483734019346[21] = 0;
   out_7513946483734019346[22] = 1;
   out_7513946483734019346[23] = 0;
   out_7513946483734019346[24] = 0;
   out_7513946483734019346[25] = 0;
   out_7513946483734019346[26] = 0;
   out_7513946483734019346[27] = 0;
   out_7513946483734019346[28] = 0;
   out_7513946483734019346[29] = 0;
   out_7513946483734019346[30] = 0;
   out_7513946483734019346[31] = 0;
   out_7513946483734019346[32] = 0;
   out_7513946483734019346[33] = 0;
   out_7513946483734019346[34] = 0;
   out_7513946483734019346[35] = 0;
   out_7513946483734019346[36] = 0;
   out_7513946483734019346[37] = 0;
   out_7513946483734019346[38] = 0;
   out_7513946483734019346[39] = 0;
   out_7513946483734019346[40] = 0;
   out_7513946483734019346[41] = 1;
   out_7513946483734019346[42] = 0;
   out_7513946483734019346[43] = 0;
   out_7513946483734019346[44] = 0;
   out_7513946483734019346[45] = 0;
   out_7513946483734019346[46] = 0;
   out_7513946483734019346[47] = 0;
   out_7513946483734019346[48] = 0;
   out_7513946483734019346[49] = 0;
   out_7513946483734019346[50] = 0;
   out_7513946483734019346[51] = 0;
   out_7513946483734019346[52] = 0;
   out_7513946483734019346[53] = 0;
}
void h_14(double *state, double *unused, double *out_60031468009030950) {
   out_60031468009030950[0] = state[6];
   out_60031468009030950[1] = state[7];
   out_60031468009030950[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1218884226106314249) {
   out_1218884226106314249[0] = 0;
   out_1218884226106314249[1] = 0;
   out_1218884226106314249[2] = 0;
   out_1218884226106314249[3] = 0;
   out_1218884226106314249[4] = 0;
   out_1218884226106314249[5] = 0;
   out_1218884226106314249[6] = 1;
   out_1218884226106314249[7] = 0;
   out_1218884226106314249[8] = 0;
   out_1218884226106314249[9] = 0;
   out_1218884226106314249[10] = 0;
   out_1218884226106314249[11] = 0;
   out_1218884226106314249[12] = 0;
   out_1218884226106314249[13] = 0;
   out_1218884226106314249[14] = 0;
   out_1218884226106314249[15] = 0;
   out_1218884226106314249[16] = 0;
   out_1218884226106314249[17] = 0;
   out_1218884226106314249[18] = 0;
   out_1218884226106314249[19] = 0;
   out_1218884226106314249[20] = 0;
   out_1218884226106314249[21] = 0;
   out_1218884226106314249[22] = 0;
   out_1218884226106314249[23] = 0;
   out_1218884226106314249[24] = 0;
   out_1218884226106314249[25] = 1;
   out_1218884226106314249[26] = 0;
   out_1218884226106314249[27] = 0;
   out_1218884226106314249[28] = 0;
   out_1218884226106314249[29] = 0;
   out_1218884226106314249[30] = 0;
   out_1218884226106314249[31] = 0;
   out_1218884226106314249[32] = 0;
   out_1218884226106314249[33] = 0;
   out_1218884226106314249[34] = 0;
   out_1218884226106314249[35] = 0;
   out_1218884226106314249[36] = 0;
   out_1218884226106314249[37] = 0;
   out_1218884226106314249[38] = 0;
   out_1218884226106314249[39] = 0;
   out_1218884226106314249[40] = 0;
   out_1218884226106314249[41] = 0;
   out_1218884226106314249[42] = 0;
   out_1218884226106314249[43] = 0;
   out_1218884226106314249[44] = 1;
   out_1218884226106314249[45] = 0;
   out_1218884226106314249[46] = 0;
   out_1218884226106314249[47] = 0;
   out_1218884226106314249[48] = 0;
   out_1218884226106314249[49] = 0;
   out_1218884226106314249[50] = 0;
   out_1218884226106314249[51] = 0;
   out_1218884226106314249[52] = 0;
   out_1218884226106314249[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7641933708620610052) {
  err_fun(nom_x, delta_x, out_7641933708620610052);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_9128860405088658984) {
  inv_err_fun(nom_x, true_x, out_9128860405088658984);
}
void pose_H_mod_fun(double *state, double *out_3103725176518788441) {
  H_mod_fun(state, out_3103725176518788441);
}
void pose_f_fun(double *state, double dt, double *out_5259001848744899041) {
  f_fun(state,  dt, out_5259001848744899041);
}
void pose_F_fun(double *state, double dt, double *out_6765250644485775616) {
  F_fun(state,  dt, out_6765250644485775616);
}
void pose_h_4(double *state, double *unused, double *out_6349780411594345580) {
  h_4(state, unused, out_6349780411594345580);
}
void pose_H_4(double *state, double *unused, double *out_4301672658401686545) {
  H_4(state, unused, out_4301672658401686545);
}
void pose_h_10(double *state, double *unused, double *out_1522297241205058892) {
  h_10(state, unused, out_1522297241205058892);
}
void pose_H_10(double *state, double *unused, double *out_2231099772160491337) {
  H_10(state, unused, out_2231099772160491337);
}
void pose_h_13(double *state, double *unused, double *out_9186389196897638740) {
  h_13(state, unused, out_9186389196897638740);
}
void pose_H_13(double *state, double *unused, double *out_7513946483734019346) {
  H_13(state, unused, out_7513946483734019346);
}
void pose_h_14(double *state, double *unused, double *out_60031468009030950) {
  h_14(state, unused, out_60031468009030950);
}
void pose_H_14(double *state, double *unused, double *out_1218884226106314249) {
  H_14(state, unused, out_1218884226106314249);
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
