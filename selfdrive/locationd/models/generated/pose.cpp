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
void err_fun(double *nom_x, double *delta_x, double *out_8550489212526755506) {
   out_8550489212526755506[0] = delta_x[0] + nom_x[0];
   out_8550489212526755506[1] = delta_x[1] + nom_x[1];
   out_8550489212526755506[2] = delta_x[2] + nom_x[2];
   out_8550489212526755506[3] = delta_x[3] + nom_x[3];
   out_8550489212526755506[4] = delta_x[4] + nom_x[4];
   out_8550489212526755506[5] = delta_x[5] + nom_x[5];
   out_8550489212526755506[6] = delta_x[6] + nom_x[6];
   out_8550489212526755506[7] = delta_x[7] + nom_x[7];
   out_8550489212526755506[8] = delta_x[8] + nom_x[8];
   out_8550489212526755506[9] = delta_x[9] + nom_x[9];
   out_8550489212526755506[10] = delta_x[10] + nom_x[10];
   out_8550489212526755506[11] = delta_x[11] + nom_x[11];
   out_8550489212526755506[12] = delta_x[12] + nom_x[12];
   out_8550489212526755506[13] = delta_x[13] + nom_x[13];
   out_8550489212526755506[14] = delta_x[14] + nom_x[14];
   out_8550489212526755506[15] = delta_x[15] + nom_x[15];
   out_8550489212526755506[16] = delta_x[16] + nom_x[16];
   out_8550489212526755506[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2197167056715094306) {
   out_2197167056715094306[0] = -nom_x[0] + true_x[0];
   out_2197167056715094306[1] = -nom_x[1] + true_x[1];
   out_2197167056715094306[2] = -nom_x[2] + true_x[2];
   out_2197167056715094306[3] = -nom_x[3] + true_x[3];
   out_2197167056715094306[4] = -nom_x[4] + true_x[4];
   out_2197167056715094306[5] = -nom_x[5] + true_x[5];
   out_2197167056715094306[6] = -nom_x[6] + true_x[6];
   out_2197167056715094306[7] = -nom_x[7] + true_x[7];
   out_2197167056715094306[8] = -nom_x[8] + true_x[8];
   out_2197167056715094306[9] = -nom_x[9] + true_x[9];
   out_2197167056715094306[10] = -nom_x[10] + true_x[10];
   out_2197167056715094306[11] = -nom_x[11] + true_x[11];
   out_2197167056715094306[12] = -nom_x[12] + true_x[12];
   out_2197167056715094306[13] = -nom_x[13] + true_x[13];
   out_2197167056715094306[14] = -nom_x[14] + true_x[14];
   out_2197167056715094306[15] = -nom_x[15] + true_x[15];
   out_2197167056715094306[16] = -nom_x[16] + true_x[16];
   out_2197167056715094306[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1273572215837011735) {
   out_1273572215837011735[0] = 1.0;
   out_1273572215837011735[1] = 0.0;
   out_1273572215837011735[2] = 0.0;
   out_1273572215837011735[3] = 0.0;
   out_1273572215837011735[4] = 0.0;
   out_1273572215837011735[5] = 0.0;
   out_1273572215837011735[6] = 0.0;
   out_1273572215837011735[7] = 0.0;
   out_1273572215837011735[8] = 0.0;
   out_1273572215837011735[9] = 0.0;
   out_1273572215837011735[10] = 0.0;
   out_1273572215837011735[11] = 0.0;
   out_1273572215837011735[12] = 0.0;
   out_1273572215837011735[13] = 0.0;
   out_1273572215837011735[14] = 0.0;
   out_1273572215837011735[15] = 0.0;
   out_1273572215837011735[16] = 0.0;
   out_1273572215837011735[17] = 0.0;
   out_1273572215837011735[18] = 0.0;
   out_1273572215837011735[19] = 1.0;
   out_1273572215837011735[20] = 0.0;
   out_1273572215837011735[21] = 0.0;
   out_1273572215837011735[22] = 0.0;
   out_1273572215837011735[23] = 0.0;
   out_1273572215837011735[24] = 0.0;
   out_1273572215837011735[25] = 0.0;
   out_1273572215837011735[26] = 0.0;
   out_1273572215837011735[27] = 0.0;
   out_1273572215837011735[28] = 0.0;
   out_1273572215837011735[29] = 0.0;
   out_1273572215837011735[30] = 0.0;
   out_1273572215837011735[31] = 0.0;
   out_1273572215837011735[32] = 0.0;
   out_1273572215837011735[33] = 0.0;
   out_1273572215837011735[34] = 0.0;
   out_1273572215837011735[35] = 0.0;
   out_1273572215837011735[36] = 0.0;
   out_1273572215837011735[37] = 0.0;
   out_1273572215837011735[38] = 1.0;
   out_1273572215837011735[39] = 0.0;
   out_1273572215837011735[40] = 0.0;
   out_1273572215837011735[41] = 0.0;
   out_1273572215837011735[42] = 0.0;
   out_1273572215837011735[43] = 0.0;
   out_1273572215837011735[44] = 0.0;
   out_1273572215837011735[45] = 0.0;
   out_1273572215837011735[46] = 0.0;
   out_1273572215837011735[47] = 0.0;
   out_1273572215837011735[48] = 0.0;
   out_1273572215837011735[49] = 0.0;
   out_1273572215837011735[50] = 0.0;
   out_1273572215837011735[51] = 0.0;
   out_1273572215837011735[52] = 0.0;
   out_1273572215837011735[53] = 0.0;
   out_1273572215837011735[54] = 0.0;
   out_1273572215837011735[55] = 0.0;
   out_1273572215837011735[56] = 0.0;
   out_1273572215837011735[57] = 1.0;
   out_1273572215837011735[58] = 0.0;
   out_1273572215837011735[59] = 0.0;
   out_1273572215837011735[60] = 0.0;
   out_1273572215837011735[61] = 0.0;
   out_1273572215837011735[62] = 0.0;
   out_1273572215837011735[63] = 0.0;
   out_1273572215837011735[64] = 0.0;
   out_1273572215837011735[65] = 0.0;
   out_1273572215837011735[66] = 0.0;
   out_1273572215837011735[67] = 0.0;
   out_1273572215837011735[68] = 0.0;
   out_1273572215837011735[69] = 0.0;
   out_1273572215837011735[70] = 0.0;
   out_1273572215837011735[71] = 0.0;
   out_1273572215837011735[72] = 0.0;
   out_1273572215837011735[73] = 0.0;
   out_1273572215837011735[74] = 0.0;
   out_1273572215837011735[75] = 0.0;
   out_1273572215837011735[76] = 1.0;
   out_1273572215837011735[77] = 0.0;
   out_1273572215837011735[78] = 0.0;
   out_1273572215837011735[79] = 0.0;
   out_1273572215837011735[80] = 0.0;
   out_1273572215837011735[81] = 0.0;
   out_1273572215837011735[82] = 0.0;
   out_1273572215837011735[83] = 0.0;
   out_1273572215837011735[84] = 0.0;
   out_1273572215837011735[85] = 0.0;
   out_1273572215837011735[86] = 0.0;
   out_1273572215837011735[87] = 0.0;
   out_1273572215837011735[88] = 0.0;
   out_1273572215837011735[89] = 0.0;
   out_1273572215837011735[90] = 0.0;
   out_1273572215837011735[91] = 0.0;
   out_1273572215837011735[92] = 0.0;
   out_1273572215837011735[93] = 0.0;
   out_1273572215837011735[94] = 0.0;
   out_1273572215837011735[95] = 1.0;
   out_1273572215837011735[96] = 0.0;
   out_1273572215837011735[97] = 0.0;
   out_1273572215837011735[98] = 0.0;
   out_1273572215837011735[99] = 0.0;
   out_1273572215837011735[100] = 0.0;
   out_1273572215837011735[101] = 0.0;
   out_1273572215837011735[102] = 0.0;
   out_1273572215837011735[103] = 0.0;
   out_1273572215837011735[104] = 0.0;
   out_1273572215837011735[105] = 0.0;
   out_1273572215837011735[106] = 0.0;
   out_1273572215837011735[107] = 0.0;
   out_1273572215837011735[108] = 0.0;
   out_1273572215837011735[109] = 0.0;
   out_1273572215837011735[110] = 0.0;
   out_1273572215837011735[111] = 0.0;
   out_1273572215837011735[112] = 0.0;
   out_1273572215837011735[113] = 0.0;
   out_1273572215837011735[114] = 1.0;
   out_1273572215837011735[115] = 0.0;
   out_1273572215837011735[116] = 0.0;
   out_1273572215837011735[117] = 0.0;
   out_1273572215837011735[118] = 0.0;
   out_1273572215837011735[119] = 0.0;
   out_1273572215837011735[120] = 0.0;
   out_1273572215837011735[121] = 0.0;
   out_1273572215837011735[122] = 0.0;
   out_1273572215837011735[123] = 0.0;
   out_1273572215837011735[124] = 0.0;
   out_1273572215837011735[125] = 0.0;
   out_1273572215837011735[126] = 0.0;
   out_1273572215837011735[127] = 0.0;
   out_1273572215837011735[128] = 0.0;
   out_1273572215837011735[129] = 0.0;
   out_1273572215837011735[130] = 0.0;
   out_1273572215837011735[131] = 0.0;
   out_1273572215837011735[132] = 0.0;
   out_1273572215837011735[133] = 1.0;
   out_1273572215837011735[134] = 0.0;
   out_1273572215837011735[135] = 0.0;
   out_1273572215837011735[136] = 0.0;
   out_1273572215837011735[137] = 0.0;
   out_1273572215837011735[138] = 0.0;
   out_1273572215837011735[139] = 0.0;
   out_1273572215837011735[140] = 0.0;
   out_1273572215837011735[141] = 0.0;
   out_1273572215837011735[142] = 0.0;
   out_1273572215837011735[143] = 0.0;
   out_1273572215837011735[144] = 0.0;
   out_1273572215837011735[145] = 0.0;
   out_1273572215837011735[146] = 0.0;
   out_1273572215837011735[147] = 0.0;
   out_1273572215837011735[148] = 0.0;
   out_1273572215837011735[149] = 0.0;
   out_1273572215837011735[150] = 0.0;
   out_1273572215837011735[151] = 0.0;
   out_1273572215837011735[152] = 1.0;
   out_1273572215837011735[153] = 0.0;
   out_1273572215837011735[154] = 0.0;
   out_1273572215837011735[155] = 0.0;
   out_1273572215837011735[156] = 0.0;
   out_1273572215837011735[157] = 0.0;
   out_1273572215837011735[158] = 0.0;
   out_1273572215837011735[159] = 0.0;
   out_1273572215837011735[160] = 0.0;
   out_1273572215837011735[161] = 0.0;
   out_1273572215837011735[162] = 0.0;
   out_1273572215837011735[163] = 0.0;
   out_1273572215837011735[164] = 0.0;
   out_1273572215837011735[165] = 0.0;
   out_1273572215837011735[166] = 0.0;
   out_1273572215837011735[167] = 0.0;
   out_1273572215837011735[168] = 0.0;
   out_1273572215837011735[169] = 0.0;
   out_1273572215837011735[170] = 0.0;
   out_1273572215837011735[171] = 1.0;
   out_1273572215837011735[172] = 0.0;
   out_1273572215837011735[173] = 0.0;
   out_1273572215837011735[174] = 0.0;
   out_1273572215837011735[175] = 0.0;
   out_1273572215837011735[176] = 0.0;
   out_1273572215837011735[177] = 0.0;
   out_1273572215837011735[178] = 0.0;
   out_1273572215837011735[179] = 0.0;
   out_1273572215837011735[180] = 0.0;
   out_1273572215837011735[181] = 0.0;
   out_1273572215837011735[182] = 0.0;
   out_1273572215837011735[183] = 0.0;
   out_1273572215837011735[184] = 0.0;
   out_1273572215837011735[185] = 0.0;
   out_1273572215837011735[186] = 0.0;
   out_1273572215837011735[187] = 0.0;
   out_1273572215837011735[188] = 0.0;
   out_1273572215837011735[189] = 0.0;
   out_1273572215837011735[190] = 1.0;
   out_1273572215837011735[191] = 0.0;
   out_1273572215837011735[192] = 0.0;
   out_1273572215837011735[193] = 0.0;
   out_1273572215837011735[194] = 0.0;
   out_1273572215837011735[195] = 0.0;
   out_1273572215837011735[196] = 0.0;
   out_1273572215837011735[197] = 0.0;
   out_1273572215837011735[198] = 0.0;
   out_1273572215837011735[199] = 0.0;
   out_1273572215837011735[200] = 0.0;
   out_1273572215837011735[201] = 0.0;
   out_1273572215837011735[202] = 0.0;
   out_1273572215837011735[203] = 0.0;
   out_1273572215837011735[204] = 0.0;
   out_1273572215837011735[205] = 0.0;
   out_1273572215837011735[206] = 0.0;
   out_1273572215837011735[207] = 0.0;
   out_1273572215837011735[208] = 0.0;
   out_1273572215837011735[209] = 1.0;
   out_1273572215837011735[210] = 0.0;
   out_1273572215837011735[211] = 0.0;
   out_1273572215837011735[212] = 0.0;
   out_1273572215837011735[213] = 0.0;
   out_1273572215837011735[214] = 0.0;
   out_1273572215837011735[215] = 0.0;
   out_1273572215837011735[216] = 0.0;
   out_1273572215837011735[217] = 0.0;
   out_1273572215837011735[218] = 0.0;
   out_1273572215837011735[219] = 0.0;
   out_1273572215837011735[220] = 0.0;
   out_1273572215837011735[221] = 0.0;
   out_1273572215837011735[222] = 0.0;
   out_1273572215837011735[223] = 0.0;
   out_1273572215837011735[224] = 0.0;
   out_1273572215837011735[225] = 0.0;
   out_1273572215837011735[226] = 0.0;
   out_1273572215837011735[227] = 0.0;
   out_1273572215837011735[228] = 1.0;
   out_1273572215837011735[229] = 0.0;
   out_1273572215837011735[230] = 0.0;
   out_1273572215837011735[231] = 0.0;
   out_1273572215837011735[232] = 0.0;
   out_1273572215837011735[233] = 0.0;
   out_1273572215837011735[234] = 0.0;
   out_1273572215837011735[235] = 0.0;
   out_1273572215837011735[236] = 0.0;
   out_1273572215837011735[237] = 0.0;
   out_1273572215837011735[238] = 0.0;
   out_1273572215837011735[239] = 0.0;
   out_1273572215837011735[240] = 0.0;
   out_1273572215837011735[241] = 0.0;
   out_1273572215837011735[242] = 0.0;
   out_1273572215837011735[243] = 0.0;
   out_1273572215837011735[244] = 0.0;
   out_1273572215837011735[245] = 0.0;
   out_1273572215837011735[246] = 0.0;
   out_1273572215837011735[247] = 1.0;
   out_1273572215837011735[248] = 0.0;
   out_1273572215837011735[249] = 0.0;
   out_1273572215837011735[250] = 0.0;
   out_1273572215837011735[251] = 0.0;
   out_1273572215837011735[252] = 0.0;
   out_1273572215837011735[253] = 0.0;
   out_1273572215837011735[254] = 0.0;
   out_1273572215837011735[255] = 0.0;
   out_1273572215837011735[256] = 0.0;
   out_1273572215837011735[257] = 0.0;
   out_1273572215837011735[258] = 0.0;
   out_1273572215837011735[259] = 0.0;
   out_1273572215837011735[260] = 0.0;
   out_1273572215837011735[261] = 0.0;
   out_1273572215837011735[262] = 0.0;
   out_1273572215837011735[263] = 0.0;
   out_1273572215837011735[264] = 0.0;
   out_1273572215837011735[265] = 0.0;
   out_1273572215837011735[266] = 1.0;
   out_1273572215837011735[267] = 0.0;
   out_1273572215837011735[268] = 0.0;
   out_1273572215837011735[269] = 0.0;
   out_1273572215837011735[270] = 0.0;
   out_1273572215837011735[271] = 0.0;
   out_1273572215837011735[272] = 0.0;
   out_1273572215837011735[273] = 0.0;
   out_1273572215837011735[274] = 0.0;
   out_1273572215837011735[275] = 0.0;
   out_1273572215837011735[276] = 0.0;
   out_1273572215837011735[277] = 0.0;
   out_1273572215837011735[278] = 0.0;
   out_1273572215837011735[279] = 0.0;
   out_1273572215837011735[280] = 0.0;
   out_1273572215837011735[281] = 0.0;
   out_1273572215837011735[282] = 0.0;
   out_1273572215837011735[283] = 0.0;
   out_1273572215837011735[284] = 0.0;
   out_1273572215837011735[285] = 1.0;
   out_1273572215837011735[286] = 0.0;
   out_1273572215837011735[287] = 0.0;
   out_1273572215837011735[288] = 0.0;
   out_1273572215837011735[289] = 0.0;
   out_1273572215837011735[290] = 0.0;
   out_1273572215837011735[291] = 0.0;
   out_1273572215837011735[292] = 0.0;
   out_1273572215837011735[293] = 0.0;
   out_1273572215837011735[294] = 0.0;
   out_1273572215837011735[295] = 0.0;
   out_1273572215837011735[296] = 0.0;
   out_1273572215837011735[297] = 0.0;
   out_1273572215837011735[298] = 0.0;
   out_1273572215837011735[299] = 0.0;
   out_1273572215837011735[300] = 0.0;
   out_1273572215837011735[301] = 0.0;
   out_1273572215837011735[302] = 0.0;
   out_1273572215837011735[303] = 0.0;
   out_1273572215837011735[304] = 1.0;
   out_1273572215837011735[305] = 0.0;
   out_1273572215837011735[306] = 0.0;
   out_1273572215837011735[307] = 0.0;
   out_1273572215837011735[308] = 0.0;
   out_1273572215837011735[309] = 0.0;
   out_1273572215837011735[310] = 0.0;
   out_1273572215837011735[311] = 0.0;
   out_1273572215837011735[312] = 0.0;
   out_1273572215837011735[313] = 0.0;
   out_1273572215837011735[314] = 0.0;
   out_1273572215837011735[315] = 0.0;
   out_1273572215837011735[316] = 0.0;
   out_1273572215837011735[317] = 0.0;
   out_1273572215837011735[318] = 0.0;
   out_1273572215837011735[319] = 0.0;
   out_1273572215837011735[320] = 0.0;
   out_1273572215837011735[321] = 0.0;
   out_1273572215837011735[322] = 0.0;
   out_1273572215837011735[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_58843541046312828) {
   out_58843541046312828[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_58843541046312828[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_58843541046312828[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_58843541046312828[3] = dt*state[12] + state[3];
   out_58843541046312828[4] = dt*state[13] + state[4];
   out_58843541046312828[5] = dt*state[14] + state[5];
   out_58843541046312828[6] = state[6];
   out_58843541046312828[7] = state[7];
   out_58843541046312828[8] = state[8];
   out_58843541046312828[9] = state[9];
   out_58843541046312828[10] = state[10];
   out_58843541046312828[11] = state[11];
   out_58843541046312828[12] = state[12];
   out_58843541046312828[13] = state[13];
   out_58843541046312828[14] = state[14];
   out_58843541046312828[15] = state[15];
   out_58843541046312828[16] = state[16];
   out_58843541046312828[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4952539587807327652) {
   out_4952539587807327652[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4952539587807327652[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4952539587807327652[2] = 0;
   out_4952539587807327652[3] = 0;
   out_4952539587807327652[4] = 0;
   out_4952539587807327652[5] = 0;
   out_4952539587807327652[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4952539587807327652[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4952539587807327652[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4952539587807327652[9] = 0;
   out_4952539587807327652[10] = 0;
   out_4952539587807327652[11] = 0;
   out_4952539587807327652[12] = 0;
   out_4952539587807327652[13] = 0;
   out_4952539587807327652[14] = 0;
   out_4952539587807327652[15] = 0;
   out_4952539587807327652[16] = 0;
   out_4952539587807327652[17] = 0;
   out_4952539587807327652[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4952539587807327652[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4952539587807327652[20] = 0;
   out_4952539587807327652[21] = 0;
   out_4952539587807327652[22] = 0;
   out_4952539587807327652[23] = 0;
   out_4952539587807327652[24] = 0;
   out_4952539587807327652[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4952539587807327652[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4952539587807327652[27] = 0;
   out_4952539587807327652[28] = 0;
   out_4952539587807327652[29] = 0;
   out_4952539587807327652[30] = 0;
   out_4952539587807327652[31] = 0;
   out_4952539587807327652[32] = 0;
   out_4952539587807327652[33] = 0;
   out_4952539587807327652[34] = 0;
   out_4952539587807327652[35] = 0;
   out_4952539587807327652[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4952539587807327652[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4952539587807327652[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4952539587807327652[39] = 0;
   out_4952539587807327652[40] = 0;
   out_4952539587807327652[41] = 0;
   out_4952539587807327652[42] = 0;
   out_4952539587807327652[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4952539587807327652[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4952539587807327652[45] = 0;
   out_4952539587807327652[46] = 0;
   out_4952539587807327652[47] = 0;
   out_4952539587807327652[48] = 0;
   out_4952539587807327652[49] = 0;
   out_4952539587807327652[50] = 0;
   out_4952539587807327652[51] = 0;
   out_4952539587807327652[52] = 0;
   out_4952539587807327652[53] = 0;
   out_4952539587807327652[54] = 0;
   out_4952539587807327652[55] = 0;
   out_4952539587807327652[56] = 0;
   out_4952539587807327652[57] = 1;
   out_4952539587807327652[58] = 0;
   out_4952539587807327652[59] = 0;
   out_4952539587807327652[60] = 0;
   out_4952539587807327652[61] = 0;
   out_4952539587807327652[62] = 0;
   out_4952539587807327652[63] = 0;
   out_4952539587807327652[64] = 0;
   out_4952539587807327652[65] = 0;
   out_4952539587807327652[66] = dt;
   out_4952539587807327652[67] = 0;
   out_4952539587807327652[68] = 0;
   out_4952539587807327652[69] = 0;
   out_4952539587807327652[70] = 0;
   out_4952539587807327652[71] = 0;
   out_4952539587807327652[72] = 0;
   out_4952539587807327652[73] = 0;
   out_4952539587807327652[74] = 0;
   out_4952539587807327652[75] = 0;
   out_4952539587807327652[76] = 1;
   out_4952539587807327652[77] = 0;
   out_4952539587807327652[78] = 0;
   out_4952539587807327652[79] = 0;
   out_4952539587807327652[80] = 0;
   out_4952539587807327652[81] = 0;
   out_4952539587807327652[82] = 0;
   out_4952539587807327652[83] = 0;
   out_4952539587807327652[84] = 0;
   out_4952539587807327652[85] = dt;
   out_4952539587807327652[86] = 0;
   out_4952539587807327652[87] = 0;
   out_4952539587807327652[88] = 0;
   out_4952539587807327652[89] = 0;
   out_4952539587807327652[90] = 0;
   out_4952539587807327652[91] = 0;
   out_4952539587807327652[92] = 0;
   out_4952539587807327652[93] = 0;
   out_4952539587807327652[94] = 0;
   out_4952539587807327652[95] = 1;
   out_4952539587807327652[96] = 0;
   out_4952539587807327652[97] = 0;
   out_4952539587807327652[98] = 0;
   out_4952539587807327652[99] = 0;
   out_4952539587807327652[100] = 0;
   out_4952539587807327652[101] = 0;
   out_4952539587807327652[102] = 0;
   out_4952539587807327652[103] = 0;
   out_4952539587807327652[104] = dt;
   out_4952539587807327652[105] = 0;
   out_4952539587807327652[106] = 0;
   out_4952539587807327652[107] = 0;
   out_4952539587807327652[108] = 0;
   out_4952539587807327652[109] = 0;
   out_4952539587807327652[110] = 0;
   out_4952539587807327652[111] = 0;
   out_4952539587807327652[112] = 0;
   out_4952539587807327652[113] = 0;
   out_4952539587807327652[114] = 1;
   out_4952539587807327652[115] = 0;
   out_4952539587807327652[116] = 0;
   out_4952539587807327652[117] = 0;
   out_4952539587807327652[118] = 0;
   out_4952539587807327652[119] = 0;
   out_4952539587807327652[120] = 0;
   out_4952539587807327652[121] = 0;
   out_4952539587807327652[122] = 0;
   out_4952539587807327652[123] = 0;
   out_4952539587807327652[124] = 0;
   out_4952539587807327652[125] = 0;
   out_4952539587807327652[126] = 0;
   out_4952539587807327652[127] = 0;
   out_4952539587807327652[128] = 0;
   out_4952539587807327652[129] = 0;
   out_4952539587807327652[130] = 0;
   out_4952539587807327652[131] = 0;
   out_4952539587807327652[132] = 0;
   out_4952539587807327652[133] = 1;
   out_4952539587807327652[134] = 0;
   out_4952539587807327652[135] = 0;
   out_4952539587807327652[136] = 0;
   out_4952539587807327652[137] = 0;
   out_4952539587807327652[138] = 0;
   out_4952539587807327652[139] = 0;
   out_4952539587807327652[140] = 0;
   out_4952539587807327652[141] = 0;
   out_4952539587807327652[142] = 0;
   out_4952539587807327652[143] = 0;
   out_4952539587807327652[144] = 0;
   out_4952539587807327652[145] = 0;
   out_4952539587807327652[146] = 0;
   out_4952539587807327652[147] = 0;
   out_4952539587807327652[148] = 0;
   out_4952539587807327652[149] = 0;
   out_4952539587807327652[150] = 0;
   out_4952539587807327652[151] = 0;
   out_4952539587807327652[152] = 1;
   out_4952539587807327652[153] = 0;
   out_4952539587807327652[154] = 0;
   out_4952539587807327652[155] = 0;
   out_4952539587807327652[156] = 0;
   out_4952539587807327652[157] = 0;
   out_4952539587807327652[158] = 0;
   out_4952539587807327652[159] = 0;
   out_4952539587807327652[160] = 0;
   out_4952539587807327652[161] = 0;
   out_4952539587807327652[162] = 0;
   out_4952539587807327652[163] = 0;
   out_4952539587807327652[164] = 0;
   out_4952539587807327652[165] = 0;
   out_4952539587807327652[166] = 0;
   out_4952539587807327652[167] = 0;
   out_4952539587807327652[168] = 0;
   out_4952539587807327652[169] = 0;
   out_4952539587807327652[170] = 0;
   out_4952539587807327652[171] = 1;
   out_4952539587807327652[172] = 0;
   out_4952539587807327652[173] = 0;
   out_4952539587807327652[174] = 0;
   out_4952539587807327652[175] = 0;
   out_4952539587807327652[176] = 0;
   out_4952539587807327652[177] = 0;
   out_4952539587807327652[178] = 0;
   out_4952539587807327652[179] = 0;
   out_4952539587807327652[180] = 0;
   out_4952539587807327652[181] = 0;
   out_4952539587807327652[182] = 0;
   out_4952539587807327652[183] = 0;
   out_4952539587807327652[184] = 0;
   out_4952539587807327652[185] = 0;
   out_4952539587807327652[186] = 0;
   out_4952539587807327652[187] = 0;
   out_4952539587807327652[188] = 0;
   out_4952539587807327652[189] = 0;
   out_4952539587807327652[190] = 1;
   out_4952539587807327652[191] = 0;
   out_4952539587807327652[192] = 0;
   out_4952539587807327652[193] = 0;
   out_4952539587807327652[194] = 0;
   out_4952539587807327652[195] = 0;
   out_4952539587807327652[196] = 0;
   out_4952539587807327652[197] = 0;
   out_4952539587807327652[198] = 0;
   out_4952539587807327652[199] = 0;
   out_4952539587807327652[200] = 0;
   out_4952539587807327652[201] = 0;
   out_4952539587807327652[202] = 0;
   out_4952539587807327652[203] = 0;
   out_4952539587807327652[204] = 0;
   out_4952539587807327652[205] = 0;
   out_4952539587807327652[206] = 0;
   out_4952539587807327652[207] = 0;
   out_4952539587807327652[208] = 0;
   out_4952539587807327652[209] = 1;
   out_4952539587807327652[210] = 0;
   out_4952539587807327652[211] = 0;
   out_4952539587807327652[212] = 0;
   out_4952539587807327652[213] = 0;
   out_4952539587807327652[214] = 0;
   out_4952539587807327652[215] = 0;
   out_4952539587807327652[216] = 0;
   out_4952539587807327652[217] = 0;
   out_4952539587807327652[218] = 0;
   out_4952539587807327652[219] = 0;
   out_4952539587807327652[220] = 0;
   out_4952539587807327652[221] = 0;
   out_4952539587807327652[222] = 0;
   out_4952539587807327652[223] = 0;
   out_4952539587807327652[224] = 0;
   out_4952539587807327652[225] = 0;
   out_4952539587807327652[226] = 0;
   out_4952539587807327652[227] = 0;
   out_4952539587807327652[228] = 1;
   out_4952539587807327652[229] = 0;
   out_4952539587807327652[230] = 0;
   out_4952539587807327652[231] = 0;
   out_4952539587807327652[232] = 0;
   out_4952539587807327652[233] = 0;
   out_4952539587807327652[234] = 0;
   out_4952539587807327652[235] = 0;
   out_4952539587807327652[236] = 0;
   out_4952539587807327652[237] = 0;
   out_4952539587807327652[238] = 0;
   out_4952539587807327652[239] = 0;
   out_4952539587807327652[240] = 0;
   out_4952539587807327652[241] = 0;
   out_4952539587807327652[242] = 0;
   out_4952539587807327652[243] = 0;
   out_4952539587807327652[244] = 0;
   out_4952539587807327652[245] = 0;
   out_4952539587807327652[246] = 0;
   out_4952539587807327652[247] = 1;
   out_4952539587807327652[248] = 0;
   out_4952539587807327652[249] = 0;
   out_4952539587807327652[250] = 0;
   out_4952539587807327652[251] = 0;
   out_4952539587807327652[252] = 0;
   out_4952539587807327652[253] = 0;
   out_4952539587807327652[254] = 0;
   out_4952539587807327652[255] = 0;
   out_4952539587807327652[256] = 0;
   out_4952539587807327652[257] = 0;
   out_4952539587807327652[258] = 0;
   out_4952539587807327652[259] = 0;
   out_4952539587807327652[260] = 0;
   out_4952539587807327652[261] = 0;
   out_4952539587807327652[262] = 0;
   out_4952539587807327652[263] = 0;
   out_4952539587807327652[264] = 0;
   out_4952539587807327652[265] = 0;
   out_4952539587807327652[266] = 1;
   out_4952539587807327652[267] = 0;
   out_4952539587807327652[268] = 0;
   out_4952539587807327652[269] = 0;
   out_4952539587807327652[270] = 0;
   out_4952539587807327652[271] = 0;
   out_4952539587807327652[272] = 0;
   out_4952539587807327652[273] = 0;
   out_4952539587807327652[274] = 0;
   out_4952539587807327652[275] = 0;
   out_4952539587807327652[276] = 0;
   out_4952539587807327652[277] = 0;
   out_4952539587807327652[278] = 0;
   out_4952539587807327652[279] = 0;
   out_4952539587807327652[280] = 0;
   out_4952539587807327652[281] = 0;
   out_4952539587807327652[282] = 0;
   out_4952539587807327652[283] = 0;
   out_4952539587807327652[284] = 0;
   out_4952539587807327652[285] = 1;
   out_4952539587807327652[286] = 0;
   out_4952539587807327652[287] = 0;
   out_4952539587807327652[288] = 0;
   out_4952539587807327652[289] = 0;
   out_4952539587807327652[290] = 0;
   out_4952539587807327652[291] = 0;
   out_4952539587807327652[292] = 0;
   out_4952539587807327652[293] = 0;
   out_4952539587807327652[294] = 0;
   out_4952539587807327652[295] = 0;
   out_4952539587807327652[296] = 0;
   out_4952539587807327652[297] = 0;
   out_4952539587807327652[298] = 0;
   out_4952539587807327652[299] = 0;
   out_4952539587807327652[300] = 0;
   out_4952539587807327652[301] = 0;
   out_4952539587807327652[302] = 0;
   out_4952539587807327652[303] = 0;
   out_4952539587807327652[304] = 1;
   out_4952539587807327652[305] = 0;
   out_4952539587807327652[306] = 0;
   out_4952539587807327652[307] = 0;
   out_4952539587807327652[308] = 0;
   out_4952539587807327652[309] = 0;
   out_4952539587807327652[310] = 0;
   out_4952539587807327652[311] = 0;
   out_4952539587807327652[312] = 0;
   out_4952539587807327652[313] = 0;
   out_4952539587807327652[314] = 0;
   out_4952539587807327652[315] = 0;
   out_4952539587807327652[316] = 0;
   out_4952539587807327652[317] = 0;
   out_4952539587807327652[318] = 0;
   out_4952539587807327652[319] = 0;
   out_4952539587807327652[320] = 0;
   out_4952539587807327652[321] = 0;
   out_4952539587807327652[322] = 0;
   out_4952539587807327652[323] = 1;
}
void h_4(double *state, double *unused, double *out_105029621528743882) {
   out_105029621528743882[0] = state[6] + state[9];
   out_105029621528743882[1] = state[7] + state[10];
   out_105029621528743882[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7121654022588970456) {
   out_7121654022588970456[0] = 0;
   out_7121654022588970456[1] = 0;
   out_7121654022588970456[2] = 0;
   out_7121654022588970456[3] = 0;
   out_7121654022588970456[4] = 0;
   out_7121654022588970456[5] = 0;
   out_7121654022588970456[6] = 1;
   out_7121654022588970456[7] = 0;
   out_7121654022588970456[8] = 0;
   out_7121654022588970456[9] = 1;
   out_7121654022588970456[10] = 0;
   out_7121654022588970456[11] = 0;
   out_7121654022588970456[12] = 0;
   out_7121654022588970456[13] = 0;
   out_7121654022588970456[14] = 0;
   out_7121654022588970456[15] = 0;
   out_7121654022588970456[16] = 0;
   out_7121654022588970456[17] = 0;
   out_7121654022588970456[18] = 0;
   out_7121654022588970456[19] = 0;
   out_7121654022588970456[20] = 0;
   out_7121654022588970456[21] = 0;
   out_7121654022588970456[22] = 0;
   out_7121654022588970456[23] = 0;
   out_7121654022588970456[24] = 0;
   out_7121654022588970456[25] = 1;
   out_7121654022588970456[26] = 0;
   out_7121654022588970456[27] = 0;
   out_7121654022588970456[28] = 1;
   out_7121654022588970456[29] = 0;
   out_7121654022588970456[30] = 0;
   out_7121654022588970456[31] = 0;
   out_7121654022588970456[32] = 0;
   out_7121654022588970456[33] = 0;
   out_7121654022588970456[34] = 0;
   out_7121654022588970456[35] = 0;
   out_7121654022588970456[36] = 0;
   out_7121654022588970456[37] = 0;
   out_7121654022588970456[38] = 0;
   out_7121654022588970456[39] = 0;
   out_7121654022588970456[40] = 0;
   out_7121654022588970456[41] = 0;
   out_7121654022588970456[42] = 0;
   out_7121654022588970456[43] = 0;
   out_7121654022588970456[44] = 1;
   out_7121654022588970456[45] = 0;
   out_7121654022588970456[46] = 0;
   out_7121654022588970456[47] = 1;
   out_7121654022588970456[48] = 0;
   out_7121654022588970456[49] = 0;
   out_7121654022588970456[50] = 0;
   out_7121654022588970456[51] = 0;
   out_7121654022588970456[52] = 0;
   out_7121654022588970456[53] = 0;
}
void h_10(double *state, double *unused, double *out_7355867801776776353) {
   out_7355867801776776353[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7355867801776776353[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7355867801776776353[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6146846088544597929) {
   out_6146846088544597929[0] = 0;
   out_6146846088544597929[1] = 9.8100000000000005*cos(state[1]);
   out_6146846088544597929[2] = 0;
   out_6146846088544597929[3] = 0;
   out_6146846088544597929[4] = -state[8];
   out_6146846088544597929[5] = state[7];
   out_6146846088544597929[6] = 0;
   out_6146846088544597929[7] = state[5];
   out_6146846088544597929[8] = -state[4];
   out_6146846088544597929[9] = 0;
   out_6146846088544597929[10] = 0;
   out_6146846088544597929[11] = 0;
   out_6146846088544597929[12] = 1;
   out_6146846088544597929[13] = 0;
   out_6146846088544597929[14] = 0;
   out_6146846088544597929[15] = 1;
   out_6146846088544597929[16] = 0;
   out_6146846088544597929[17] = 0;
   out_6146846088544597929[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6146846088544597929[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6146846088544597929[20] = 0;
   out_6146846088544597929[21] = state[8];
   out_6146846088544597929[22] = 0;
   out_6146846088544597929[23] = -state[6];
   out_6146846088544597929[24] = -state[5];
   out_6146846088544597929[25] = 0;
   out_6146846088544597929[26] = state[3];
   out_6146846088544597929[27] = 0;
   out_6146846088544597929[28] = 0;
   out_6146846088544597929[29] = 0;
   out_6146846088544597929[30] = 0;
   out_6146846088544597929[31] = 1;
   out_6146846088544597929[32] = 0;
   out_6146846088544597929[33] = 0;
   out_6146846088544597929[34] = 1;
   out_6146846088544597929[35] = 0;
   out_6146846088544597929[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6146846088544597929[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6146846088544597929[38] = 0;
   out_6146846088544597929[39] = -state[7];
   out_6146846088544597929[40] = state[6];
   out_6146846088544597929[41] = 0;
   out_6146846088544597929[42] = state[4];
   out_6146846088544597929[43] = -state[3];
   out_6146846088544597929[44] = 0;
   out_6146846088544597929[45] = 0;
   out_6146846088544597929[46] = 0;
   out_6146846088544597929[47] = 0;
   out_6146846088544597929[48] = 0;
   out_6146846088544597929[49] = 0;
   out_6146846088544597929[50] = 1;
   out_6146846088544597929[51] = 0;
   out_6146846088544597929[52] = 0;
   out_6146846088544597929[53] = 1;
}
void h_13(double *state, double *unused, double *out_2344100091734301077) {
   out_2344100091734301077[0] = state[3];
   out_2344100091734301077[1] = state[4];
   out_2344100091734301077[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3909380197256637655) {
   out_3909380197256637655[0] = 0;
   out_3909380197256637655[1] = 0;
   out_3909380197256637655[2] = 0;
   out_3909380197256637655[3] = 1;
   out_3909380197256637655[4] = 0;
   out_3909380197256637655[5] = 0;
   out_3909380197256637655[6] = 0;
   out_3909380197256637655[7] = 0;
   out_3909380197256637655[8] = 0;
   out_3909380197256637655[9] = 0;
   out_3909380197256637655[10] = 0;
   out_3909380197256637655[11] = 0;
   out_3909380197256637655[12] = 0;
   out_3909380197256637655[13] = 0;
   out_3909380197256637655[14] = 0;
   out_3909380197256637655[15] = 0;
   out_3909380197256637655[16] = 0;
   out_3909380197256637655[17] = 0;
   out_3909380197256637655[18] = 0;
   out_3909380197256637655[19] = 0;
   out_3909380197256637655[20] = 0;
   out_3909380197256637655[21] = 0;
   out_3909380197256637655[22] = 1;
   out_3909380197256637655[23] = 0;
   out_3909380197256637655[24] = 0;
   out_3909380197256637655[25] = 0;
   out_3909380197256637655[26] = 0;
   out_3909380197256637655[27] = 0;
   out_3909380197256637655[28] = 0;
   out_3909380197256637655[29] = 0;
   out_3909380197256637655[30] = 0;
   out_3909380197256637655[31] = 0;
   out_3909380197256637655[32] = 0;
   out_3909380197256637655[33] = 0;
   out_3909380197256637655[34] = 0;
   out_3909380197256637655[35] = 0;
   out_3909380197256637655[36] = 0;
   out_3909380197256637655[37] = 0;
   out_3909380197256637655[38] = 0;
   out_3909380197256637655[39] = 0;
   out_3909380197256637655[40] = 0;
   out_3909380197256637655[41] = 1;
   out_3909380197256637655[42] = 0;
   out_3909380197256637655[43] = 0;
   out_3909380197256637655[44] = 0;
   out_3909380197256637655[45] = 0;
   out_3909380197256637655[46] = 0;
   out_3909380197256637655[47] = 0;
   out_3909380197256637655[48] = 0;
   out_3909380197256637655[49] = 0;
   out_3909380197256637655[50] = 0;
   out_3909380197256637655[51] = 0;
   out_3909380197256637655[52] = 0;
   out_3909380197256637655[53] = 0;
}
void h_14(double *state, double *unused, double *out_589344124113930337) {
   out_589344124113930337[0] = state[6];
   out_589344124113930337[1] = state[7];
   out_589344124113930337[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3158413166249485927) {
   out_3158413166249485927[0] = 0;
   out_3158413166249485927[1] = 0;
   out_3158413166249485927[2] = 0;
   out_3158413166249485927[3] = 0;
   out_3158413166249485927[4] = 0;
   out_3158413166249485927[5] = 0;
   out_3158413166249485927[6] = 1;
   out_3158413166249485927[7] = 0;
   out_3158413166249485927[8] = 0;
   out_3158413166249485927[9] = 0;
   out_3158413166249485927[10] = 0;
   out_3158413166249485927[11] = 0;
   out_3158413166249485927[12] = 0;
   out_3158413166249485927[13] = 0;
   out_3158413166249485927[14] = 0;
   out_3158413166249485927[15] = 0;
   out_3158413166249485927[16] = 0;
   out_3158413166249485927[17] = 0;
   out_3158413166249485927[18] = 0;
   out_3158413166249485927[19] = 0;
   out_3158413166249485927[20] = 0;
   out_3158413166249485927[21] = 0;
   out_3158413166249485927[22] = 0;
   out_3158413166249485927[23] = 0;
   out_3158413166249485927[24] = 0;
   out_3158413166249485927[25] = 1;
   out_3158413166249485927[26] = 0;
   out_3158413166249485927[27] = 0;
   out_3158413166249485927[28] = 0;
   out_3158413166249485927[29] = 0;
   out_3158413166249485927[30] = 0;
   out_3158413166249485927[31] = 0;
   out_3158413166249485927[32] = 0;
   out_3158413166249485927[33] = 0;
   out_3158413166249485927[34] = 0;
   out_3158413166249485927[35] = 0;
   out_3158413166249485927[36] = 0;
   out_3158413166249485927[37] = 0;
   out_3158413166249485927[38] = 0;
   out_3158413166249485927[39] = 0;
   out_3158413166249485927[40] = 0;
   out_3158413166249485927[41] = 0;
   out_3158413166249485927[42] = 0;
   out_3158413166249485927[43] = 0;
   out_3158413166249485927[44] = 1;
   out_3158413166249485927[45] = 0;
   out_3158413166249485927[46] = 0;
   out_3158413166249485927[47] = 0;
   out_3158413166249485927[48] = 0;
   out_3158413166249485927[49] = 0;
   out_3158413166249485927[50] = 0;
   out_3158413166249485927[51] = 0;
   out_3158413166249485927[52] = 0;
   out_3158413166249485927[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8550489212526755506) {
  err_fun(nom_x, delta_x, out_8550489212526755506);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2197167056715094306) {
  inv_err_fun(nom_x, true_x, out_2197167056715094306);
}
void pose_H_mod_fun(double *state, double *out_1273572215837011735) {
  H_mod_fun(state, out_1273572215837011735);
}
void pose_f_fun(double *state, double dt, double *out_58843541046312828) {
  f_fun(state,  dt, out_58843541046312828);
}
void pose_F_fun(double *state, double dt, double *out_4952539587807327652) {
  F_fun(state,  dt, out_4952539587807327652);
}
void pose_h_4(double *state, double *unused, double *out_105029621528743882) {
  h_4(state, unused, out_105029621528743882);
}
void pose_H_4(double *state, double *unused, double *out_7121654022588970456) {
  H_4(state, unused, out_7121654022588970456);
}
void pose_h_10(double *state, double *unused, double *out_7355867801776776353) {
  h_10(state, unused, out_7355867801776776353);
}
void pose_H_10(double *state, double *unused, double *out_6146846088544597929) {
  H_10(state, unused, out_6146846088544597929);
}
void pose_h_13(double *state, double *unused, double *out_2344100091734301077) {
  h_13(state, unused, out_2344100091734301077);
}
void pose_H_13(double *state, double *unused, double *out_3909380197256637655) {
  H_13(state, unused, out_3909380197256637655);
}
void pose_h_14(double *state, double *unused, double *out_589344124113930337) {
  h_14(state, unused, out_589344124113930337);
}
void pose_H_14(double *state, double *unused, double *out_3158413166249485927) {
  H_14(state, unused, out_3158413166249485927);
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
