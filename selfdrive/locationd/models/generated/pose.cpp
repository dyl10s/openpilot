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
void err_fun(double *nom_x, double *delta_x, double *out_2822233615381903085) {
   out_2822233615381903085[0] = delta_x[0] + nom_x[0];
   out_2822233615381903085[1] = delta_x[1] + nom_x[1];
   out_2822233615381903085[2] = delta_x[2] + nom_x[2];
   out_2822233615381903085[3] = delta_x[3] + nom_x[3];
   out_2822233615381903085[4] = delta_x[4] + nom_x[4];
   out_2822233615381903085[5] = delta_x[5] + nom_x[5];
   out_2822233615381903085[6] = delta_x[6] + nom_x[6];
   out_2822233615381903085[7] = delta_x[7] + nom_x[7];
   out_2822233615381903085[8] = delta_x[8] + nom_x[8];
   out_2822233615381903085[9] = delta_x[9] + nom_x[9];
   out_2822233615381903085[10] = delta_x[10] + nom_x[10];
   out_2822233615381903085[11] = delta_x[11] + nom_x[11];
   out_2822233615381903085[12] = delta_x[12] + nom_x[12];
   out_2822233615381903085[13] = delta_x[13] + nom_x[13];
   out_2822233615381903085[14] = delta_x[14] + nom_x[14];
   out_2822233615381903085[15] = delta_x[15] + nom_x[15];
   out_2822233615381903085[16] = delta_x[16] + nom_x[16];
   out_2822233615381903085[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3556797172859207138) {
   out_3556797172859207138[0] = -nom_x[0] + true_x[0];
   out_3556797172859207138[1] = -nom_x[1] + true_x[1];
   out_3556797172859207138[2] = -nom_x[2] + true_x[2];
   out_3556797172859207138[3] = -nom_x[3] + true_x[3];
   out_3556797172859207138[4] = -nom_x[4] + true_x[4];
   out_3556797172859207138[5] = -nom_x[5] + true_x[5];
   out_3556797172859207138[6] = -nom_x[6] + true_x[6];
   out_3556797172859207138[7] = -nom_x[7] + true_x[7];
   out_3556797172859207138[8] = -nom_x[8] + true_x[8];
   out_3556797172859207138[9] = -nom_x[9] + true_x[9];
   out_3556797172859207138[10] = -nom_x[10] + true_x[10];
   out_3556797172859207138[11] = -nom_x[11] + true_x[11];
   out_3556797172859207138[12] = -nom_x[12] + true_x[12];
   out_3556797172859207138[13] = -nom_x[13] + true_x[13];
   out_3556797172859207138[14] = -nom_x[14] + true_x[14];
   out_3556797172859207138[15] = -nom_x[15] + true_x[15];
   out_3556797172859207138[16] = -nom_x[16] + true_x[16];
   out_3556797172859207138[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4158952900173024917) {
   out_4158952900173024917[0] = 1.0;
   out_4158952900173024917[1] = 0.0;
   out_4158952900173024917[2] = 0.0;
   out_4158952900173024917[3] = 0.0;
   out_4158952900173024917[4] = 0.0;
   out_4158952900173024917[5] = 0.0;
   out_4158952900173024917[6] = 0.0;
   out_4158952900173024917[7] = 0.0;
   out_4158952900173024917[8] = 0.0;
   out_4158952900173024917[9] = 0.0;
   out_4158952900173024917[10] = 0.0;
   out_4158952900173024917[11] = 0.0;
   out_4158952900173024917[12] = 0.0;
   out_4158952900173024917[13] = 0.0;
   out_4158952900173024917[14] = 0.0;
   out_4158952900173024917[15] = 0.0;
   out_4158952900173024917[16] = 0.0;
   out_4158952900173024917[17] = 0.0;
   out_4158952900173024917[18] = 0.0;
   out_4158952900173024917[19] = 1.0;
   out_4158952900173024917[20] = 0.0;
   out_4158952900173024917[21] = 0.0;
   out_4158952900173024917[22] = 0.0;
   out_4158952900173024917[23] = 0.0;
   out_4158952900173024917[24] = 0.0;
   out_4158952900173024917[25] = 0.0;
   out_4158952900173024917[26] = 0.0;
   out_4158952900173024917[27] = 0.0;
   out_4158952900173024917[28] = 0.0;
   out_4158952900173024917[29] = 0.0;
   out_4158952900173024917[30] = 0.0;
   out_4158952900173024917[31] = 0.0;
   out_4158952900173024917[32] = 0.0;
   out_4158952900173024917[33] = 0.0;
   out_4158952900173024917[34] = 0.0;
   out_4158952900173024917[35] = 0.0;
   out_4158952900173024917[36] = 0.0;
   out_4158952900173024917[37] = 0.0;
   out_4158952900173024917[38] = 1.0;
   out_4158952900173024917[39] = 0.0;
   out_4158952900173024917[40] = 0.0;
   out_4158952900173024917[41] = 0.0;
   out_4158952900173024917[42] = 0.0;
   out_4158952900173024917[43] = 0.0;
   out_4158952900173024917[44] = 0.0;
   out_4158952900173024917[45] = 0.0;
   out_4158952900173024917[46] = 0.0;
   out_4158952900173024917[47] = 0.0;
   out_4158952900173024917[48] = 0.0;
   out_4158952900173024917[49] = 0.0;
   out_4158952900173024917[50] = 0.0;
   out_4158952900173024917[51] = 0.0;
   out_4158952900173024917[52] = 0.0;
   out_4158952900173024917[53] = 0.0;
   out_4158952900173024917[54] = 0.0;
   out_4158952900173024917[55] = 0.0;
   out_4158952900173024917[56] = 0.0;
   out_4158952900173024917[57] = 1.0;
   out_4158952900173024917[58] = 0.0;
   out_4158952900173024917[59] = 0.0;
   out_4158952900173024917[60] = 0.0;
   out_4158952900173024917[61] = 0.0;
   out_4158952900173024917[62] = 0.0;
   out_4158952900173024917[63] = 0.0;
   out_4158952900173024917[64] = 0.0;
   out_4158952900173024917[65] = 0.0;
   out_4158952900173024917[66] = 0.0;
   out_4158952900173024917[67] = 0.0;
   out_4158952900173024917[68] = 0.0;
   out_4158952900173024917[69] = 0.0;
   out_4158952900173024917[70] = 0.0;
   out_4158952900173024917[71] = 0.0;
   out_4158952900173024917[72] = 0.0;
   out_4158952900173024917[73] = 0.0;
   out_4158952900173024917[74] = 0.0;
   out_4158952900173024917[75] = 0.0;
   out_4158952900173024917[76] = 1.0;
   out_4158952900173024917[77] = 0.0;
   out_4158952900173024917[78] = 0.0;
   out_4158952900173024917[79] = 0.0;
   out_4158952900173024917[80] = 0.0;
   out_4158952900173024917[81] = 0.0;
   out_4158952900173024917[82] = 0.0;
   out_4158952900173024917[83] = 0.0;
   out_4158952900173024917[84] = 0.0;
   out_4158952900173024917[85] = 0.0;
   out_4158952900173024917[86] = 0.0;
   out_4158952900173024917[87] = 0.0;
   out_4158952900173024917[88] = 0.0;
   out_4158952900173024917[89] = 0.0;
   out_4158952900173024917[90] = 0.0;
   out_4158952900173024917[91] = 0.0;
   out_4158952900173024917[92] = 0.0;
   out_4158952900173024917[93] = 0.0;
   out_4158952900173024917[94] = 0.0;
   out_4158952900173024917[95] = 1.0;
   out_4158952900173024917[96] = 0.0;
   out_4158952900173024917[97] = 0.0;
   out_4158952900173024917[98] = 0.0;
   out_4158952900173024917[99] = 0.0;
   out_4158952900173024917[100] = 0.0;
   out_4158952900173024917[101] = 0.0;
   out_4158952900173024917[102] = 0.0;
   out_4158952900173024917[103] = 0.0;
   out_4158952900173024917[104] = 0.0;
   out_4158952900173024917[105] = 0.0;
   out_4158952900173024917[106] = 0.0;
   out_4158952900173024917[107] = 0.0;
   out_4158952900173024917[108] = 0.0;
   out_4158952900173024917[109] = 0.0;
   out_4158952900173024917[110] = 0.0;
   out_4158952900173024917[111] = 0.0;
   out_4158952900173024917[112] = 0.0;
   out_4158952900173024917[113] = 0.0;
   out_4158952900173024917[114] = 1.0;
   out_4158952900173024917[115] = 0.0;
   out_4158952900173024917[116] = 0.0;
   out_4158952900173024917[117] = 0.0;
   out_4158952900173024917[118] = 0.0;
   out_4158952900173024917[119] = 0.0;
   out_4158952900173024917[120] = 0.0;
   out_4158952900173024917[121] = 0.0;
   out_4158952900173024917[122] = 0.0;
   out_4158952900173024917[123] = 0.0;
   out_4158952900173024917[124] = 0.0;
   out_4158952900173024917[125] = 0.0;
   out_4158952900173024917[126] = 0.0;
   out_4158952900173024917[127] = 0.0;
   out_4158952900173024917[128] = 0.0;
   out_4158952900173024917[129] = 0.0;
   out_4158952900173024917[130] = 0.0;
   out_4158952900173024917[131] = 0.0;
   out_4158952900173024917[132] = 0.0;
   out_4158952900173024917[133] = 1.0;
   out_4158952900173024917[134] = 0.0;
   out_4158952900173024917[135] = 0.0;
   out_4158952900173024917[136] = 0.0;
   out_4158952900173024917[137] = 0.0;
   out_4158952900173024917[138] = 0.0;
   out_4158952900173024917[139] = 0.0;
   out_4158952900173024917[140] = 0.0;
   out_4158952900173024917[141] = 0.0;
   out_4158952900173024917[142] = 0.0;
   out_4158952900173024917[143] = 0.0;
   out_4158952900173024917[144] = 0.0;
   out_4158952900173024917[145] = 0.0;
   out_4158952900173024917[146] = 0.0;
   out_4158952900173024917[147] = 0.0;
   out_4158952900173024917[148] = 0.0;
   out_4158952900173024917[149] = 0.0;
   out_4158952900173024917[150] = 0.0;
   out_4158952900173024917[151] = 0.0;
   out_4158952900173024917[152] = 1.0;
   out_4158952900173024917[153] = 0.0;
   out_4158952900173024917[154] = 0.0;
   out_4158952900173024917[155] = 0.0;
   out_4158952900173024917[156] = 0.0;
   out_4158952900173024917[157] = 0.0;
   out_4158952900173024917[158] = 0.0;
   out_4158952900173024917[159] = 0.0;
   out_4158952900173024917[160] = 0.0;
   out_4158952900173024917[161] = 0.0;
   out_4158952900173024917[162] = 0.0;
   out_4158952900173024917[163] = 0.0;
   out_4158952900173024917[164] = 0.0;
   out_4158952900173024917[165] = 0.0;
   out_4158952900173024917[166] = 0.0;
   out_4158952900173024917[167] = 0.0;
   out_4158952900173024917[168] = 0.0;
   out_4158952900173024917[169] = 0.0;
   out_4158952900173024917[170] = 0.0;
   out_4158952900173024917[171] = 1.0;
   out_4158952900173024917[172] = 0.0;
   out_4158952900173024917[173] = 0.0;
   out_4158952900173024917[174] = 0.0;
   out_4158952900173024917[175] = 0.0;
   out_4158952900173024917[176] = 0.0;
   out_4158952900173024917[177] = 0.0;
   out_4158952900173024917[178] = 0.0;
   out_4158952900173024917[179] = 0.0;
   out_4158952900173024917[180] = 0.0;
   out_4158952900173024917[181] = 0.0;
   out_4158952900173024917[182] = 0.0;
   out_4158952900173024917[183] = 0.0;
   out_4158952900173024917[184] = 0.0;
   out_4158952900173024917[185] = 0.0;
   out_4158952900173024917[186] = 0.0;
   out_4158952900173024917[187] = 0.0;
   out_4158952900173024917[188] = 0.0;
   out_4158952900173024917[189] = 0.0;
   out_4158952900173024917[190] = 1.0;
   out_4158952900173024917[191] = 0.0;
   out_4158952900173024917[192] = 0.0;
   out_4158952900173024917[193] = 0.0;
   out_4158952900173024917[194] = 0.0;
   out_4158952900173024917[195] = 0.0;
   out_4158952900173024917[196] = 0.0;
   out_4158952900173024917[197] = 0.0;
   out_4158952900173024917[198] = 0.0;
   out_4158952900173024917[199] = 0.0;
   out_4158952900173024917[200] = 0.0;
   out_4158952900173024917[201] = 0.0;
   out_4158952900173024917[202] = 0.0;
   out_4158952900173024917[203] = 0.0;
   out_4158952900173024917[204] = 0.0;
   out_4158952900173024917[205] = 0.0;
   out_4158952900173024917[206] = 0.0;
   out_4158952900173024917[207] = 0.0;
   out_4158952900173024917[208] = 0.0;
   out_4158952900173024917[209] = 1.0;
   out_4158952900173024917[210] = 0.0;
   out_4158952900173024917[211] = 0.0;
   out_4158952900173024917[212] = 0.0;
   out_4158952900173024917[213] = 0.0;
   out_4158952900173024917[214] = 0.0;
   out_4158952900173024917[215] = 0.0;
   out_4158952900173024917[216] = 0.0;
   out_4158952900173024917[217] = 0.0;
   out_4158952900173024917[218] = 0.0;
   out_4158952900173024917[219] = 0.0;
   out_4158952900173024917[220] = 0.0;
   out_4158952900173024917[221] = 0.0;
   out_4158952900173024917[222] = 0.0;
   out_4158952900173024917[223] = 0.0;
   out_4158952900173024917[224] = 0.0;
   out_4158952900173024917[225] = 0.0;
   out_4158952900173024917[226] = 0.0;
   out_4158952900173024917[227] = 0.0;
   out_4158952900173024917[228] = 1.0;
   out_4158952900173024917[229] = 0.0;
   out_4158952900173024917[230] = 0.0;
   out_4158952900173024917[231] = 0.0;
   out_4158952900173024917[232] = 0.0;
   out_4158952900173024917[233] = 0.0;
   out_4158952900173024917[234] = 0.0;
   out_4158952900173024917[235] = 0.0;
   out_4158952900173024917[236] = 0.0;
   out_4158952900173024917[237] = 0.0;
   out_4158952900173024917[238] = 0.0;
   out_4158952900173024917[239] = 0.0;
   out_4158952900173024917[240] = 0.0;
   out_4158952900173024917[241] = 0.0;
   out_4158952900173024917[242] = 0.0;
   out_4158952900173024917[243] = 0.0;
   out_4158952900173024917[244] = 0.0;
   out_4158952900173024917[245] = 0.0;
   out_4158952900173024917[246] = 0.0;
   out_4158952900173024917[247] = 1.0;
   out_4158952900173024917[248] = 0.0;
   out_4158952900173024917[249] = 0.0;
   out_4158952900173024917[250] = 0.0;
   out_4158952900173024917[251] = 0.0;
   out_4158952900173024917[252] = 0.0;
   out_4158952900173024917[253] = 0.0;
   out_4158952900173024917[254] = 0.0;
   out_4158952900173024917[255] = 0.0;
   out_4158952900173024917[256] = 0.0;
   out_4158952900173024917[257] = 0.0;
   out_4158952900173024917[258] = 0.0;
   out_4158952900173024917[259] = 0.0;
   out_4158952900173024917[260] = 0.0;
   out_4158952900173024917[261] = 0.0;
   out_4158952900173024917[262] = 0.0;
   out_4158952900173024917[263] = 0.0;
   out_4158952900173024917[264] = 0.0;
   out_4158952900173024917[265] = 0.0;
   out_4158952900173024917[266] = 1.0;
   out_4158952900173024917[267] = 0.0;
   out_4158952900173024917[268] = 0.0;
   out_4158952900173024917[269] = 0.0;
   out_4158952900173024917[270] = 0.0;
   out_4158952900173024917[271] = 0.0;
   out_4158952900173024917[272] = 0.0;
   out_4158952900173024917[273] = 0.0;
   out_4158952900173024917[274] = 0.0;
   out_4158952900173024917[275] = 0.0;
   out_4158952900173024917[276] = 0.0;
   out_4158952900173024917[277] = 0.0;
   out_4158952900173024917[278] = 0.0;
   out_4158952900173024917[279] = 0.0;
   out_4158952900173024917[280] = 0.0;
   out_4158952900173024917[281] = 0.0;
   out_4158952900173024917[282] = 0.0;
   out_4158952900173024917[283] = 0.0;
   out_4158952900173024917[284] = 0.0;
   out_4158952900173024917[285] = 1.0;
   out_4158952900173024917[286] = 0.0;
   out_4158952900173024917[287] = 0.0;
   out_4158952900173024917[288] = 0.0;
   out_4158952900173024917[289] = 0.0;
   out_4158952900173024917[290] = 0.0;
   out_4158952900173024917[291] = 0.0;
   out_4158952900173024917[292] = 0.0;
   out_4158952900173024917[293] = 0.0;
   out_4158952900173024917[294] = 0.0;
   out_4158952900173024917[295] = 0.0;
   out_4158952900173024917[296] = 0.0;
   out_4158952900173024917[297] = 0.0;
   out_4158952900173024917[298] = 0.0;
   out_4158952900173024917[299] = 0.0;
   out_4158952900173024917[300] = 0.0;
   out_4158952900173024917[301] = 0.0;
   out_4158952900173024917[302] = 0.0;
   out_4158952900173024917[303] = 0.0;
   out_4158952900173024917[304] = 1.0;
   out_4158952900173024917[305] = 0.0;
   out_4158952900173024917[306] = 0.0;
   out_4158952900173024917[307] = 0.0;
   out_4158952900173024917[308] = 0.0;
   out_4158952900173024917[309] = 0.0;
   out_4158952900173024917[310] = 0.0;
   out_4158952900173024917[311] = 0.0;
   out_4158952900173024917[312] = 0.0;
   out_4158952900173024917[313] = 0.0;
   out_4158952900173024917[314] = 0.0;
   out_4158952900173024917[315] = 0.0;
   out_4158952900173024917[316] = 0.0;
   out_4158952900173024917[317] = 0.0;
   out_4158952900173024917[318] = 0.0;
   out_4158952900173024917[319] = 0.0;
   out_4158952900173024917[320] = 0.0;
   out_4158952900173024917[321] = 0.0;
   out_4158952900173024917[322] = 0.0;
   out_4158952900173024917[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4480310224533440205) {
   out_4480310224533440205[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4480310224533440205[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4480310224533440205[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4480310224533440205[3] = dt*state[12] + state[3];
   out_4480310224533440205[4] = dt*state[13] + state[4];
   out_4480310224533440205[5] = dt*state[14] + state[5];
   out_4480310224533440205[6] = state[6];
   out_4480310224533440205[7] = state[7];
   out_4480310224533440205[8] = state[8];
   out_4480310224533440205[9] = state[9];
   out_4480310224533440205[10] = state[10];
   out_4480310224533440205[11] = state[11];
   out_4480310224533440205[12] = state[12];
   out_4480310224533440205[13] = state[13];
   out_4480310224533440205[14] = state[14];
   out_4480310224533440205[15] = state[15];
   out_4480310224533440205[16] = state[16];
   out_4480310224533440205[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2252133042369597057) {
   out_2252133042369597057[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2252133042369597057[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2252133042369597057[2] = 0;
   out_2252133042369597057[3] = 0;
   out_2252133042369597057[4] = 0;
   out_2252133042369597057[5] = 0;
   out_2252133042369597057[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2252133042369597057[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2252133042369597057[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2252133042369597057[9] = 0;
   out_2252133042369597057[10] = 0;
   out_2252133042369597057[11] = 0;
   out_2252133042369597057[12] = 0;
   out_2252133042369597057[13] = 0;
   out_2252133042369597057[14] = 0;
   out_2252133042369597057[15] = 0;
   out_2252133042369597057[16] = 0;
   out_2252133042369597057[17] = 0;
   out_2252133042369597057[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2252133042369597057[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2252133042369597057[20] = 0;
   out_2252133042369597057[21] = 0;
   out_2252133042369597057[22] = 0;
   out_2252133042369597057[23] = 0;
   out_2252133042369597057[24] = 0;
   out_2252133042369597057[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2252133042369597057[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2252133042369597057[27] = 0;
   out_2252133042369597057[28] = 0;
   out_2252133042369597057[29] = 0;
   out_2252133042369597057[30] = 0;
   out_2252133042369597057[31] = 0;
   out_2252133042369597057[32] = 0;
   out_2252133042369597057[33] = 0;
   out_2252133042369597057[34] = 0;
   out_2252133042369597057[35] = 0;
   out_2252133042369597057[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2252133042369597057[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2252133042369597057[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2252133042369597057[39] = 0;
   out_2252133042369597057[40] = 0;
   out_2252133042369597057[41] = 0;
   out_2252133042369597057[42] = 0;
   out_2252133042369597057[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2252133042369597057[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2252133042369597057[45] = 0;
   out_2252133042369597057[46] = 0;
   out_2252133042369597057[47] = 0;
   out_2252133042369597057[48] = 0;
   out_2252133042369597057[49] = 0;
   out_2252133042369597057[50] = 0;
   out_2252133042369597057[51] = 0;
   out_2252133042369597057[52] = 0;
   out_2252133042369597057[53] = 0;
   out_2252133042369597057[54] = 0;
   out_2252133042369597057[55] = 0;
   out_2252133042369597057[56] = 0;
   out_2252133042369597057[57] = 1;
   out_2252133042369597057[58] = 0;
   out_2252133042369597057[59] = 0;
   out_2252133042369597057[60] = 0;
   out_2252133042369597057[61] = 0;
   out_2252133042369597057[62] = 0;
   out_2252133042369597057[63] = 0;
   out_2252133042369597057[64] = 0;
   out_2252133042369597057[65] = 0;
   out_2252133042369597057[66] = dt;
   out_2252133042369597057[67] = 0;
   out_2252133042369597057[68] = 0;
   out_2252133042369597057[69] = 0;
   out_2252133042369597057[70] = 0;
   out_2252133042369597057[71] = 0;
   out_2252133042369597057[72] = 0;
   out_2252133042369597057[73] = 0;
   out_2252133042369597057[74] = 0;
   out_2252133042369597057[75] = 0;
   out_2252133042369597057[76] = 1;
   out_2252133042369597057[77] = 0;
   out_2252133042369597057[78] = 0;
   out_2252133042369597057[79] = 0;
   out_2252133042369597057[80] = 0;
   out_2252133042369597057[81] = 0;
   out_2252133042369597057[82] = 0;
   out_2252133042369597057[83] = 0;
   out_2252133042369597057[84] = 0;
   out_2252133042369597057[85] = dt;
   out_2252133042369597057[86] = 0;
   out_2252133042369597057[87] = 0;
   out_2252133042369597057[88] = 0;
   out_2252133042369597057[89] = 0;
   out_2252133042369597057[90] = 0;
   out_2252133042369597057[91] = 0;
   out_2252133042369597057[92] = 0;
   out_2252133042369597057[93] = 0;
   out_2252133042369597057[94] = 0;
   out_2252133042369597057[95] = 1;
   out_2252133042369597057[96] = 0;
   out_2252133042369597057[97] = 0;
   out_2252133042369597057[98] = 0;
   out_2252133042369597057[99] = 0;
   out_2252133042369597057[100] = 0;
   out_2252133042369597057[101] = 0;
   out_2252133042369597057[102] = 0;
   out_2252133042369597057[103] = 0;
   out_2252133042369597057[104] = dt;
   out_2252133042369597057[105] = 0;
   out_2252133042369597057[106] = 0;
   out_2252133042369597057[107] = 0;
   out_2252133042369597057[108] = 0;
   out_2252133042369597057[109] = 0;
   out_2252133042369597057[110] = 0;
   out_2252133042369597057[111] = 0;
   out_2252133042369597057[112] = 0;
   out_2252133042369597057[113] = 0;
   out_2252133042369597057[114] = 1;
   out_2252133042369597057[115] = 0;
   out_2252133042369597057[116] = 0;
   out_2252133042369597057[117] = 0;
   out_2252133042369597057[118] = 0;
   out_2252133042369597057[119] = 0;
   out_2252133042369597057[120] = 0;
   out_2252133042369597057[121] = 0;
   out_2252133042369597057[122] = 0;
   out_2252133042369597057[123] = 0;
   out_2252133042369597057[124] = 0;
   out_2252133042369597057[125] = 0;
   out_2252133042369597057[126] = 0;
   out_2252133042369597057[127] = 0;
   out_2252133042369597057[128] = 0;
   out_2252133042369597057[129] = 0;
   out_2252133042369597057[130] = 0;
   out_2252133042369597057[131] = 0;
   out_2252133042369597057[132] = 0;
   out_2252133042369597057[133] = 1;
   out_2252133042369597057[134] = 0;
   out_2252133042369597057[135] = 0;
   out_2252133042369597057[136] = 0;
   out_2252133042369597057[137] = 0;
   out_2252133042369597057[138] = 0;
   out_2252133042369597057[139] = 0;
   out_2252133042369597057[140] = 0;
   out_2252133042369597057[141] = 0;
   out_2252133042369597057[142] = 0;
   out_2252133042369597057[143] = 0;
   out_2252133042369597057[144] = 0;
   out_2252133042369597057[145] = 0;
   out_2252133042369597057[146] = 0;
   out_2252133042369597057[147] = 0;
   out_2252133042369597057[148] = 0;
   out_2252133042369597057[149] = 0;
   out_2252133042369597057[150] = 0;
   out_2252133042369597057[151] = 0;
   out_2252133042369597057[152] = 1;
   out_2252133042369597057[153] = 0;
   out_2252133042369597057[154] = 0;
   out_2252133042369597057[155] = 0;
   out_2252133042369597057[156] = 0;
   out_2252133042369597057[157] = 0;
   out_2252133042369597057[158] = 0;
   out_2252133042369597057[159] = 0;
   out_2252133042369597057[160] = 0;
   out_2252133042369597057[161] = 0;
   out_2252133042369597057[162] = 0;
   out_2252133042369597057[163] = 0;
   out_2252133042369597057[164] = 0;
   out_2252133042369597057[165] = 0;
   out_2252133042369597057[166] = 0;
   out_2252133042369597057[167] = 0;
   out_2252133042369597057[168] = 0;
   out_2252133042369597057[169] = 0;
   out_2252133042369597057[170] = 0;
   out_2252133042369597057[171] = 1;
   out_2252133042369597057[172] = 0;
   out_2252133042369597057[173] = 0;
   out_2252133042369597057[174] = 0;
   out_2252133042369597057[175] = 0;
   out_2252133042369597057[176] = 0;
   out_2252133042369597057[177] = 0;
   out_2252133042369597057[178] = 0;
   out_2252133042369597057[179] = 0;
   out_2252133042369597057[180] = 0;
   out_2252133042369597057[181] = 0;
   out_2252133042369597057[182] = 0;
   out_2252133042369597057[183] = 0;
   out_2252133042369597057[184] = 0;
   out_2252133042369597057[185] = 0;
   out_2252133042369597057[186] = 0;
   out_2252133042369597057[187] = 0;
   out_2252133042369597057[188] = 0;
   out_2252133042369597057[189] = 0;
   out_2252133042369597057[190] = 1;
   out_2252133042369597057[191] = 0;
   out_2252133042369597057[192] = 0;
   out_2252133042369597057[193] = 0;
   out_2252133042369597057[194] = 0;
   out_2252133042369597057[195] = 0;
   out_2252133042369597057[196] = 0;
   out_2252133042369597057[197] = 0;
   out_2252133042369597057[198] = 0;
   out_2252133042369597057[199] = 0;
   out_2252133042369597057[200] = 0;
   out_2252133042369597057[201] = 0;
   out_2252133042369597057[202] = 0;
   out_2252133042369597057[203] = 0;
   out_2252133042369597057[204] = 0;
   out_2252133042369597057[205] = 0;
   out_2252133042369597057[206] = 0;
   out_2252133042369597057[207] = 0;
   out_2252133042369597057[208] = 0;
   out_2252133042369597057[209] = 1;
   out_2252133042369597057[210] = 0;
   out_2252133042369597057[211] = 0;
   out_2252133042369597057[212] = 0;
   out_2252133042369597057[213] = 0;
   out_2252133042369597057[214] = 0;
   out_2252133042369597057[215] = 0;
   out_2252133042369597057[216] = 0;
   out_2252133042369597057[217] = 0;
   out_2252133042369597057[218] = 0;
   out_2252133042369597057[219] = 0;
   out_2252133042369597057[220] = 0;
   out_2252133042369597057[221] = 0;
   out_2252133042369597057[222] = 0;
   out_2252133042369597057[223] = 0;
   out_2252133042369597057[224] = 0;
   out_2252133042369597057[225] = 0;
   out_2252133042369597057[226] = 0;
   out_2252133042369597057[227] = 0;
   out_2252133042369597057[228] = 1;
   out_2252133042369597057[229] = 0;
   out_2252133042369597057[230] = 0;
   out_2252133042369597057[231] = 0;
   out_2252133042369597057[232] = 0;
   out_2252133042369597057[233] = 0;
   out_2252133042369597057[234] = 0;
   out_2252133042369597057[235] = 0;
   out_2252133042369597057[236] = 0;
   out_2252133042369597057[237] = 0;
   out_2252133042369597057[238] = 0;
   out_2252133042369597057[239] = 0;
   out_2252133042369597057[240] = 0;
   out_2252133042369597057[241] = 0;
   out_2252133042369597057[242] = 0;
   out_2252133042369597057[243] = 0;
   out_2252133042369597057[244] = 0;
   out_2252133042369597057[245] = 0;
   out_2252133042369597057[246] = 0;
   out_2252133042369597057[247] = 1;
   out_2252133042369597057[248] = 0;
   out_2252133042369597057[249] = 0;
   out_2252133042369597057[250] = 0;
   out_2252133042369597057[251] = 0;
   out_2252133042369597057[252] = 0;
   out_2252133042369597057[253] = 0;
   out_2252133042369597057[254] = 0;
   out_2252133042369597057[255] = 0;
   out_2252133042369597057[256] = 0;
   out_2252133042369597057[257] = 0;
   out_2252133042369597057[258] = 0;
   out_2252133042369597057[259] = 0;
   out_2252133042369597057[260] = 0;
   out_2252133042369597057[261] = 0;
   out_2252133042369597057[262] = 0;
   out_2252133042369597057[263] = 0;
   out_2252133042369597057[264] = 0;
   out_2252133042369597057[265] = 0;
   out_2252133042369597057[266] = 1;
   out_2252133042369597057[267] = 0;
   out_2252133042369597057[268] = 0;
   out_2252133042369597057[269] = 0;
   out_2252133042369597057[270] = 0;
   out_2252133042369597057[271] = 0;
   out_2252133042369597057[272] = 0;
   out_2252133042369597057[273] = 0;
   out_2252133042369597057[274] = 0;
   out_2252133042369597057[275] = 0;
   out_2252133042369597057[276] = 0;
   out_2252133042369597057[277] = 0;
   out_2252133042369597057[278] = 0;
   out_2252133042369597057[279] = 0;
   out_2252133042369597057[280] = 0;
   out_2252133042369597057[281] = 0;
   out_2252133042369597057[282] = 0;
   out_2252133042369597057[283] = 0;
   out_2252133042369597057[284] = 0;
   out_2252133042369597057[285] = 1;
   out_2252133042369597057[286] = 0;
   out_2252133042369597057[287] = 0;
   out_2252133042369597057[288] = 0;
   out_2252133042369597057[289] = 0;
   out_2252133042369597057[290] = 0;
   out_2252133042369597057[291] = 0;
   out_2252133042369597057[292] = 0;
   out_2252133042369597057[293] = 0;
   out_2252133042369597057[294] = 0;
   out_2252133042369597057[295] = 0;
   out_2252133042369597057[296] = 0;
   out_2252133042369597057[297] = 0;
   out_2252133042369597057[298] = 0;
   out_2252133042369597057[299] = 0;
   out_2252133042369597057[300] = 0;
   out_2252133042369597057[301] = 0;
   out_2252133042369597057[302] = 0;
   out_2252133042369597057[303] = 0;
   out_2252133042369597057[304] = 1;
   out_2252133042369597057[305] = 0;
   out_2252133042369597057[306] = 0;
   out_2252133042369597057[307] = 0;
   out_2252133042369597057[308] = 0;
   out_2252133042369597057[309] = 0;
   out_2252133042369597057[310] = 0;
   out_2252133042369597057[311] = 0;
   out_2252133042369597057[312] = 0;
   out_2252133042369597057[313] = 0;
   out_2252133042369597057[314] = 0;
   out_2252133042369597057[315] = 0;
   out_2252133042369597057[316] = 0;
   out_2252133042369597057[317] = 0;
   out_2252133042369597057[318] = 0;
   out_2252133042369597057[319] = 0;
   out_2252133042369597057[320] = 0;
   out_2252133042369597057[321] = 0;
   out_2252133042369597057[322] = 0;
   out_2252133042369597057[323] = 1;
}
void h_4(double *state, double *unused, double *out_1225931617160521679) {
   out_1225931617160521679[0] = state[6] + state[9];
   out_1225931617160521679[1] = state[7] + state[10];
   out_1225931617160521679[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3404791898118312310) {
   out_3404791898118312310[0] = 0;
   out_3404791898118312310[1] = 0;
   out_3404791898118312310[2] = 0;
   out_3404791898118312310[3] = 0;
   out_3404791898118312310[4] = 0;
   out_3404791898118312310[5] = 0;
   out_3404791898118312310[6] = 1;
   out_3404791898118312310[7] = 0;
   out_3404791898118312310[8] = 0;
   out_3404791898118312310[9] = 1;
   out_3404791898118312310[10] = 0;
   out_3404791898118312310[11] = 0;
   out_3404791898118312310[12] = 0;
   out_3404791898118312310[13] = 0;
   out_3404791898118312310[14] = 0;
   out_3404791898118312310[15] = 0;
   out_3404791898118312310[16] = 0;
   out_3404791898118312310[17] = 0;
   out_3404791898118312310[18] = 0;
   out_3404791898118312310[19] = 0;
   out_3404791898118312310[20] = 0;
   out_3404791898118312310[21] = 0;
   out_3404791898118312310[22] = 0;
   out_3404791898118312310[23] = 0;
   out_3404791898118312310[24] = 0;
   out_3404791898118312310[25] = 1;
   out_3404791898118312310[26] = 0;
   out_3404791898118312310[27] = 0;
   out_3404791898118312310[28] = 1;
   out_3404791898118312310[29] = 0;
   out_3404791898118312310[30] = 0;
   out_3404791898118312310[31] = 0;
   out_3404791898118312310[32] = 0;
   out_3404791898118312310[33] = 0;
   out_3404791898118312310[34] = 0;
   out_3404791898118312310[35] = 0;
   out_3404791898118312310[36] = 0;
   out_3404791898118312310[37] = 0;
   out_3404791898118312310[38] = 0;
   out_3404791898118312310[39] = 0;
   out_3404791898118312310[40] = 0;
   out_3404791898118312310[41] = 0;
   out_3404791898118312310[42] = 0;
   out_3404791898118312310[43] = 0;
   out_3404791898118312310[44] = 1;
   out_3404791898118312310[45] = 0;
   out_3404791898118312310[46] = 0;
   out_3404791898118312310[47] = 1;
   out_3404791898118312310[48] = 0;
   out_3404791898118312310[49] = 0;
   out_3404791898118312310[50] = 0;
   out_3404791898118312310[51] = 0;
   out_3404791898118312310[52] = 0;
   out_3404791898118312310[53] = 0;
}
void h_10(double *state, double *unused, double *out_8314558572170779017) {
   out_8314558572170779017[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8314558572170779017[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8314558572170779017[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3543553484029179274) {
   out_3543553484029179274[0] = 0;
   out_3543553484029179274[1] = 9.8100000000000005*cos(state[1]);
   out_3543553484029179274[2] = 0;
   out_3543553484029179274[3] = 0;
   out_3543553484029179274[4] = -state[8];
   out_3543553484029179274[5] = state[7];
   out_3543553484029179274[6] = 0;
   out_3543553484029179274[7] = state[5];
   out_3543553484029179274[8] = -state[4];
   out_3543553484029179274[9] = 0;
   out_3543553484029179274[10] = 0;
   out_3543553484029179274[11] = 0;
   out_3543553484029179274[12] = 1;
   out_3543553484029179274[13] = 0;
   out_3543553484029179274[14] = 0;
   out_3543553484029179274[15] = 1;
   out_3543553484029179274[16] = 0;
   out_3543553484029179274[17] = 0;
   out_3543553484029179274[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3543553484029179274[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3543553484029179274[20] = 0;
   out_3543553484029179274[21] = state[8];
   out_3543553484029179274[22] = 0;
   out_3543553484029179274[23] = -state[6];
   out_3543553484029179274[24] = -state[5];
   out_3543553484029179274[25] = 0;
   out_3543553484029179274[26] = state[3];
   out_3543553484029179274[27] = 0;
   out_3543553484029179274[28] = 0;
   out_3543553484029179274[29] = 0;
   out_3543553484029179274[30] = 0;
   out_3543553484029179274[31] = 1;
   out_3543553484029179274[32] = 0;
   out_3543553484029179274[33] = 0;
   out_3543553484029179274[34] = 1;
   out_3543553484029179274[35] = 0;
   out_3543553484029179274[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3543553484029179274[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3543553484029179274[38] = 0;
   out_3543553484029179274[39] = -state[7];
   out_3543553484029179274[40] = state[6];
   out_3543553484029179274[41] = 0;
   out_3543553484029179274[42] = state[4];
   out_3543553484029179274[43] = -state[3];
   out_3543553484029179274[44] = 0;
   out_3543553484029179274[45] = 0;
   out_3543553484029179274[46] = 0;
   out_3543553484029179274[47] = 0;
   out_3543553484029179274[48] = 0;
   out_3543553484029179274[49] = 0;
   out_3543553484029179274[50] = 1;
   out_3543553484029179274[51] = 0;
   out_3543553484029179274[52] = 0;
   out_3543553484029179274[53] = 1;
}
void h_13(double *state, double *unused, double *out_7492025966781743409) {
   out_7492025966781743409[0] = state[3];
   out_7492025966781743409[1] = state[4];
   out_7492025966781743409[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4205839310198388619) {
   out_4205839310198388619[0] = 0;
   out_4205839310198388619[1] = 0;
   out_4205839310198388619[2] = 0;
   out_4205839310198388619[3] = 1;
   out_4205839310198388619[4] = 0;
   out_4205839310198388619[5] = 0;
   out_4205839310198388619[6] = 0;
   out_4205839310198388619[7] = 0;
   out_4205839310198388619[8] = 0;
   out_4205839310198388619[9] = 0;
   out_4205839310198388619[10] = 0;
   out_4205839310198388619[11] = 0;
   out_4205839310198388619[12] = 0;
   out_4205839310198388619[13] = 0;
   out_4205839310198388619[14] = 0;
   out_4205839310198388619[15] = 0;
   out_4205839310198388619[16] = 0;
   out_4205839310198388619[17] = 0;
   out_4205839310198388619[18] = 0;
   out_4205839310198388619[19] = 0;
   out_4205839310198388619[20] = 0;
   out_4205839310198388619[21] = 0;
   out_4205839310198388619[22] = 1;
   out_4205839310198388619[23] = 0;
   out_4205839310198388619[24] = 0;
   out_4205839310198388619[25] = 0;
   out_4205839310198388619[26] = 0;
   out_4205839310198388619[27] = 0;
   out_4205839310198388619[28] = 0;
   out_4205839310198388619[29] = 0;
   out_4205839310198388619[30] = 0;
   out_4205839310198388619[31] = 0;
   out_4205839310198388619[32] = 0;
   out_4205839310198388619[33] = 0;
   out_4205839310198388619[34] = 0;
   out_4205839310198388619[35] = 0;
   out_4205839310198388619[36] = 0;
   out_4205839310198388619[37] = 0;
   out_4205839310198388619[38] = 0;
   out_4205839310198388619[39] = 0;
   out_4205839310198388619[40] = 0;
   out_4205839310198388619[41] = 1;
   out_4205839310198388619[42] = 0;
   out_4205839310198388619[43] = 0;
   out_4205839310198388619[44] = 0;
   out_4205839310198388619[45] = 0;
   out_4205839310198388619[46] = 0;
   out_4205839310198388619[47] = 0;
   out_4205839310198388619[48] = 0;
   out_4205839310198388619[49] = 0;
   out_4205839310198388619[50] = 0;
   out_4205839310198388619[51] = 0;
   out_4205839310198388619[52] = 0;
   out_4205839310198388619[53] = 0;
}
void h_14(double *state, double *unused, double *out_8444019918627598165) {
   out_8444019918627598165[0] = state[6];
   out_8444019918627598165[1] = state[7];
   out_8444019918627598165[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6487580330413684606) {
   out_6487580330413684606[0] = 0;
   out_6487580330413684606[1] = 0;
   out_6487580330413684606[2] = 0;
   out_6487580330413684606[3] = 0;
   out_6487580330413684606[4] = 0;
   out_6487580330413684606[5] = 0;
   out_6487580330413684606[6] = 1;
   out_6487580330413684606[7] = 0;
   out_6487580330413684606[8] = 0;
   out_6487580330413684606[9] = 0;
   out_6487580330413684606[10] = 0;
   out_6487580330413684606[11] = 0;
   out_6487580330413684606[12] = 0;
   out_6487580330413684606[13] = 0;
   out_6487580330413684606[14] = 0;
   out_6487580330413684606[15] = 0;
   out_6487580330413684606[16] = 0;
   out_6487580330413684606[17] = 0;
   out_6487580330413684606[18] = 0;
   out_6487580330413684606[19] = 0;
   out_6487580330413684606[20] = 0;
   out_6487580330413684606[21] = 0;
   out_6487580330413684606[22] = 0;
   out_6487580330413684606[23] = 0;
   out_6487580330413684606[24] = 0;
   out_6487580330413684606[25] = 1;
   out_6487580330413684606[26] = 0;
   out_6487580330413684606[27] = 0;
   out_6487580330413684606[28] = 0;
   out_6487580330413684606[29] = 0;
   out_6487580330413684606[30] = 0;
   out_6487580330413684606[31] = 0;
   out_6487580330413684606[32] = 0;
   out_6487580330413684606[33] = 0;
   out_6487580330413684606[34] = 0;
   out_6487580330413684606[35] = 0;
   out_6487580330413684606[36] = 0;
   out_6487580330413684606[37] = 0;
   out_6487580330413684606[38] = 0;
   out_6487580330413684606[39] = 0;
   out_6487580330413684606[40] = 0;
   out_6487580330413684606[41] = 0;
   out_6487580330413684606[42] = 0;
   out_6487580330413684606[43] = 0;
   out_6487580330413684606[44] = 1;
   out_6487580330413684606[45] = 0;
   out_6487580330413684606[46] = 0;
   out_6487580330413684606[47] = 0;
   out_6487580330413684606[48] = 0;
   out_6487580330413684606[49] = 0;
   out_6487580330413684606[50] = 0;
   out_6487580330413684606[51] = 0;
   out_6487580330413684606[52] = 0;
   out_6487580330413684606[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2822233615381903085) {
  err_fun(nom_x, delta_x, out_2822233615381903085);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3556797172859207138) {
  inv_err_fun(nom_x, true_x, out_3556797172859207138);
}
void pose_H_mod_fun(double *state, double *out_4158952900173024917) {
  H_mod_fun(state, out_4158952900173024917);
}
void pose_f_fun(double *state, double dt, double *out_4480310224533440205) {
  f_fun(state,  dt, out_4480310224533440205);
}
void pose_F_fun(double *state, double dt, double *out_2252133042369597057) {
  F_fun(state,  dt, out_2252133042369597057);
}
void pose_h_4(double *state, double *unused, double *out_1225931617160521679) {
  h_4(state, unused, out_1225931617160521679);
}
void pose_H_4(double *state, double *unused, double *out_3404791898118312310) {
  H_4(state, unused, out_3404791898118312310);
}
void pose_h_10(double *state, double *unused, double *out_8314558572170779017) {
  h_10(state, unused, out_8314558572170779017);
}
void pose_H_10(double *state, double *unused, double *out_3543553484029179274) {
  H_10(state, unused, out_3543553484029179274);
}
void pose_h_13(double *state, double *unused, double *out_7492025966781743409) {
  h_13(state, unused, out_7492025966781743409);
}
void pose_H_13(double *state, double *unused, double *out_4205839310198388619) {
  H_13(state, unused, out_4205839310198388619);
}
void pose_h_14(double *state, double *unused, double *out_8444019918627598165) {
  h_14(state, unused, out_8444019918627598165);
}
void pose_H_14(double *state, double *unused, double *out_6487580330413684606) {
  H_14(state, unused, out_6487580330413684606);
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
