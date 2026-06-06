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
void err_fun(double *nom_x, double *delta_x, double *out_609976965150865312) {
   out_609976965150865312[0] = delta_x[0] + nom_x[0];
   out_609976965150865312[1] = delta_x[1] + nom_x[1];
   out_609976965150865312[2] = delta_x[2] + nom_x[2];
   out_609976965150865312[3] = delta_x[3] + nom_x[3];
   out_609976965150865312[4] = delta_x[4] + nom_x[4];
   out_609976965150865312[5] = delta_x[5] + nom_x[5];
   out_609976965150865312[6] = delta_x[6] + nom_x[6];
   out_609976965150865312[7] = delta_x[7] + nom_x[7];
   out_609976965150865312[8] = delta_x[8] + nom_x[8];
   out_609976965150865312[9] = delta_x[9] + nom_x[9];
   out_609976965150865312[10] = delta_x[10] + nom_x[10];
   out_609976965150865312[11] = delta_x[11] + nom_x[11];
   out_609976965150865312[12] = delta_x[12] + nom_x[12];
   out_609976965150865312[13] = delta_x[13] + nom_x[13];
   out_609976965150865312[14] = delta_x[14] + nom_x[14];
   out_609976965150865312[15] = delta_x[15] + nom_x[15];
   out_609976965150865312[16] = delta_x[16] + nom_x[16];
   out_609976965150865312[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8281732551506992950) {
   out_8281732551506992950[0] = -nom_x[0] + true_x[0];
   out_8281732551506992950[1] = -nom_x[1] + true_x[1];
   out_8281732551506992950[2] = -nom_x[2] + true_x[2];
   out_8281732551506992950[3] = -nom_x[3] + true_x[3];
   out_8281732551506992950[4] = -nom_x[4] + true_x[4];
   out_8281732551506992950[5] = -nom_x[5] + true_x[5];
   out_8281732551506992950[6] = -nom_x[6] + true_x[6];
   out_8281732551506992950[7] = -nom_x[7] + true_x[7];
   out_8281732551506992950[8] = -nom_x[8] + true_x[8];
   out_8281732551506992950[9] = -nom_x[9] + true_x[9];
   out_8281732551506992950[10] = -nom_x[10] + true_x[10];
   out_8281732551506992950[11] = -nom_x[11] + true_x[11];
   out_8281732551506992950[12] = -nom_x[12] + true_x[12];
   out_8281732551506992950[13] = -nom_x[13] + true_x[13];
   out_8281732551506992950[14] = -nom_x[14] + true_x[14];
   out_8281732551506992950[15] = -nom_x[15] + true_x[15];
   out_8281732551506992950[16] = -nom_x[16] + true_x[16];
   out_8281732551506992950[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4168561321210011185) {
   out_4168561321210011185[0] = 1.0;
   out_4168561321210011185[1] = 0.0;
   out_4168561321210011185[2] = 0.0;
   out_4168561321210011185[3] = 0.0;
   out_4168561321210011185[4] = 0.0;
   out_4168561321210011185[5] = 0.0;
   out_4168561321210011185[6] = 0.0;
   out_4168561321210011185[7] = 0.0;
   out_4168561321210011185[8] = 0.0;
   out_4168561321210011185[9] = 0.0;
   out_4168561321210011185[10] = 0.0;
   out_4168561321210011185[11] = 0.0;
   out_4168561321210011185[12] = 0.0;
   out_4168561321210011185[13] = 0.0;
   out_4168561321210011185[14] = 0.0;
   out_4168561321210011185[15] = 0.0;
   out_4168561321210011185[16] = 0.0;
   out_4168561321210011185[17] = 0.0;
   out_4168561321210011185[18] = 0.0;
   out_4168561321210011185[19] = 1.0;
   out_4168561321210011185[20] = 0.0;
   out_4168561321210011185[21] = 0.0;
   out_4168561321210011185[22] = 0.0;
   out_4168561321210011185[23] = 0.0;
   out_4168561321210011185[24] = 0.0;
   out_4168561321210011185[25] = 0.0;
   out_4168561321210011185[26] = 0.0;
   out_4168561321210011185[27] = 0.0;
   out_4168561321210011185[28] = 0.0;
   out_4168561321210011185[29] = 0.0;
   out_4168561321210011185[30] = 0.0;
   out_4168561321210011185[31] = 0.0;
   out_4168561321210011185[32] = 0.0;
   out_4168561321210011185[33] = 0.0;
   out_4168561321210011185[34] = 0.0;
   out_4168561321210011185[35] = 0.0;
   out_4168561321210011185[36] = 0.0;
   out_4168561321210011185[37] = 0.0;
   out_4168561321210011185[38] = 1.0;
   out_4168561321210011185[39] = 0.0;
   out_4168561321210011185[40] = 0.0;
   out_4168561321210011185[41] = 0.0;
   out_4168561321210011185[42] = 0.0;
   out_4168561321210011185[43] = 0.0;
   out_4168561321210011185[44] = 0.0;
   out_4168561321210011185[45] = 0.0;
   out_4168561321210011185[46] = 0.0;
   out_4168561321210011185[47] = 0.0;
   out_4168561321210011185[48] = 0.0;
   out_4168561321210011185[49] = 0.0;
   out_4168561321210011185[50] = 0.0;
   out_4168561321210011185[51] = 0.0;
   out_4168561321210011185[52] = 0.0;
   out_4168561321210011185[53] = 0.0;
   out_4168561321210011185[54] = 0.0;
   out_4168561321210011185[55] = 0.0;
   out_4168561321210011185[56] = 0.0;
   out_4168561321210011185[57] = 1.0;
   out_4168561321210011185[58] = 0.0;
   out_4168561321210011185[59] = 0.0;
   out_4168561321210011185[60] = 0.0;
   out_4168561321210011185[61] = 0.0;
   out_4168561321210011185[62] = 0.0;
   out_4168561321210011185[63] = 0.0;
   out_4168561321210011185[64] = 0.0;
   out_4168561321210011185[65] = 0.0;
   out_4168561321210011185[66] = 0.0;
   out_4168561321210011185[67] = 0.0;
   out_4168561321210011185[68] = 0.0;
   out_4168561321210011185[69] = 0.0;
   out_4168561321210011185[70] = 0.0;
   out_4168561321210011185[71] = 0.0;
   out_4168561321210011185[72] = 0.0;
   out_4168561321210011185[73] = 0.0;
   out_4168561321210011185[74] = 0.0;
   out_4168561321210011185[75] = 0.0;
   out_4168561321210011185[76] = 1.0;
   out_4168561321210011185[77] = 0.0;
   out_4168561321210011185[78] = 0.0;
   out_4168561321210011185[79] = 0.0;
   out_4168561321210011185[80] = 0.0;
   out_4168561321210011185[81] = 0.0;
   out_4168561321210011185[82] = 0.0;
   out_4168561321210011185[83] = 0.0;
   out_4168561321210011185[84] = 0.0;
   out_4168561321210011185[85] = 0.0;
   out_4168561321210011185[86] = 0.0;
   out_4168561321210011185[87] = 0.0;
   out_4168561321210011185[88] = 0.0;
   out_4168561321210011185[89] = 0.0;
   out_4168561321210011185[90] = 0.0;
   out_4168561321210011185[91] = 0.0;
   out_4168561321210011185[92] = 0.0;
   out_4168561321210011185[93] = 0.0;
   out_4168561321210011185[94] = 0.0;
   out_4168561321210011185[95] = 1.0;
   out_4168561321210011185[96] = 0.0;
   out_4168561321210011185[97] = 0.0;
   out_4168561321210011185[98] = 0.0;
   out_4168561321210011185[99] = 0.0;
   out_4168561321210011185[100] = 0.0;
   out_4168561321210011185[101] = 0.0;
   out_4168561321210011185[102] = 0.0;
   out_4168561321210011185[103] = 0.0;
   out_4168561321210011185[104] = 0.0;
   out_4168561321210011185[105] = 0.0;
   out_4168561321210011185[106] = 0.0;
   out_4168561321210011185[107] = 0.0;
   out_4168561321210011185[108] = 0.0;
   out_4168561321210011185[109] = 0.0;
   out_4168561321210011185[110] = 0.0;
   out_4168561321210011185[111] = 0.0;
   out_4168561321210011185[112] = 0.0;
   out_4168561321210011185[113] = 0.0;
   out_4168561321210011185[114] = 1.0;
   out_4168561321210011185[115] = 0.0;
   out_4168561321210011185[116] = 0.0;
   out_4168561321210011185[117] = 0.0;
   out_4168561321210011185[118] = 0.0;
   out_4168561321210011185[119] = 0.0;
   out_4168561321210011185[120] = 0.0;
   out_4168561321210011185[121] = 0.0;
   out_4168561321210011185[122] = 0.0;
   out_4168561321210011185[123] = 0.0;
   out_4168561321210011185[124] = 0.0;
   out_4168561321210011185[125] = 0.0;
   out_4168561321210011185[126] = 0.0;
   out_4168561321210011185[127] = 0.0;
   out_4168561321210011185[128] = 0.0;
   out_4168561321210011185[129] = 0.0;
   out_4168561321210011185[130] = 0.0;
   out_4168561321210011185[131] = 0.0;
   out_4168561321210011185[132] = 0.0;
   out_4168561321210011185[133] = 1.0;
   out_4168561321210011185[134] = 0.0;
   out_4168561321210011185[135] = 0.0;
   out_4168561321210011185[136] = 0.0;
   out_4168561321210011185[137] = 0.0;
   out_4168561321210011185[138] = 0.0;
   out_4168561321210011185[139] = 0.0;
   out_4168561321210011185[140] = 0.0;
   out_4168561321210011185[141] = 0.0;
   out_4168561321210011185[142] = 0.0;
   out_4168561321210011185[143] = 0.0;
   out_4168561321210011185[144] = 0.0;
   out_4168561321210011185[145] = 0.0;
   out_4168561321210011185[146] = 0.0;
   out_4168561321210011185[147] = 0.0;
   out_4168561321210011185[148] = 0.0;
   out_4168561321210011185[149] = 0.0;
   out_4168561321210011185[150] = 0.0;
   out_4168561321210011185[151] = 0.0;
   out_4168561321210011185[152] = 1.0;
   out_4168561321210011185[153] = 0.0;
   out_4168561321210011185[154] = 0.0;
   out_4168561321210011185[155] = 0.0;
   out_4168561321210011185[156] = 0.0;
   out_4168561321210011185[157] = 0.0;
   out_4168561321210011185[158] = 0.0;
   out_4168561321210011185[159] = 0.0;
   out_4168561321210011185[160] = 0.0;
   out_4168561321210011185[161] = 0.0;
   out_4168561321210011185[162] = 0.0;
   out_4168561321210011185[163] = 0.0;
   out_4168561321210011185[164] = 0.0;
   out_4168561321210011185[165] = 0.0;
   out_4168561321210011185[166] = 0.0;
   out_4168561321210011185[167] = 0.0;
   out_4168561321210011185[168] = 0.0;
   out_4168561321210011185[169] = 0.0;
   out_4168561321210011185[170] = 0.0;
   out_4168561321210011185[171] = 1.0;
   out_4168561321210011185[172] = 0.0;
   out_4168561321210011185[173] = 0.0;
   out_4168561321210011185[174] = 0.0;
   out_4168561321210011185[175] = 0.0;
   out_4168561321210011185[176] = 0.0;
   out_4168561321210011185[177] = 0.0;
   out_4168561321210011185[178] = 0.0;
   out_4168561321210011185[179] = 0.0;
   out_4168561321210011185[180] = 0.0;
   out_4168561321210011185[181] = 0.0;
   out_4168561321210011185[182] = 0.0;
   out_4168561321210011185[183] = 0.0;
   out_4168561321210011185[184] = 0.0;
   out_4168561321210011185[185] = 0.0;
   out_4168561321210011185[186] = 0.0;
   out_4168561321210011185[187] = 0.0;
   out_4168561321210011185[188] = 0.0;
   out_4168561321210011185[189] = 0.0;
   out_4168561321210011185[190] = 1.0;
   out_4168561321210011185[191] = 0.0;
   out_4168561321210011185[192] = 0.0;
   out_4168561321210011185[193] = 0.0;
   out_4168561321210011185[194] = 0.0;
   out_4168561321210011185[195] = 0.0;
   out_4168561321210011185[196] = 0.0;
   out_4168561321210011185[197] = 0.0;
   out_4168561321210011185[198] = 0.0;
   out_4168561321210011185[199] = 0.0;
   out_4168561321210011185[200] = 0.0;
   out_4168561321210011185[201] = 0.0;
   out_4168561321210011185[202] = 0.0;
   out_4168561321210011185[203] = 0.0;
   out_4168561321210011185[204] = 0.0;
   out_4168561321210011185[205] = 0.0;
   out_4168561321210011185[206] = 0.0;
   out_4168561321210011185[207] = 0.0;
   out_4168561321210011185[208] = 0.0;
   out_4168561321210011185[209] = 1.0;
   out_4168561321210011185[210] = 0.0;
   out_4168561321210011185[211] = 0.0;
   out_4168561321210011185[212] = 0.0;
   out_4168561321210011185[213] = 0.0;
   out_4168561321210011185[214] = 0.0;
   out_4168561321210011185[215] = 0.0;
   out_4168561321210011185[216] = 0.0;
   out_4168561321210011185[217] = 0.0;
   out_4168561321210011185[218] = 0.0;
   out_4168561321210011185[219] = 0.0;
   out_4168561321210011185[220] = 0.0;
   out_4168561321210011185[221] = 0.0;
   out_4168561321210011185[222] = 0.0;
   out_4168561321210011185[223] = 0.0;
   out_4168561321210011185[224] = 0.0;
   out_4168561321210011185[225] = 0.0;
   out_4168561321210011185[226] = 0.0;
   out_4168561321210011185[227] = 0.0;
   out_4168561321210011185[228] = 1.0;
   out_4168561321210011185[229] = 0.0;
   out_4168561321210011185[230] = 0.0;
   out_4168561321210011185[231] = 0.0;
   out_4168561321210011185[232] = 0.0;
   out_4168561321210011185[233] = 0.0;
   out_4168561321210011185[234] = 0.0;
   out_4168561321210011185[235] = 0.0;
   out_4168561321210011185[236] = 0.0;
   out_4168561321210011185[237] = 0.0;
   out_4168561321210011185[238] = 0.0;
   out_4168561321210011185[239] = 0.0;
   out_4168561321210011185[240] = 0.0;
   out_4168561321210011185[241] = 0.0;
   out_4168561321210011185[242] = 0.0;
   out_4168561321210011185[243] = 0.0;
   out_4168561321210011185[244] = 0.0;
   out_4168561321210011185[245] = 0.0;
   out_4168561321210011185[246] = 0.0;
   out_4168561321210011185[247] = 1.0;
   out_4168561321210011185[248] = 0.0;
   out_4168561321210011185[249] = 0.0;
   out_4168561321210011185[250] = 0.0;
   out_4168561321210011185[251] = 0.0;
   out_4168561321210011185[252] = 0.0;
   out_4168561321210011185[253] = 0.0;
   out_4168561321210011185[254] = 0.0;
   out_4168561321210011185[255] = 0.0;
   out_4168561321210011185[256] = 0.0;
   out_4168561321210011185[257] = 0.0;
   out_4168561321210011185[258] = 0.0;
   out_4168561321210011185[259] = 0.0;
   out_4168561321210011185[260] = 0.0;
   out_4168561321210011185[261] = 0.0;
   out_4168561321210011185[262] = 0.0;
   out_4168561321210011185[263] = 0.0;
   out_4168561321210011185[264] = 0.0;
   out_4168561321210011185[265] = 0.0;
   out_4168561321210011185[266] = 1.0;
   out_4168561321210011185[267] = 0.0;
   out_4168561321210011185[268] = 0.0;
   out_4168561321210011185[269] = 0.0;
   out_4168561321210011185[270] = 0.0;
   out_4168561321210011185[271] = 0.0;
   out_4168561321210011185[272] = 0.0;
   out_4168561321210011185[273] = 0.0;
   out_4168561321210011185[274] = 0.0;
   out_4168561321210011185[275] = 0.0;
   out_4168561321210011185[276] = 0.0;
   out_4168561321210011185[277] = 0.0;
   out_4168561321210011185[278] = 0.0;
   out_4168561321210011185[279] = 0.0;
   out_4168561321210011185[280] = 0.0;
   out_4168561321210011185[281] = 0.0;
   out_4168561321210011185[282] = 0.0;
   out_4168561321210011185[283] = 0.0;
   out_4168561321210011185[284] = 0.0;
   out_4168561321210011185[285] = 1.0;
   out_4168561321210011185[286] = 0.0;
   out_4168561321210011185[287] = 0.0;
   out_4168561321210011185[288] = 0.0;
   out_4168561321210011185[289] = 0.0;
   out_4168561321210011185[290] = 0.0;
   out_4168561321210011185[291] = 0.0;
   out_4168561321210011185[292] = 0.0;
   out_4168561321210011185[293] = 0.0;
   out_4168561321210011185[294] = 0.0;
   out_4168561321210011185[295] = 0.0;
   out_4168561321210011185[296] = 0.0;
   out_4168561321210011185[297] = 0.0;
   out_4168561321210011185[298] = 0.0;
   out_4168561321210011185[299] = 0.0;
   out_4168561321210011185[300] = 0.0;
   out_4168561321210011185[301] = 0.0;
   out_4168561321210011185[302] = 0.0;
   out_4168561321210011185[303] = 0.0;
   out_4168561321210011185[304] = 1.0;
   out_4168561321210011185[305] = 0.0;
   out_4168561321210011185[306] = 0.0;
   out_4168561321210011185[307] = 0.0;
   out_4168561321210011185[308] = 0.0;
   out_4168561321210011185[309] = 0.0;
   out_4168561321210011185[310] = 0.0;
   out_4168561321210011185[311] = 0.0;
   out_4168561321210011185[312] = 0.0;
   out_4168561321210011185[313] = 0.0;
   out_4168561321210011185[314] = 0.0;
   out_4168561321210011185[315] = 0.0;
   out_4168561321210011185[316] = 0.0;
   out_4168561321210011185[317] = 0.0;
   out_4168561321210011185[318] = 0.0;
   out_4168561321210011185[319] = 0.0;
   out_4168561321210011185[320] = 0.0;
   out_4168561321210011185[321] = 0.0;
   out_4168561321210011185[322] = 0.0;
   out_4168561321210011185[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7595162637232814159) {
   out_7595162637232814159[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7595162637232814159[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7595162637232814159[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7595162637232814159[3] = dt*state[12] + state[3];
   out_7595162637232814159[4] = dt*state[13] + state[4];
   out_7595162637232814159[5] = dt*state[14] + state[5];
   out_7595162637232814159[6] = state[6];
   out_7595162637232814159[7] = state[7];
   out_7595162637232814159[8] = state[8];
   out_7595162637232814159[9] = state[9];
   out_7595162637232814159[10] = state[10];
   out_7595162637232814159[11] = state[11];
   out_7595162637232814159[12] = state[12];
   out_7595162637232814159[13] = state[13];
   out_7595162637232814159[14] = state[14];
   out_7595162637232814159[15] = state[15];
   out_7595162637232814159[16] = state[16];
   out_7595162637232814159[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1091902965475609973) {
   out_1091902965475609973[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1091902965475609973[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1091902965475609973[2] = 0;
   out_1091902965475609973[3] = 0;
   out_1091902965475609973[4] = 0;
   out_1091902965475609973[5] = 0;
   out_1091902965475609973[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1091902965475609973[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1091902965475609973[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1091902965475609973[9] = 0;
   out_1091902965475609973[10] = 0;
   out_1091902965475609973[11] = 0;
   out_1091902965475609973[12] = 0;
   out_1091902965475609973[13] = 0;
   out_1091902965475609973[14] = 0;
   out_1091902965475609973[15] = 0;
   out_1091902965475609973[16] = 0;
   out_1091902965475609973[17] = 0;
   out_1091902965475609973[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1091902965475609973[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1091902965475609973[20] = 0;
   out_1091902965475609973[21] = 0;
   out_1091902965475609973[22] = 0;
   out_1091902965475609973[23] = 0;
   out_1091902965475609973[24] = 0;
   out_1091902965475609973[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1091902965475609973[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1091902965475609973[27] = 0;
   out_1091902965475609973[28] = 0;
   out_1091902965475609973[29] = 0;
   out_1091902965475609973[30] = 0;
   out_1091902965475609973[31] = 0;
   out_1091902965475609973[32] = 0;
   out_1091902965475609973[33] = 0;
   out_1091902965475609973[34] = 0;
   out_1091902965475609973[35] = 0;
   out_1091902965475609973[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1091902965475609973[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1091902965475609973[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1091902965475609973[39] = 0;
   out_1091902965475609973[40] = 0;
   out_1091902965475609973[41] = 0;
   out_1091902965475609973[42] = 0;
   out_1091902965475609973[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1091902965475609973[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1091902965475609973[45] = 0;
   out_1091902965475609973[46] = 0;
   out_1091902965475609973[47] = 0;
   out_1091902965475609973[48] = 0;
   out_1091902965475609973[49] = 0;
   out_1091902965475609973[50] = 0;
   out_1091902965475609973[51] = 0;
   out_1091902965475609973[52] = 0;
   out_1091902965475609973[53] = 0;
   out_1091902965475609973[54] = 0;
   out_1091902965475609973[55] = 0;
   out_1091902965475609973[56] = 0;
   out_1091902965475609973[57] = 1;
   out_1091902965475609973[58] = 0;
   out_1091902965475609973[59] = 0;
   out_1091902965475609973[60] = 0;
   out_1091902965475609973[61] = 0;
   out_1091902965475609973[62] = 0;
   out_1091902965475609973[63] = 0;
   out_1091902965475609973[64] = 0;
   out_1091902965475609973[65] = 0;
   out_1091902965475609973[66] = dt;
   out_1091902965475609973[67] = 0;
   out_1091902965475609973[68] = 0;
   out_1091902965475609973[69] = 0;
   out_1091902965475609973[70] = 0;
   out_1091902965475609973[71] = 0;
   out_1091902965475609973[72] = 0;
   out_1091902965475609973[73] = 0;
   out_1091902965475609973[74] = 0;
   out_1091902965475609973[75] = 0;
   out_1091902965475609973[76] = 1;
   out_1091902965475609973[77] = 0;
   out_1091902965475609973[78] = 0;
   out_1091902965475609973[79] = 0;
   out_1091902965475609973[80] = 0;
   out_1091902965475609973[81] = 0;
   out_1091902965475609973[82] = 0;
   out_1091902965475609973[83] = 0;
   out_1091902965475609973[84] = 0;
   out_1091902965475609973[85] = dt;
   out_1091902965475609973[86] = 0;
   out_1091902965475609973[87] = 0;
   out_1091902965475609973[88] = 0;
   out_1091902965475609973[89] = 0;
   out_1091902965475609973[90] = 0;
   out_1091902965475609973[91] = 0;
   out_1091902965475609973[92] = 0;
   out_1091902965475609973[93] = 0;
   out_1091902965475609973[94] = 0;
   out_1091902965475609973[95] = 1;
   out_1091902965475609973[96] = 0;
   out_1091902965475609973[97] = 0;
   out_1091902965475609973[98] = 0;
   out_1091902965475609973[99] = 0;
   out_1091902965475609973[100] = 0;
   out_1091902965475609973[101] = 0;
   out_1091902965475609973[102] = 0;
   out_1091902965475609973[103] = 0;
   out_1091902965475609973[104] = dt;
   out_1091902965475609973[105] = 0;
   out_1091902965475609973[106] = 0;
   out_1091902965475609973[107] = 0;
   out_1091902965475609973[108] = 0;
   out_1091902965475609973[109] = 0;
   out_1091902965475609973[110] = 0;
   out_1091902965475609973[111] = 0;
   out_1091902965475609973[112] = 0;
   out_1091902965475609973[113] = 0;
   out_1091902965475609973[114] = 1;
   out_1091902965475609973[115] = 0;
   out_1091902965475609973[116] = 0;
   out_1091902965475609973[117] = 0;
   out_1091902965475609973[118] = 0;
   out_1091902965475609973[119] = 0;
   out_1091902965475609973[120] = 0;
   out_1091902965475609973[121] = 0;
   out_1091902965475609973[122] = 0;
   out_1091902965475609973[123] = 0;
   out_1091902965475609973[124] = 0;
   out_1091902965475609973[125] = 0;
   out_1091902965475609973[126] = 0;
   out_1091902965475609973[127] = 0;
   out_1091902965475609973[128] = 0;
   out_1091902965475609973[129] = 0;
   out_1091902965475609973[130] = 0;
   out_1091902965475609973[131] = 0;
   out_1091902965475609973[132] = 0;
   out_1091902965475609973[133] = 1;
   out_1091902965475609973[134] = 0;
   out_1091902965475609973[135] = 0;
   out_1091902965475609973[136] = 0;
   out_1091902965475609973[137] = 0;
   out_1091902965475609973[138] = 0;
   out_1091902965475609973[139] = 0;
   out_1091902965475609973[140] = 0;
   out_1091902965475609973[141] = 0;
   out_1091902965475609973[142] = 0;
   out_1091902965475609973[143] = 0;
   out_1091902965475609973[144] = 0;
   out_1091902965475609973[145] = 0;
   out_1091902965475609973[146] = 0;
   out_1091902965475609973[147] = 0;
   out_1091902965475609973[148] = 0;
   out_1091902965475609973[149] = 0;
   out_1091902965475609973[150] = 0;
   out_1091902965475609973[151] = 0;
   out_1091902965475609973[152] = 1;
   out_1091902965475609973[153] = 0;
   out_1091902965475609973[154] = 0;
   out_1091902965475609973[155] = 0;
   out_1091902965475609973[156] = 0;
   out_1091902965475609973[157] = 0;
   out_1091902965475609973[158] = 0;
   out_1091902965475609973[159] = 0;
   out_1091902965475609973[160] = 0;
   out_1091902965475609973[161] = 0;
   out_1091902965475609973[162] = 0;
   out_1091902965475609973[163] = 0;
   out_1091902965475609973[164] = 0;
   out_1091902965475609973[165] = 0;
   out_1091902965475609973[166] = 0;
   out_1091902965475609973[167] = 0;
   out_1091902965475609973[168] = 0;
   out_1091902965475609973[169] = 0;
   out_1091902965475609973[170] = 0;
   out_1091902965475609973[171] = 1;
   out_1091902965475609973[172] = 0;
   out_1091902965475609973[173] = 0;
   out_1091902965475609973[174] = 0;
   out_1091902965475609973[175] = 0;
   out_1091902965475609973[176] = 0;
   out_1091902965475609973[177] = 0;
   out_1091902965475609973[178] = 0;
   out_1091902965475609973[179] = 0;
   out_1091902965475609973[180] = 0;
   out_1091902965475609973[181] = 0;
   out_1091902965475609973[182] = 0;
   out_1091902965475609973[183] = 0;
   out_1091902965475609973[184] = 0;
   out_1091902965475609973[185] = 0;
   out_1091902965475609973[186] = 0;
   out_1091902965475609973[187] = 0;
   out_1091902965475609973[188] = 0;
   out_1091902965475609973[189] = 0;
   out_1091902965475609973[190] = 1;
   out_1091902965475609973[191] = 0;
   out_1091902965475609973[192] = 0;
   out_1091902965475609973[193] = 0;
   out_1091902965475609973[194] = 0;
   out_1091902965475609973[195] = 0;
   out_1091902965475609973[196] = 0;
   out_1091902965475609973[197] = 0;
   out_1091902965475609973[198] = 0;
   out_1091902965475609973[199] = 0;
   out_1091902965475609973[200] = 0;
   out_1091902965475609973[201] = 0;
   out_1091902965475609973[202] = 0;
   out_1091902965475609973[203] = 0;
   out_1091902965475609973[204] = 0;
   out_1091902965475609973[205] = 0;
   out_1091902965475609973[206] = 0;
   out_1091902965475609973[207] = 0;
   out_1091902965475609973[208] = 0;
   out_1091902965475609973[209] = 1;
   out_1091902965475609973[210] = 0;
   out_1091902965475609973[211] = 0;
   out_1091902965475609973[212] = 0;
   out_1091902965475609973[213] = 0;
   out_1091902965475609973[214] = 0;
   out_1091902965475609973[215] = 0;
   out_1091902965475609973[216] = 0;
   out_1091902965475609973[217] = 0;
   out_1091902965475609973[218] = 0;
   out_1091902965475609973[219] = 0;
   out_1091902965475609973[220] = 0;
   out_1091902965475609973[221] = 0;
   out_1091902965475609973[222] = 0;
   out_1091902965475609973[223] = 0;
   out_1091902965475609973[224] = 0;
   out_1091902965475609973[225] = 0;
   out_1091902965475609973[226] = 0;
   out_1091902965475609973[227] = 0;
   out_1091902965475609973[228] = 1;
   out_1091902965475609973[229] = 0;
   out_1091902965475609973[230] = 0;
   out_1091902965475609973[231] = 0;
   out_1091902965475609973[232] = 0;
   out_1091902965475609973[233] = 0;
   out_1091902965475609973[234] = 0;
   out_1091902965475609973[235] = 0;
   out_1091902965475609973[236] = 0;
   out_1091902965475609973[237] = 0;
   out_1091902965475609973[238] = 0;
   out_1091902965475609973[239] = 0;
   out_1091902965475609973[240] = 0;
   out_1091902965475609973[241] = 0;
   out_1091902965475609973[242] = 0;
   out_1091902965475609973[243] = 0;
   out_1091902965475609973[244] = 0;
   out_1091902965475609973[245] = 0;
   out_1091902965475609973[246] = 0;
   out_1091902965475609973[247] = 1;
   out_1091902965475609973[248] = 0;
   out_1091902965475609973[249] = 0;
   out_1091902965475609973[250] = 0;
   out_1091902965475609973[251] = 0;
   out_1091902965475609973[252] = 0;
   out_1091902965475609973[253] = 0;
   out_1091902965475609973[254] = 0;
   out_1091902965475609973[255] = 0;
   out_1091902965475609973[256] = 0;
   out_1091902965475609973[257] = 0;
   out_1091902965475609973[258] = 0;
   out_1091902965475609973[259] = 0;
   out_1091902965475609973[260] = 0;
   out_1091902965475609973[261] = 0;
   out_1091902965475609973[262] = 0;
   out_1091902965475609973[263] = 0;
   out_1091902965475609973[264] = 0;
   out_1091902965475609973[265] = 0;
   out_1091902965475609973[266] = 1;
   out_1091902965475609973[267] = 0;
   out_1091902965475609973[268] = 0;
   out_1091902965475609973[269] = 0;
   out_1091902965475609973[270] = 0;
   out_1091902965475609973[271] = 0;
   out_1091902965475609973[272] = 0;
   out_1091902965475609973[273] = 0;
   out_1091902965475609973[274] = 0;
   out_1091902965475609973[275] = 0;
   out_1091902965475609973[276] = 0;
   out_1091902965475609973[277] = 0;
   out_1091902965475609973[278] = 0;
   out_1091902965475609973[279] = 0;
   out_1091902965475609973[280] = 0;
   out_1091902965475609973[281] = 0;
   out_1091902965475609973[282] = 0;
   out_1091902965475609973[283] = 0;
   out_1091902965475609973[284] = 0;
   out_1091902965475609973[285] = 1;
   out_1091902965475609973[286] = 0;
   out_1091902965475609973[287] = 0;
   out_1091902965475609973[288] = 0;
   out_1091902965475609973[289] = 0;
   out_1091902965475609973[290] = 0;
   out_1091902965475609973[291] = 0;
   out_1091902965475609973[292] = 0;
   out_1091902965475609973[293] = 0;
   out_1091902965475609973[294] = 0;
   out_1091902965475609973[295] = 0;
   out_1091902965475609973[296] = 0;
   out_1091902965475609973[297] = 0;
   out_1091902965475609973[298] = 0;
   out_1091902965475609973[299] = 0;
   out_1091902965475609973[300] = 0;
   out_1091902965475609973[301] = 0;
   out_1091902965475609973[302] = 0;
   out_1091902965475609973[303] = 0;
   out_1091902965475609973[304] = 1;
   out_1091902965475609973[305] = 0;
   out_1091902965475609973[306] = 0;
   out_1091902965475609973[307] = 0;
   out_1091902965475609973[308] = 0;
   out_1091902965475609973[309] = 0;
   out_1091902965475609973[310] = 0;
   out_1091902965475609973[311] = 0;
   out_1091902965475609973[312] = 0;
   out_1091902965475609973[313] = 0;
   out_1091902965475609973[314] = 0;
   out_1091902965475609973[315] = 0;
   out_1091902965475609973[316] = 0;
   out_1091902965475609973[317] = 0;
   out_1091902965475609973[318] = 0;
   out_1091902965475609973[319] = 0;
   out_1091902965475609973[320] = 0;
   out_1091902965475609973[321] = 0;
   out_1091902965475609973[322] = 0;
   out_1091902965475609973[323] = 1;
}
void h_4(double *state, double *unused, double *out_4271893182613978797) {
   out_4271893182613978797[0] = state[6] + state[9];
   out_4271893182613978797[1] = state[7] + state[10];
   out_4271893182613978797[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5265198332585855939) {
   out_5265198332585855939[0] = 0;
   out_5265198332585855939[1] = 0;
   out_5265198332585855939[2] = 0;
   out_5265198332585855939[3] = 0;
   out_5265198332585855939[4] = 0;
   out_5265198332585855939[5] = 0;
   out_5265198332585855939[6] = 1;
   out_5265198332585855939[7] = 0;
   out_5265198332585855939[8] = 0;
   out_5265198332585855939[9] = 1;
   out_5265198332585855939[10] = 0;
   out_5265198332585855939[11] = 0;
   out_5265198332585855939[12] = 0;
   out_5265198332585855939[13] = 0;
   out_5265198332585855939[14] = 0;
   out_5265198332585855939[15] = 0;
   out_5265198332585855939[16] = 0;
   out_5265198332585855939[17] = 0;
   out_5265198332585855939[18] = 0;
   out_5265198332585855939[19] = 0;
   out_5265198332585855939[20] = 0;
   out_5265198332585855939[21] = 0;
   out_5265198332585855939[22] = 0;
   out_5265198332585855939[23] = 0;
   out_5265198332585855939[24] = 0;
   out_5265198332585855939[25] = 1;
   out_5265198332585855939[26] = 0;
   out_5265198332585855939[27] = 0;
   out_5265198332585855939[28] = 1;
   out_5265198332585855939[29] = 0;
   out_5265198332585855939[30] = 0;
   out_5265198332585855939[31] = 0;
   out_5265198332585855939[32] = 0;
   out_5265198332585855939[33] = 0;
   out_5265198332585855939[34] = 0;
   out_5265198332585855939[35] = 0;
   out_5265198332585855939[36] = 0;
   out_5265198332585855939[37] = 0;
   out_5265198332585855939[38] = 0;
   out_5265198332585855939[39] = 0;
   out_5265198332585855939[40] = 0;
   out_5265198332585855939[41] = 0;
   out_5265198332585855939[42] = 0;
   out_5265198332585855939[43] = 0;
   out_5265198332585855939[44] = 1;
   out_5265198332585855939[45] = 0;
   out_5265198332585855939[46] = 0;
   out_5265198332585855939[47] = 1;
   out_5265198332585855939[48] = 0;
   out_5265198332585855939[49] = 0;
   out_5265198332585855939[50] = 0;
   out_5265198332585855939[51] = 0;
   out_5265198332585855939[52] = 0;
   out_5265198332585855939[53] = 0;
}
void h_10(double *state, double *unused, double *out_6068675735727225828) {
   out_6068675735727225828[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6068675735727225828[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6068675735727225828[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4012474741247108873) {
   out_4012474741247108873[0] = 0;
   out_4012474741247108873[1] = 9.8100000000000005*cos(state[1]);
   out_4012474741247108873[2] = 0;
   out_4012474741247108873[3] = 0;
   out_4012474741247108873[4] = -state[8];
   out_4012474741247108873[5] = state[7];
   out_4012474741247108873[6] = 0;
   out_4012474741247108873[7] = state[5];
   out_4012474741247108873[8] = -state[4];
   out_4012474741247108873[9] = 0;
   out_4012474741247108873[10] = 0;
   out_4012474741247108873[11] = 0;
   out_4012474741247108873[12] = 1;
   out_4012474741247108873[13] = 0;
   out_4012474741247108873[14] = 0;
   out_4012474741247108873[15] = 1;
   out_4012474741247108873[16] = 0;
   out_4012474741247108873[17] = 0;
   out_4012474741247108873[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4012474741247108873[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4012474741247108873[20] = 0;
   out_4012474741247108873[21] = state[8];
   out_4012474741247108873[22] = 0;
   out_4012474741247108873[23] = -state[6];
   out_4012474741247108873[24] = -state[5];
   out_4012474741247108873[25] = 0;
   out_4012474741247108873[26] = state[3];
   out_4012474741247108873[27] = 0;
   out_4012474741247108873[28] = 0;
   out_4012474741247108873[29] = 0;
   out_4012474741247108873[30] = 0;
   out_4012474741247108873[31] = 1;
   out_4012474741247108873[32] = 0;
   out_4012474741247108873[33] = 0;
   out_4012474741247108873[34] = 1;
   out_4012474741247108873[35] = 0;
   out_4012474741247108873[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4012474741247108873[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4012474741247108873[38] = 0;
   out_4012474741247108873[39] = -state[7];
   out_4012474741247108873[40] = state[6];
   out_4012474741247108873[41] = 0;
   out_4012474741247108873[42] = state[4];
   out_4012474741247108873[43] = -state[3];
   out_4012474741247108873[44] = 0;
   out_4012474741247108873[45] = 0;
   out_4012474741247108873[46] = 0;
   out_4012474741247108873[47] = 0;
   out_4012474741247108873[48] = 0;
   out_4012474741247108873[49] = 0;
   out_4012474741247108873[50] = 1;
   out_4012474741247108873[51] = 0;
   out_4012474741247108873[52] = 0;
   out_4012474741247108873[53] = 1;
}
void h_13(double *state, double *unused, double *out_860321329376649767) {
   out_860321329376649767[0] = state[3];
   out_860321329376649767[1] = state[4];
   out_860321329376649767[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2052924507253523138) {
   out_2052924507253523138[0] = 0;
   out_2052924507253523138[1] = 0;
   out_2052924507253523138[2] = 0;
   out_2052924507253523138[3] = 1;
   out_2052924507253523138[4] = 0;
   out_2052924507253523138[5] = 0;
   out_2052924507253523138[6] = 0;
   out_2052924507253523138[7] = 0;
   out_2052924507253523138[8] = 0;
   out_2052924507253523138[9] = 0;
   out_2052924507253523138[10] = 0;
   out_2052924507253523138[11] = 0;
   out_2052924507253523138[12] = 0;
   out_2052924507253523138[13] = 0;
   out_2052924507253523138[14] = 0;
   out_2052924507253523138[15] = 0;
   out_2052924507253523138[16] = 0;
   out_2052924507253523138[17] = 0;
   out_2052924507253523138[18] = 0;
   out_2052924507253523138[19] = 0;
   out_2052924507253523138[20] = 0;
   out_2052924507253523138[21] = 0;
   out_2052924507253523138[22] = 1;
   out_2052924507253523138[23] = 0;
   out_2052924507253523138[24] = 0;
   out_2052924507253523138[25] = 0;
   out_2052924507253523138[26] = 0;
   out_2052924507253523138[27] = 0;
   out_2052924507253523138[28] = 0;
   out_2052924507253523138[29] = 0;
   out_2052924507253523138[30] = 0;
   out_2052924507253523138[31] = 0;
   out_2052924507253523138[32] = 0;
   out_2052924507253523138[33] = 0;
   out_2052924507253523138[34] = 0;
   out_2052924507253523138[35] = 0;
   out_2052924507253523138[36] = 0;
   out_2052924507253523138[37] = 0;
   out_2052924507253523138[38] = 0;
   out_2052924507253523138[39] = 0;
   out_2052924507253523138[40] = 0;
   out_2052924507253523138[41] = 1;
   out_2052924507253523138[42] = 0;
   out_2052924507253523138[43] = 0;
   out_2052924507253523138[44] = 0;
   out_2052924507253523138[45] = 0;
   out_2052924507253523138[46] = 0;
   out_2052924507253523138[47] = 0;
   out_2052924507253523138[48] = 0;
   out_2052924507253523138[49] = 0;
   out_2052924507253523138[50] = 0;
   out_2052924507253523138[51] = 0;
   out_2052924507253523138[52] = 0;
   out_2052924507253523138[53] = 0;
}
void h_14(double *state, double *unused, double *out_5677441075365347292) {
   out_5677441075365347292[0] = state[6];
   out_5677441075365347292[1] = state[7];
   out_5677441075365347292[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1301957476246371410) {
   out_1301957476246371410[0] = 0;
   out_1301957476246371410[1] = 0;
   out_1301957476246371410[2] = 0;
   out_1301957476246371410[3] = 0;
   out_1301957476246371410[4] = 0;
   out_1301957476246371410[5] = 0;
   out_1301957476246371410[6] = 1;
   out_1301957476246371410[7] = 0;
   out_1301957476246371410[8] = 0;
   out_1301957476246371410[9] = 0;
   out_1301957476246371410[10] = 0;
   out_1301957476246371410[11] = 0;
   out_1301957476246371410[12] = 0;
   out_1301957476246371410[13] = 0;
   out_1301957476246371410[14] = 0;
   out_1301957476246371410[15] = 0;
   out_1301957476246371410[16] = 0;
   out_1301957476246371410[17] = 0;
   out_1301957476246371410[18] = 0;
   out_1301957476246371410[19] = 0;
   out_1301957476246371410[20] = 0;
   out_1301957476246371410[21] = 0;
   out_1301957476246371410[22] = 0;
   out_1301957476246371410[23] = 0;
   out_1301957476246371410[24] = 0;
   out_1301957476246371410[25] = 1;
   out_1301957476246371410[26] = 0;
   out_1301957476246371410[27] = 0;
   out_1301957476246371410[28] = 0;
   out_1301957476246371410[29] = 0;
   out_1301957476246371410[30] = 0;
   out_1301957476246371410[31] = 0;
   out_1301957476246371410[32] = 0;
   out_1301957476246371410[33] = 0;
   out_1301957476246371410[34] = 0;
   out_1301957476246371410[35] = 0;
   out_1301957476246371410[36] = 0;
   out_1301957476246371410[37] = 0;
   out_1301957476246371410[38] = 0;
   out_1301957476246371410[39] = 0;
   out_1301957476246371410[40] = 0;
   out_1301957476246371410[41] = 0;
   out_1301957476246371410[42] = 0;
   out_1301957476246371410[43] = 0;
   out_1301957476246371410[44] = 1;
   out_1301957476246371410[45] = 0;
   out_1301957476246371410[46] = 0;
   out_1301957476246371410[47] = 0;
   out_1301957476246371410[48] = 0;
   out_1301957476246371410[49] = 0;
   out_1301957476246371410[50] = 0;
   out_1301957476246371410[51] = 0;
   out_1301957476246371410[52] = 0;
   out_1301957476246371410[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_609976965150865312) {
  err_fun(nom_x, delta_x, out_609976965150865312);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8281732551506992950) {
  inv_err_fun(nom_x, true_x, out_8281732551506992950);
}
void pose_H_mod_fun(double *state, double *out_4168561321210011185) {
  H_mod_fun(state, out_4168561321210011185);
}
void pose_f_fun(double *state, double dt, double *out_7595162637232814159) {
  f_fun(state,  dt, out_7595162637232814159);
}
void pose_F_fun(double *state, double dt, double *out_1091902965475609973) {
  F_fun(state,  dt, out_1091902965475609973);
}
void pose_h_4(double *state, double *unused, double *out_4271893182613978797) {
  h_4(state, unused, out_4271893182613978797);
}
void pose_H_4(double *state, double *unused, double *out_5265198332585855939) {
  H_4(state, unused, out_5265198332585855939);
}
void pose_h_10(double *state, double *unused, double *out_6068675735727225828) {
  h_10(state, unused, out_6068675735727225828);
}
void pose_H_10(double *state, double *unused, double *out_4012474741247108873) {
  H_10(state, unused, out_4012474741247108873);
}
void pose_h_13(double *state, double *unused, double *out_860321329376649767) {
  h_13(state, unused, out_860321329376649767);
}
void pose_H_13(double *state, double *unused, double *out_2052924507253523138) {
  H_13(state, unused, out_2052924507253523138);
}
void pose_h_14(double *state, double *unused, double *out_5677441075365347292) {
  h_14(state, unused, out_5677441075365347292);
}
void pose_H_14(double *state, double *unused, double *out_1301957476246371410) {
  H_14(state, unused, out_1301957476246371410);
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
