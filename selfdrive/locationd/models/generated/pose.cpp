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
void err_fun(double *nom_x, double *delta_x, double *out_2889016141520795461) {
   out_2889016141520795461[0] = delta_x[0] + nom_x[0];
   out_2889016141520795461[1] = delta_x[1] + nom_x[1];
   out_2889016141520795461[2] = delta_x[2] + nom_x[2];
   out_2889016141520795461[3] = delta_x[3] + nom_x[3];
   out_2889016141520795461[4] = delta_x[4] + nom_x[4];
   out_2889016141520795461[5] = delta_x[5] + nom_x[5];
   out_2889016141520795461[6] = delta_x[6] + nom_x[6];
   out_2889016141520795461[7] = delta_x[7] + nom_x[7];
   out_2889016141520795461[8] = delta_x[8] + nom_x[8];
   out_2889016141520795461[9] = delta_x[9] + nom_x[9];
   out_2889016141520795461[10] = delta_x[10] + nom_x[10];
   out_2889016141520795461[11] = delta_x[11] + nom_x[11];
   out_2889016141520795461[12] = delta_x[12] + nom_x[12];
   out_2889016141520795461[13] = delta_x[13] + nom_x[13];
   out_2889016141520795461[14] = delta_x[14] + nom_x[14];
   out_2889016141520795461[15] = delta_x[15] + nom_x[15];
   out_2889016141520795461[16] = delta_x[16] + nom_x[16];
   out_2889016141520795461[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6586333085018065986) {
   out_6586333085018065986[0] = -nom_x[0] + true_x[0];
   out_6586333085018065986[1] = -nom_x[1] + true_x[1];
   out_6586333085018065986[2] = -nom_x[2] + true_x[2];
   out_6586333085018065986[3] = -nom_x[3] + true_x[3];
   out_6586333085018065986[4] = -nom_x[4] + true_x[4];
   out_6586333085018065986[5] = -nom_x[5] + true_x[5];
   out_6586333085018065986[6] = -nom_x[6] + true_x[6];
   out_6586333085018065986[7] = -nom_x[7] + true_x[7];
   out_6586333085018065986[8] = -nom_x[8] + true_x[8];
   out_6586333085018065986[9] = -nom_x[9] + true_x[9];
   out_6586333085018065986[10] = -nom_x[10] + true_x[10];
   out_6586333085018065986[11] = -nom_x[11] + true_x[11];
   out_6586333085018065986[12] = -nom_x[12] + true_x[12];
   out_6586333085018065986[13] = -nom_x[13] + true_x[13];
   out_6586333085018065986[14] = -nom_x[14] + true_x[14];
   out_6586333085018065986[15] = -nom_x[15] + true_x[15];
   out_6586333085018065986[16] = -nom_x[16] + true_x[16];
   out_6586333085018065986[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6984305438091048706) {
   out_6984305438091048706[0] = 1.0;
   out_6984305438091048706[1] = 0.0;
   out_6984305438091048706[2] = 0.0;
   out_6984305438091048706[3] = 0.0;
   out_6984305438091048706[4] = 0.0;
   out_6984305438091048706[5] = 0.0;
   out_6984305438091048706[6] = 0.0;
   out_6984305438091048706[7] = 0.0;
   out_6984305438091048706[8] = 0.0;
   out_6984305438091048706[9] = 0.0;
   out_6984305438091048706[10] = 0.0;
   out_6984305438091048706[11] = 0.0;
   out_6984305438091048706[12] = 0.0;
   out_6984305438091048706[13] = 0.0;
   out_6984305438091048706[14] = 0.0;
   out_6984305438091048706[15] = 0.0;
   out_6984305438091048706[16] = 0.0;
   out_6984305438091048706[17] = 0.0;
   out_6984305438091048706[18] = 0.0;
   out_6984305438091048706[19] = 1.0;
   out_6984305438091048706[20] = 0.0;
   out_6984305438091048706[21] = 0.0;
   out_6984305438091048706[22] = 0.0;
   out_6984305438091048706[23] = 0.0;
   out_6984305438091048706[24] = 0.0;
   out_6984305438091048706[25] = 0.0;
   out_6984305438091048706[26] = 0.0;
   out_6984305438091048706[27] = 0.0;
   out_6984305438091048706[28] = 0.0;
   out_6984305438091048706[29] = 0.0;
   out_6984305438091048706[30] = 0.0;
   out_6984305438091048706[31] = 0.0;
   out_6984305438091048706[32] = 0.0;
   out_6984305438091048706[33] = 0.0;
   out_6984305438091048706[34] = 0.0;
   out_6984305438091048706[35] = 0.0;
   out_6984305438091048706[36] = 0.0;
   out_6984305438091048706[37] = 0.0;
   out_6984305438091048706[38] = 1.0;
   out_6984305438091048706[39] = 0.0;
   out_6984305438091048706[40] = 0.0;
   out_6984305438091048706[41] = 0.0;
   out_6984305438091048706[42] = 0.0;
   out_6984305438091048706[43] = 0.0;
   out_6984305438091048706[44] = 0.0;
   out_6984305438091048706[45] = 0.0;
   out_6984305438091048706[46] = 0.0;
   out_6984305438091048706[47] = 0.0;
   out_6984305438091048706[48] = 0.0;
   out_6984305438091048706[49] = 0.0;
   out_6984305438091048706[50] = 0.0;
   out_6984305438091048706[51] = 0.0;
   out_6984305438091048706[52] = 0.0;
   out_6984305438091048706[53] = 0.0;
   out_6984305438091048706[54] = 0.0;
   out_6984305438091048706[55] = 0.0;
   out_6984305438091048706[56] = 0.0;
   out_6984305438091048706[57] = 1.0;
   out_6984305438091048706[58] = 0.0;
   out_6984305438091048706[59] = 0.0;
   out_6984305438091048706[60] = 0.0;
   out_6984305438091048706[61] = 0.0;
   out_6984305438091048706[62] = 0.0;
   out_6984305438091048706[63] = 0.0;
   out_6984305438091048706[64] = 0.0;
   out_6984305438091048706[65] = 0.0;
   out_6984305438091048706[66] = 0.0;
   out_6984305438091048706[67] = 0.0;
   out_6984305438091048706[68] = 0.0;
   out_6984305438091048706[69] = 0.0;
   out_6984305438091048706[70] = 0.0;
   out_6984305438091048706[71] = 0.0;
   out_6984305438091048706[72] = 0.0;
   out_6984305438091048706[73] = 0.0;
   out_6984305438091048706[74] = 0.0;
   out_6984305438091048706[75] = 0.0;
   out_6984305438091048706[76] = 1.0;
   out_6984305438091048706[77] = 0.0;
   out_6984305438091048706[78] = 0.0;
   out_6984305438091048706[79] = 0.0;
   out_6984305438091048706[80] = 0.0;
   out_6984305438091048706[81] = 0.0;
   out_6984305438091048706[82] = 0.0;
   out_6984305438091048706[83] = 0.0;
   out_6984305438091048706[84] = 0.0;
   out_6984305438091048706[85] = 0.0;
   out_6984305438091048706[86] = 0.0;
   out_6984305438091048706[87] = 0.0;
   out_6984305438091048706[88] = 0.0;
   out_6984305438091048706[89] = 0.0;
   out_6984305438091048706[90] = 0.0;
   out_6984305438091048706[91] = 0.0;
   out_6984305438091048706[92] = 0.0;
   out_6984305438091048706[93] = 0.0;
   out_6984305438091048706[94] = 0.0;
   out_6984305438091048706[95] = 1.0;
   out_6984305438091048706[96] = 0.0;
   out_6984305438091048706[97] = 0.0;
   out_6984305438091048706[98] = 0.0;
   out_6984305438091048706[99] = 0.0;
   out_6984305438091048706[100] = 0.0;
   out_6984305438091048706[101] = 0.0;
   out_6984305438091048706[102] = 0.0;
   out_6984305438091048706[103] = 0.0;
   out_6984305438091048706[104] = 0.0;
   out_6984305438091048706[105] = 0.0;
   out_6984305438091048706[106] = 0.0;
   out_6984305438091048706[107] = 0.0;
   out_6984305438091048706[108] = 0.0;
   out_6984305438091048706[109] = 0.0;
   out_6984305438091048706[110] = 0.0;
   out_6984305438091048706[111] = 0.0;
   out_6984305438091048706[112] = 0.0;
   out_6984305438091048706[113] = 0.0;
   out_6984305438091048706[114] = 1.0;
   out_6984305438091048706[115] = 0.0;
   out_6984305438091048706[116] = 0.0;
   out_6984305438091048706[117] = 0.0;
   out_6984305438091048706[118] = 0.0;
   out_6984305438091048706[119] = 0.0;
   out_6984305438091048706[120] = 0.0;
   out_6984305438091048706[121] = 0.0;
   out_6984305438091048706[122] = 0.0;
   out_6984305438091048706[123] = 0.0;
   out_6984305438091048706[124] = 0.0;
   out_6984305438091048706[125] = 0.0;
   out_6984305438091048706[126] = 0.0;
   out_6984305438091048706[127] = 0.0;
   out_6984305438091048706[128] = 0.0;
   out_6984305438091048706[129] = 0.0;
   out_6984305438091048706[130] = 0.0;
   out_6984305438091048706[131] = 0.0;
   out_6984305438091048706[132] = 0.0;
   out_6984305438091048706[133] = 1.0;
   out_6984305438091048706[134] = 0.0;
   out_6984305438091048706[135] = 0.0;
   out_6984305438091048706[136] = 0.0;
   out_6984305438091048706[137] = 0.0;
   out_6984305438091048706[138] = 0.0;
   out_6984305438091048706[139] = 0.0;
   out_6984305438091048706[140] = 0.0;
   out_6984305438091048706[141] = 0.0;
   out_6984305438091048706[142] = 0.0;
   out_6984305438091048706[143] = 0.0;
   out_6984305438091048706[144] = 0.0;
   out_6984305438091048706[145] = 0.0;
   out_6984305438091048706[146] = 0.0;
   out_6984305438091048706[147] = 0.0;
   out_6984305438091048706[148] = 0.0;
   out_6984305438091048706[149] = 0.0;
   out_6984305438091048706[150] = 0.0;
   out_6984305438091048706[151] = 0.0;
   out_6984305438091048706[152] = 1.0;
   out_6984305438091048706[153] = 0.0;
   out_6984305438091048706[154] = 0.0;
   out_6984305438091048706[155] = 0.0;
   out_6984305438091048706[156] = 0.0;
   out_6984305438091048706[157] = 0.0;
   out_6984305438091048706[158] = 0.0;
   out_6984305438091048706[159] = 0.0;
   out_6984305438091048706[160] = 0.0;
   out_6984305438091048706[161] = 0.0;
   out_6984305438091048706[162] = 0.0;
   out_6984305438091048706[163] = 0.0;
   out_6984305438091048706[164] = 0.0;
   out_6984305438091048706[165] = 0.0;
   out_6984305438091048706[166] = 0.0;
   out_6984305438091048706[167] = 0.0;
   out_6984305438091048706[168] = 0.0;
   out_6984305438091048706[169] = 0.0;
   out_6984305438091048706[170] = 0.0;
   out_6984305438091048706[171] = 1.0;
   out_6984305438091048706[172] = 0.0;
   out_6984305438091048706[173] = 0.0;
   out_6984305438091048706[174] = 0.0;
   out_6984305438091048706[175] = 0.0;
   out_6984305438091048706[176] = 0.0;
   out_6984305438091048706[177] = 0.0;
   out_6984305438091048706[178] = 0.0;
   out_6984305438091048706[179] = 0.0;
   out_6984305438091048706[180] = 0.0;
   out_6984305438091048706[181] = 0.0;
   out_6984305438091048706[182] = 0.0;
   out_6984305438091048706[183] = 0.0;
   out_6984305438091048706[184] = 0.0;
   out_6984305438091048706[185] = 0.0;
   out_6984305438091048706[186] = 0.0;
   out_6984305438091048706[187] = 0.0;
   out_6984305438091048706[188] = 0.0;
   out_6984305438091048706[189] = 0.0;
   out_6984305438091048706[190] = 1.0;
   out_6984305438091048706[191] = 0.0;
   out_6984305438091048706[192] = 0.0;
   out_6984305438091048706[193] = 0.0;
   out_6984305438091048706[194] = 0.0;
   out_6984305438091048706[195] = 0.0;
   out_6984305438091048706[196] = 0.0;
   out_6984305438091048706[197] = 0.0;
   out_6984305438091048706[198] = 0.0;
   out_6984305438091048706[199] = 0.0;
   out_6984305438091048706[200] = 0.0;
   out_6984305438091048706[201] = 0.0;
   out_6984305438091048706[202] = 0.0;
   out_6984305438091048706[203] = 0.0;
   out_6984305438091048706[204] = 0.0;
   out_6984305438091048706[205] = 0.0;
   out_6984305438091048706[206] = 0.0;
   out_6984305438091048706[207] = 0.0;
   out_6984305438091048706[208] = 0.0;
   out_6984305438091048706[209] = 1.0;
   out_6984305438091048706[210] = 0.0;
   out_6984305438091048706[211] = 0.0;
   out_6984305438091048706[212] = 0.0;
   out_6984305438091048706[213] = 0.0;
   out_6984305438091048706[214] = 0.0;
   out_6984305438091048706[215] = 0.0;
   out_6984305438091048706[216] = 0.0;
   out_6984305438091048706[217] = 0.0;
   out_6984305438091048706[218] = 0.0;
   out_6984305438091048706[219] = 0.0;
   out_6984305438091048706[220] = 0.0;
   out_6984305438091048706[221] = 0.0;
   out_6984305438091048706[222] = 0.0;
   out_6984305438091048706[223] = 0.0;
   out_6984305438091048706[224] = 0.0;
   out_6984305438091048706[225] = 0.0;
   out_6984305438091048706[226] = 0.0;
   out_6984305438091048706[227] = 0.0;
   out_6984305438091048706[228] = 1.0;
   out_6984305438091048706[229] = 0.0;
   out_6984305438091048706[230] = 0.0;
   out_6984305438091048706[231] = 0.0;
   out_6984305438091048706[232] = 0.0;
   out_6984305438091048706[233] = 0.0;
   out_6984305438091048706[234] = 0.0;
   out_6984305438091048706[235] = 0.0;
   out_6984305438091048706[236] = 0.0;
   out_6984305438091048706[237] = 0.0;
   out_6984305438091048706[238] = 0.0;
   out_6984305438091048706[239] = 0.0;
   out_6984305438091048706[240] = 0.0;
   out_6984305438091048706[241] = 0.0;
   out_6984305438091048706[242] = 0.0;
   out_6984305438091048706[243] = 0.0;
   out_6984305438091048706[244] = 0.0;
   out_6984305438091048706[245] = 0.0;
   out_6984305438091048706[246] = 0.0;
   out_6984305438091048706[247] = 1.0;
   out_6984305438091048706[248] = 0.0;
   out_6984305438091048706[249] = 0.0;
   out_6984305438091048706[250] = 0.0;
   out_6984305438091048706[251] = 0.0;
   out_6984305438091048706[252] = 0.0;
   out_6984305438091048706[253] = 0.0;
   out_6984305438091048706[254] = 0.0;
   out_6984305438091048706[255] = 0.0;
   out_6984305438091048706[256] = 0.0;
   out_6984305438091048706[257] = 0.0;
   out_6984305438091048706[258] = 0.0;
   out_6984305438091048706[259] = 0.0;
   out_6984305438091048706[260] = 0.0;
   out_6984305438091048706[261] = 0.0;
   out_6984305438091048706[262] = 0.0;
   out_6984305438091048706[263] = 0.0;
   out_6984305438091048706[264] = 0.0;
   out_6984305438091048706[265] = 0.0;
   out_6984305438091048706[266] = 1.0;
   out_6984305438091048706[267] = 0.0;
   out_6984305438091048706[268] = 0.0;
   out_6984305438091048706[269] = 0.0;
   out_6984305438091048706[270] = 0.0;
   out_6984305438091048706[271] = 0.0;
   out_6984305438091048706[272] = 0.0;
   out_6984305438091048706[273] = 0.0;
   out_6984305438091048706[274] = 0.0;
   out_6984305438091048706[275] = 0.0;
   out_6984305438091048706[276] = 0.0;
   out_6984305438091048706[277] = 0.0;
   out_6984305438091048706[278] = 0.0;
   out_6984305438091048706[279] = 0.0;
   out_6984305438091048706[280] = 0.0;
   out_6984305438091048706[281] = 0.0;
   out_6984305438091048706[282] = 0.0;
   out_6984305438091048706[283] = 0.0;
   out_6984305438091048706[284] = 0.0;
   out_6984305438091048706[285] = 1.0;
   out_6984305438091048706[286] = 0.0;
   out_6984305438091048706[287] = 0.0;
   out_6984305438091048706[288] = 0.0;
   out_6984305438091048706[289] = 0.0;
   out_6984305438091048706[290] = 0.0;
   out_6984305438091048706[291] = 0.0;
   out_6984305438091048706[292] = 0.0;
   out_6984305438091048706[293] = 0.0;
   out_6984305438091048706[294] = 0.0;
   out_6984305438091048706[295] = 0.0;
   out_6984305438091048706[296] = 0.0;
   out_6984305438091048706[297] = 0.0;
   out_6984305438091048706[298] = 0.0;
   out_6984305438091048706[299] = 0.0;
   out_6984305438091048706[300] = 0.0;
   out_6984305438091048706[301] = 0.0;
   out_6984305438091048706[302] = 0.0;
   out_6984305438091048706[303] = 0.0;
   out_6984305438091048706[304] = 1.0;
   out_6984305438091048706[305] = 0.0;
   out_6984305438091048706[306] = 0.0;
   out_6984305438091048706[307] = 0.0;
   out_6984305438091048706[308] = 0.0;
   out_6984305438091048706[309] = 0.0;
   out_6984305438091048706[310] = 0.0;
   out_6984305438091048706[311] = 0.0;
   out_6984305438091048706[312] = 0.0;
   out_6984305438091048706[313] = 0.0;
   out_6984305438091048706[314] = 0.0;
   out_6984305438091048706[315] = 0.0;
   out_6984305438091048706[316] = 0.0;
   out_6984305438091048706[317] = 0.0;
   out_6984305438091048706[318] = 0.0;
   out_6984305438091048706[319] = 0.0;
   out_6984305438091048706[320] = 0.0;
   out_6984305438091048706[321] = 0.0;
   out_6984305438091048706[322] = 0.0;
   out_6984305438091048706[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4187862153732757636) {
   out_4187862153732757636[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4187862153732757636[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4187862153732757636[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4187862153732757636[3] = dt*state[12] + state[3];
   out_4187862153732757636[4] = dt*state[13] + state[4];
   out_4187862153732757636[5] = dt*state[14] + state[5];
   out_4187862153732757636[6] = state[6];
   out_4187862153732757636[7] = state[7];
   out_4187862153732757636[8] = state[8];
   out_4187862153732757636[9] = state[9];
   out_4187862153732757636[10] = state[10];
   out_4187862153732757636[11] = state[11];
   out_4187862153732757636[12] = state[12];
   out_4187862153732757636[13] = state[13];
   out_4187862153732757636[14] = state[14];
   out_4187862153732757636[15] = state[15];
   out_4187862153732757636[16] = state[16];
   out_4187862153732757636[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7339590787986428927) {
   out_7339590787986428927[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7339590787986428927[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7339590787986428927[2] = 0;
   out_7339590787986428927[3] = 0;
   out_7339590787986428927[4] = 0;
   out_7339590787986428927[5] = 0;
   out_7339590787986428927[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7339590787986428927[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7339590787986428927[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7339590787986428927[9] = 0;
   out_7339590787986428927[10] = 0;
   out_7339590787986428927[11] = 0;
   out_7339590787986428927[12] = 0;
   out_7339590787986428927[13] = 0;
   out_7339590787986428927[14] = 0;
   out_7339590787986428927[15] = 0;
   out_7339590787986428927[16] = 0;
   out_7339590787986428927[17] = 0;
   out_7339590787986428927[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7339590787986428927[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7339590787986428927[20] = 0;
   out_7339590787986428927[21] = 0;
   out_7339590787986428927[22] = 0;
   out_7339590787986428927[23] = 0;
   out_7339590787986428927[24] = 0;
   out_7339590787986428927[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7339590787986428927[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7339590787986428927[27] = 0;
   out_7339590787986428927[28] = 0;
   out_7339590787986428927[29] = 0;
   out_7339590787986428927[30] = 0;
   out_7339590787986428927[31] = 0;
   out_7339590787986428927[32] = 0;
   out_7339590787986428927[33] = 0;
   out_7339590787986428927[34] = 0;
   out_7339590787986428927[35] = 0;
   out_7339590787986428927[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7339590787986428927[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7339590787986428927[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7339590787986428927[39] = 0;
   out_7339590787986428927[40] = 0;
   out_7339590787986428927[41] = 0;
   out_7339590787986428927[42] = 0;
   out_7339590787986428927[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7339590787986428927[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7339590787986428927[45] = 0;
   out_7339590787986428927[46] = 0;
   out_7339590787986428927[47] = 0;
   out_7339590787986428927[48] = 0;
   out_7339590787986428927[49] = 0;
   out_7339590787986428927[50] = 0;
   out_7339590787986428927[51] = 0;
   out_7339590787986428927[52] = 0;
   out_7339590787986428927[53] = 0;
   out_7339590787986428927[54] = 0;
   out_7339590787986428927[55] = 0;
   out_7339590787986428927[56] = 0;
   out_7339590787986428927[57] = 1;
   out_7339590787986428927[58] = 0;
   out_7339590787986428927[59] = 0;
   out_7339590787986428927[60] = 0;
   out_7339590787986428927[61] = 0;
   out_7339590787986428927[62] = 0;
   out_7339590787986428927[63] = 0;
   out_7339590787986428927[64] = 0;
   out_7339590787986428927[65] = 0;
   out_7339590787986428927[66] = dt;
   out_7339590787986428927[67] = 0;
   out_7339590787986428927[68] = 0;
   out_7339590787986428927[69] = 0;
   out_7339590787986428927[70] = 0;
   out_7339590787986428927[71] = 0;
   out_7339590787986428927[72] = 0;
   out_7339590787986428927[73] = 0;
   out_7339590787986428927[74] = 0;
   out_7339590787986428927[75] = 0;
   out_7339590787986428927[76] = 1;
   out_7339590787986428927[77] = 0;
   out_7339590787986428927[78] = 0;
   out_7339590787986428927[79] = 0;
   out_7339590787986428927[80] = 0;
   out_7339590787986428927[81] = 0;
   out_7339590787986428927[82] = 0;
   out_7339590787986428927[83] = 0;
   out_7339590787986428927[84] = 0;
   out_7339590787986428927[85] = dt;
   out_7339590787986428927[86] = 0;
   out_7339590787986428927[87] = 0;
   out_7339590787986428927[88] = 0;
   out_7339590787986428927[89] = 0;
   out_7339590787986428927[90] = 0;
   out_7339590787986428927[91] = 0;
   out_7339590787986428927[92] = 0;
   out_7339590787986428927[93] = 0;
   out_7339590787986428927[94] = 0;
   out_7339590787986428927[95] = 1;
   out_7339590787986428927[96] = 0;
   out_7339590787986428927[97] = 0;
   out_7339590787986428927[98] = 0;
   out_7339590787986428927[99] = 0;
   out_7339590787986428927[100] = 0;
   out_7339590787986428927[101] = 0;
   out_7339590787986428927[102] = 0;
   out_7339590787986428927[103] = 0;
   out_7339590787986428927[104] = dt;
   out_7339590787986428927[105] = 0;
   out_7339590787986428927[106] = 0;
   out_7339590787986428927[107] = 0;
   out_7339590787986428927[108] = 0;
   out_7339590787986428927[109] = 0;
   out_7339590787986428927[110] = 0;
   out_7339590787986428927[111] = 0;
   out_7339590787986428927[112] = 0;
   out_7339590787986428927[113] = 0;
   out_7339590787986428927[114] = 1;
   out_7339590787986428927[115] = 0;
   out_7339590787986428927[116] = 0;
   out_7339590787986428927[117] = 0;
   out_7339590787986428927[118] = 0;
   out_7339590787986428927[119] = 0;
   out_7339590787986428927[120] = 0;
   out_7339590787986428927[121] = 0;
   out_7339590787986428927[122] = 0;
   out_7339590787986428927[123] = 0;
   out_7339590787986428927[124] = 0;
   out_7339590787986428927[125] = 0;
   out_7339590787986428927[126] = 0;
   out_7339590787986428927[127] = 0;
   out_7339590787986428927[128] = 0;
   out_7339590787986428927[129] = 0;
   out_7339590787986428927[130] = 0;
   out_7339590787986428927[131] = 0;
   out_7339590787986428927[132] = 0;
   out_7339590787986428927[133] = 1;
   out_7339590787986428927[134] = 0;
   out_7339590787986428927[135] = 0;
   out_7339590787986428927[136] = 0;
   out_7339590787986428927[137] = 0;
   out_7339590787986428927[138] = 0;
   out_7339590787986428927[139] = 0;
   out_7339590787986428927[140] = 0;
   out_7339590787986428927[141] = 0;
   out_7339590787986428927[142] = 0;
   out_7339590787986428927[143] = 0;
   out_7339590787986428927[144] = 0;
   out_7339590787986428927[145] = 0;
   out_7339590787986428927[146] = 0;
   out_7339590787986428927[147] = 0;
   out_7339590787986428927[148] = 0;
   out_7339590787986428927[149] = 0;
   out_7339590787986428927[150] = 0;
   out_7339590787986428927[151] = 0;
   out_7339590787986428927[152] = 1;
   out_7339590787986428927[153] = 0;
   out_7339590787986428927[154] = 0;
   out_7339590787986428927[155] = 0;
   out_7339590787986428927[156] = 0;
   out_7339590787986428927[157] = 0;
   out_7339590787986428927[158] = 0;
   out_7339590787986428927[159] = 0;
   out_7339590787986428927[160] = 0;
   out_7339590787986428927[161] = 0;
   out_7339590787986428927[162] = 0;
   out_7339590787986428927[163] = 0;
   out_7339590787986428927[164] = 0;
   out_7339590787986428927[165] = 0;
   out_7339590787986428927[166] = 0;
   out_7339590787986428927[167] = 0;
   out_7339590787986428927[168] = 0;
   out_7339590787986428927[169] = 0;
   out_7339590787986428927[170] = 0;
   out_7339590787986428927[171] = 1;
   out_7339590787986428927[172] = 0;
   out_7339590787986428927[173] = 0;
   out_7339590787986428927[174] = 0;
   out_7339590787986428927[175] = 0;
   out_7339590787986428927[176] = 0;
   out_7339590787986428927[177] = 0;
   out_7339590787986428927[178] = 0;
   out_7339590787986428927[179] = 0;
   out_7339590787986428927[180] = 0;
   out_7339590787986428927[181] = 0;
   out_7339590787986428927[182] = 0;
   out_7339590787986428927[183] = 0;
   out_7339590787986428927[184] = 0;
   out_7339590787986428927[185] = 0;
   out_7339590787986428927[186] = 0;
   out_7339590787986428927[187] = 0;
   out_7339590787986428927[188] = 0;
   out_7339590787986428927[189] = 0;
   out_7339590787986428927[190] = 1;
   out_7339590787986428927[191] = 0;
   out_7339590787986428927[192] = 0;
   out_7339590787986428927[193] = 0;
   out_7339590787986428927[194] = 0;
   out_7339590787986428927[195] = 0;
   out_7339590787986428927[196] = 0;
   out_7339590787986428927[197] = 0;
   out_7339590787986428927[198] = 0;
   out_7339590787986428927[199] = 0;
   out_7339590787986428927[200] = 0;
   out_7339590787986428927[201] = 0;
   out_7339590787986428927[202] = 0;
   out_7339590787986428927[203] = 0;
   out_7339590787986428927[204] = 0;
   out_7339590787986428927[205] = 0;
   out_7339590787986428927[206] = 0;
   out_7339590787986428927[207] = 0;
   out_7339590787986428927[208] = 0;
   out_7339590787986428927[209] = 1;
   out_7339590787986428927[210] = 0;
   out_7339590787986428927[211] = 0;
   out_7339590787986428927[212] = 0;
   out_7339590787986428927[213] = 0;
   out_7339590787986428927[214] = 0;
   out_7339590787986428927[215] = 0;
   out_7339590787986428927[216] = 0;
   out_7339590787986428927[217] = 0;
   out_7339590787986428927[218] = 0;
   out_7339590787986428927[219] = 0;
   out_7339590787986428927[220] = 0;
   out_7339590787986428927[221] = 0;
   out_7339590787986428927[222] = 0;
   out_7339590787986428927[223] = 0;
   out_7339590787986428927[224] = 0;
   out_7339590787986428927[225] = 0;
   out_7339590787986428927[226] = 0;
   out_7339590787986428927[227] = 0;
   out_7339590787986428927[228] = 1;
   out_7339590787986428927[229] = 0;
   out_7339590787986428927[230] = 0;
   out_7339590787986428927[231] = 0;
   out_7339590787986428927[232] = 0;
   out_7339590787986428927[233] = 0;
   out_7339590787986428927[234] = 0;
   out_7339590787986428927[235] = 0;
   out_7339590787986428927[236] = 0;
   out_7339590787986428927[237] = 0;
   out_7339590787986428927[238] = 0;
   out_7339590787986428927[239] = 0;
   out_7339590787986428927[240] = 0;
   out_7339590787986428927[241] = 0;
   out_7339590787986428927[242] = 0;
   out_7339590787986428927[243] = 0;
   out_7339590787986428927[244] = 0;
   out_7339590787986428927[245] = 0;
   out_7339590787986428927[246] = 0;
   out_7339590787986428927[247] = 1;
   out_7339590787986428927[248] = 0;
   out_7339590787986428927[249] = 0;
   out_7339590787986428927[250] = 0;
   out_7339590787986428927[251] = 0;
   out_7339590787986428927[252] = 0;
   out_7339590787986428927[253] = 0;
   out_7339590787986428927[254] = 0;
   out_7339590787986428927[255] = 0;
   out_7339590787986428927[256] = 0;
   out_7339590787986428927[257] = 0;
   out_7339590787986428927[258] = 0;
   out_7339590787986428927[259] = 0;
   out_7339590787986428927[260] = 0;
   out_7339590787986428927[261] = 0;
   out_7339590787986428927[262] = 0;
   out_7339590787986428927[263] = 0;
   out_7339590787986428927[264] = 0;
   out_7339590787986428927[265] = 0;
   out_7339590787986428927[266] = 1;
   out_7339590787986428927[267] = 0;
   out_7339590787986428927[268] = 0;
   out_7339590787986428927[269] = 0;
   out_7339590787986428927[270] = 0;
   out_7339590787986428927[271] = 0;
   out_7339590787986428927[272] = 0;
   out_7339590787986428927[273] = 0;
   out_7339590787986428927[274] = 0;
   out_7339590787986428927[275] = 0;
   out_7339590787986428927[276] = 0;
   out_7339590787986428927[277] = 0;
   out_7339590787986428927[278] = 0;
   out_7339590787986428927[279] = 0;
   out_7339590787986428927[280] = 0;
   out_7339590787986428927[281] = 0;
   out_7339590787986428927[282] = 0;
   out_7339590787986428927[283] = 0;
   out_7339590787986428927[284] = 0;
   out_7339590787986428927[285] = 1;
   out_7339590787986428927[286] = 0;
   out_7339590787986428927[287] = 0;
   out_7339590787986428927[288] = 0;
   out_7339590787986428927[289] = 0;
   out_7339590787986428927[290] = 0;
   out_7339590787986428927[291] = 0;
   out_7339590787986428927[292] = 0;
   out_7339590787986428927[293] = 0;
   out_7339590787986428927[294] = 0;
   out_7339590787986428927[295] = 0;
   out_7339590787986428927[296] = 0;
   out_7339590787986428927[297] = 0;
   out_7339590787986428927[298] = 0;
   out_7339590787986428927[299] = 0;
   out_7339590787986428927[300] = 0;
   out_7339590787986428927[301] = 0;
   out_7339590787986428927[302] = 0;
   out_7339590787986428927[303] = 0;
   out_7339590787986428927[304] = 1;
   out_7339590787986428927[305] = 0;
   out_7339590787986428927[306] = 0;
   out_7339590787986428927[307] = 0;
   out_7339590787986428927[308] = 0;
   out_7339590787986428927[309] = 0;
   out_7339590787986428927[310] = 0;
   out_7339590787986428927[311] = 0;
   out_7339590787986428927[312] = 0;
   out_7339590787986428927[313] = 0;
   out_7339590787986428927[314] = 0;
   out_7339590787986428927[315] = 0;
   out_7339590787986428927[316] = 0;
   out_7339590787986428927[317] = 0;
   out_7339590787986428927[318] = 0;
   out_7339590787986428927[319] = 0;
   out_7339590787986428927[320] = 0;
   out_7339590787986428927[321] = 0;
   out_7339590787986428927[322] = 0;
   out_7339590787986428927[323] = 1;
}
void h_4(double *state, double *unused, double *out_8608741357917418213) {
   out_8608741357917418213[0] = state[6] + state[9];
   out_8608741357917418213[1] = state[7] + state[10];
   out_8608741357917418213[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8804004163997345567) {
   out_8804004163997345567[0] = 0;
   out_8804004163997345567[1] = 0;
   out_8804004163997345567[2] = 0;
   out_8804004163997345567[3] = 0;
   out_8804004163997345567[4] = 0;
   out_8804004163997345567[5] = 0;
   out_8804004163997345567[6] = 1;
   out_8804004163997345567[7] = 0;
   out_8804004163997345567[8] = 0;
   out_8804004163997345567[9] = 1;
   out_8804004163997345567[10] = 0;
   out_8804004163997345567[11] = 0;
   out_8804004163997345567[12] = 0;
   out_8804004163997345567[13] = 0;
   out_8804004163997345567[14] = 0;
   out_8804004163997345567[15] = 0;
   out_8804004163997345567[16] = 0;
   out_8804004163997345567[17] = 0;
   out_8804004163997345567[18] = 0;
   out_8804004163997345567[19] = 0;
   out_8804004163997345567[20] = 0;
   out_8804004163997345567[21] = 0;
   out_8804004163997345567[22] = 0;
   out_8804004163997345567[23] = 0;
   out_8804004163997345567[24] = 0;
   out_8804004163997345567[25] = 1;
   out_8804004163997345567[26] = 0;
   out_8804004163997345567[27] = 0;
   out_8804004163997345567[28] = 1;
   out_8804004163997345567[29] = 0;
   out_8804004163997345567[30] = 0;
   out_8804004163997345567[31] = 0;
   out_8804004163997345567[32] = 0;
   out_8804004163997345567[33] = 0;
   out_8804004163997345567[34] = 0;
   out_8804004163997345567[35] = 0;
   out_8804004163997345567[36] = 0;
   out_8804004163997345567[37] = 0;
   out_8804004163997345567[38] = 0;
   out_8804004163997345567[39] = 0;
   out_8804004163997345567[40] = 0;
   out_8804004163997345567[41] = 0;
   out_8804004163997345567[42] = 0;
   out_8804004163997345567[43] = 0;
   out_8804004163997345567[44] = 1;
   out_8804004163997345567[45] = 0;
   out_8804004163997345567[46] = 0;
   out_8804004163997345567[47] = 1;
   out_8804004163997345567[48] = 0;
   out_8804004163997345567[49] = 0;
   out_8804004163997345567[50] = 0;
   out_8804004163997345567[51] = 0;
   out_8804004163997345567[52] = 0;
   out_8804004163997345567[53] = 0;
}
void h_10(double *state, double *unused, double *out_4067868698993544544) {
   out_4067868698993544544[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4067868698993544544[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4067868698993544544[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6538171315605639203) {
   out_6538171315605639203[0] = 0;
   out_6538171315605639203[1] = 9.8100000000000005*cos(state[1]);
   out_6538171315605639203[2] = 0;
   out_6538171315605639203[3] = 0;
   out_6538171315605639203[4] = -state[8];
   out_6538171315605639203[5] = state[7];
   out_6538171315605639203[6] = 0;
   out_6538171315605639203[7] = state[5];
   out_6538171315605639203[8] = -state[4];
   out_6538171315605639203[9] = 0;
   out_6538171315605639203[10] = 0;
   out_6538171315605639203[11] = 0;
   out_6538171315605639203[12] = 1;
   out_6538171315605639203[13] = 0;
   out_6538171315605639203[14] = 0;
   out_6538171315605639203[15] = 1;
   out_6538171315605639203[16] = 0;
   out_6538171315605639203[17] = 0;
   out_6538171315605639203[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6538171315605639203[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6538171315605639203[20] = 0;
   out_6538171315605639203[21] = state[8];
   out_6538171315605639203[22] = 0;
   out_6538171315605639203[23] = -state[6];
   out_6538171315605639203[24] = -state[5];
   out_6538171315605639203[25] = 0;
   out_6538171315605639203[26] = state[3];
   out_6538171315605639203[27] = 0;
   out_6538171315605639203[28] = 0;
   out_6538171315605639203[29] = 0;
   out_6538171315605639203[30] = 0;
   out_6538171315605639203[31] = 1;
   out_6538171315605639203[32] = 0;
   out_6538171315605639203[33] = 0;
   out_6538171315605639203[34] = 1;
   out_6538171315605639203[35] = 0;
   out_6538171315605639203[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6538171315605639203[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6538171315605639203[38] = 0;
   out_6538171315605639203[39] = -state[7];
   out_6538171315605639203[40] = state[6];
   out_6538171315605639203[41] = 0;
   out_6538171315605639203[42] = state[4];
   out_6538171315605639203[43] = -state[3];
   out_6538171315605639203[44] = 0;
   out_6538171315605639203[45] = 0;
   out_6538171315605639203[46] = 0;
   out_6538171315605639203[47] = 0;
   out_6538171315605639203[48] = 0;
   out_6538171315605639203[49] = 0;
   out_6538171315605639203[50] = 1;
   out_6538171315605639203[51] = 0;
   out_6538171315605639203[52] = 0;
   out_6538171315605639203[53] = 1;
}
void h_13(double *state, double *unused, double *out_1704356913043206317) {
   out_1704356913043206317[0] = state[3];
   out_1704356913043206317[1] = state[4];
   out_1704356913043206317[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5591730338665012766) {
   out_5591730338665012766[0] = 0;
   out_5591730338665012766[1] = 0;
   out_5591730338665012766[2] = 0;
   out_5591730338665012766[3] = 1;
   out_5591730338665012766[4] = 0;
   out_5591730338665012766[5] = 0;
   out_5591730338665012766[6] = 0;
   out_5591730338665012766[7] = 0;
   out_5591730338665012766[8] = 0;
   out_5591730338665012766[9] = 0;
   out_5591730338665012766[10] = 0;
   out_5591730338665012766[11] = 0;
   out_5591730338665012766[12] = 0;
   out_5591730338665012766[13] = 0;
   out_5591730338665012766[14] = 0;
   out_5591730338665012766[15] = 0;
   out_5591730338665012766[16] = 0;
   out_5591730338665012766[17] = 0;
   out_5591730338665012766[18] = 0;
   out_5591730338665012766[19] = 0;
   out_5591730338665012766[20] = 0;
   out_5591730338665012766[21] = 0;
   out_5591730338665012766[22] = 1;
   out_5591730338665012766[23] = 0;
   out_5591730338665012766[24] = 0;
   out_5591730338665012766[25] = 0;
   out_5591730338665012766[26] = 0;
   out_5591730338665012766[27] = 0;
   out_5591730338665012766[28] = 0;
   out_5591730338665012766[29] = 0;
   out_5591730338665012766[30] = 0;
   out_5591730338665012766[31] = 0;
   out_5591730338665012766[32] = 0;
   out_5591730338665012766[33] = 0;
   out_5591730338665012766[34] = 0;
   out_5591730338665012766[35] = 0;
   out_5591730338665012766[36] = 0;
   out_5591730338665012766[37] = 0;
   out_5591730338665012766[38] = 0;
   out_5591730338665012766[39] = 0;
   out_5591730338665012766[40] = 0;
   out_5591730338665012766[41] = 1;
   out_5591730338665012766[42] = 0;
   out_5591730338665012766[43] = 0;
   out_5591730338665012766[44] = 0;
   out_5591730338665012766[45] = 0;
   out_5591730338665012766[46] = 0;
   out_5591730338665012766[47] = 0;
   out_5591730338665012766[48] = 0;
   out_5591730338665012766[49] = 0;
   out_5591730338665012766[50] = 0;
   out_5591730338665012766[51] = 0;
   out_5591730338665012766[52] = 0;
   out_5591730338665012766[53] = 0;
}
void h_14(double *state, double *unused, double *out_5410919187051701678) {
   out_5410919187051701678[0] = state[6];
   out_5410919187051701678[1] = state[7];
   out_5410919187051701678[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4840763307657861038) {
   out_4840763307657861038[0] = 0;
   out_4840763307657861038[1] = 0;
   out_4840763307657861038[2] = 0;
   out_4840763307657861038[3] = 0;
   out_4840763307657861038[4] = 0;
   out_4840763307657861038[5] = 0;
   out_4840763307657861038[6] = 1;
   out_4840763307657861038[7] = 0;
   out_4840763307657861038[8] = 0;
   out_4840763307657861038[9] = 0;
   out_4840763307657861038[10] = 0;
   out_4840763307657861038[11] = 0;
   out_4840763307657861038[12] = 0;
   out_4840763307657861038[13] = 0;
   out_4840763307657861038[14] = 0;
   out_4840763307657861038[15] = 0;
   out_4840763307657861038[16] = 0;
   out_4840763307657861038[17] = 0;
   out_4840763307657861038[18] = 0;
   out_4840763307657861038[19] = 0;
   out_4840763307657861038[20] = 0;
   out_4840763307657861038[21] = 0;
   out_4840763307657861038[22] = 0;
   out_4840763307657861038[23] = 0;
   out_4840763307657861038[24] = 0;
   out_4840763307657861038[25] = 1;
   out_4840763307657861038[26] = 0;
   out_4840763307657861038[27] = 0;
   out_4840763307657861038[28] = 0;
   out_4840763307657861038[29] = 0;
   out_4840763307657861038[30] = 0;
   out_4840763307657861038[31] = 0;
   out_4840763307657861038[32] = 0;
   out_4840763307657861038[33] = 0;
   out_4840763307657861038[34] = 0;
   out_4840763307657861038[35] = 0;
   out_4840763307657861038[36] = 0;
   out_4840763307657861038[37] = 0;
   out_4840763307657861038[38] = 0;
   out_4840763307657861038[39] = 0;
   out_4840763307657861038[40] = 0;
   out_4840763307657861038[41] = 0;
   out_4840763307657861038[42] = 0;
   out_4840763307657861038[43] = 0;
   out_4840763307657861038[44] = 1;
   out_4840763307657861038[45] = 0;
   out_4840763307657861038[46] = 0;
   out_4840763307657861038[47] = 0;
   out_4840763307657861038[48] = 0;
   out_4840763307657861038[49] = 0;
   out_4840763307657861038[50] = 0;
   out_4840763307657861038[51] = 0;
   out_4840763307657861038[52] = 0;
   out_4840763307657861038[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2889016141520795461) {
  err_fun(nom_x, delta_x, out_2889016141520795461);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6586333085018065986) {
  inv_err_fun(nom_x, true_x, out_6586333085018065986);
}
void pose_H_mod_fun(double *state, double *out_6984305438091048706) {
  H_mod_fun(state, out_6984305438091048706);
}
void pose_f_fun(double *state, double dt, double *out_4187862153732757636) {
  f_fun(state,  dt, out_4187862153732757636);
}
void pose_F_fun(double *state, double dt, double *out_7339590787986428927) {
  F_fun(state,  dt, out_7339590787986428927);
}
void pose_h_4(double *state, double *unused, double *out_8608741357917418213) {
  h_4(state, unused, out_8608741357917418213);
}
void pose_H_4(double *state, double *unused, double *out_8804004163997345567) {
  H_4(state, unused, out_8804004163997345567);
}
void pose_h_10(double *state, double *unused, double *out_4067868698993544544) {
  h_10(state, unused, out_4067868698993544544);
}
void pose_H_10(double *state, double *unused, double *out_6538171315605639203) {
  H_10(state, unused, out_6538171315605639203);
}
void pose_h_13(double *state, double *unused, double *out_1704356913043206317) {
  h_13(state, unused, out_1704356913043206317);
}
void pose_H_13(double *state, double *unused, double *out_5591730338665012766) {
  H_13(state, unused, out_5591730338665012766);
}
void pose_h_14(double *state, double *unused, double *out_5410919187051701678) {
  h_14(state, unused, out_5410919187051701678);
}
void pose_H_14(double *state, double *unused, double *out_4840763307657861038) {
  H_14(state, unused, out_4840763307657861038);
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
