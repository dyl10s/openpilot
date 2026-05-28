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
void err_fun(double *nom_x, double *delta_x, double *out_937271495952840532) {
   out_937271495952840532[0] = delta_x[0] + nom_x[0];
   out_937271495952840532[1] = delta_x[1] + nom_x[1];
   out_937271495952840532[2] = delta_x[2] + nom_x[2];
   out_937271495952840532[3] = delta_x[3] + nom_x[3];
   out_937271495952840532[4] = delta_x[4] + nom_x[4];
   out_937271495952840532[5] = delta_x[5] + nom_x[5];
   out_937271495952840532[6] = delta_x[6] + nom_x[6];
   out_937271495952840532[7] = delta_x[7] + nom_x[7];
   out_937271495952840532[8] = delta_x[8] + nom_x[8];
   out_937271495952840532[9] = delta_x[9] + nom_x[9];
   out_937271495952840532[10] = delta_x[10] + nom_x[10];
   out_937271495952840532[11] = delta_x[11] + nom_x[11];
   out_937271495952840532[12] = delta_x[12] + nom_x[12];
   out_937271495952840532[13] = delta_x[13] + nom_x[13];
   out_937271495952840532[14] = delta_x[14] + nom_x[14];
   out_937271495952840532[15] = delta_x[15] + nom_x[15];
   out_937271495952840532[16] = delta_x[16] + nom_x[16];
   out_937271495952840532[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_712402659692030222) {
   out_712402659692030222[0] = -nom_x[0] + true_x[0];
   out_712402659692030222[1] = -nom_x[1] + true_x[1];
   out_712402659692030222[2] = -nom_x[2] + true_x[2];
   out_712402659692030222[3] = -nom_x[3] + true_x[3];
   out_712402659692030222[4] = -nom_x[4] + true_x[4];
   out_712402659692030222[5] = -nom_x[5] + true_x[5];
   out_712402659692030222[6] = -nom_x[6] + true_x[6];
   out_712402659692030222[7] = -nom_x[7] + true_x[7];
   out_712402659692030222[8] = -nom_x[8] + true_x[8];
   out_712402659692030222[9] = -nom_x[9] + true_x[9];
   out_712402659692030222[10] = -nom_x[10] + true_x[10];
   out_712402659692030222[11] = -nom_x[11] + true_x[11];
   out_712402659692030222[12] = -nom_x[12] + true_x[12];
   out_712402659692030222[13] = -nom_x[13] + true_x[13];
   out_712402659692030222[14] = -nom_x[14] + true_x[14];
   out_712402659692030222[15] = -nom_x[15] + true_x[15];
   out_712402659692030222[16] = -nom_x[16] + true_x[16];
   out_712402659692030222[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4304163029800659692) {
   out_4304163029800659692[0] = 1.0;
   out_4304163029800659692[1] = 0.0;
   out_4304163029800659692[2] = 0.0;
   out_4304163029800659692[3] = 0.0;
   out_4304163029800659692[4] = 0.0;
   out_4304163029800659692[5] = 0.0;
   out_4304163029800659692[6] = 0.0;
   out_4304163029800659692[7] = 0.0;
   out_4304163029800659692[8] = 0.0;
   out_4304163029800659692[9] = 0.0;
   out_4304163029800659692[10] = 0.0;
   out_4304163029800659692[11] = 0.0;
   out_4304163029800659692[12] = 0.0;
   out_4304163029800659692[13] = 0.0;
   out_4304163029800659692[14] = 0.0;
   out_4304163029800659692[15] = 0.0;
   out_4304163029800659692[16] = 0.0;
   out_4304163029800659692[17] = 0.0;
   out_4304163029800659692[18] = 0.0;
   out_4304163029800659692[19] = 1.0;
   out_4304163029800659692[20] = 0.0;
   out_4304163029800659692[21] = 0.0;
   out_4304163029800659692[22] = 0.0;
   out_4304163029800659692[23] = 0.0;
   out_4304163029800659692[24] = 0.0;
   out_4304163029800659692[25] = 0.0;
   out_4304163029800659692[26] = 0.0;
   out_4304163029800659692[27] = 0.0;
   out_4304163029800659692[28] = 0.0;
   out_4304163029800659692[29] = 0.0;
   out_4304163029800659692[30] = 0.0;
   out_4304163029800659692[31] = 0.0;
   out_4304163029800659692[32] = 0.0;
   out_4304163029800659692[33] = 0.0;
   out_4304163029800659692[34] = 0.0;
   out_4304163029800659692[35] = 0.0;
   out_4304163029800659692[36] = 0.0;
   out_4304163029800659692[37] = 0.0;
   out_4304163029800659692[38] = 1.0;
   out_4304163029800659692[39] = 0.0;
   out_4304163029800659692[40] = 0.0;
   out_4304163029800659692[41] = 0.0;
   out_4304163029800659692[42] = 0.0;
   out_4304163029800659692[43] = 0.0;
   out_4304163029800659692[44] = 0.0;
   out_4304163029800659692[45] = 0.0;
   out_4304163029800659692[46] = 0.0;
   out_4304163029800659692[47] = 0.0;
   out_4304163029800659692[48] = 0.0;
   out_4304163029800659692[49] = 0.0;
   out_4304163029800659692[50] = 0.0;
   out_4304163029800659692[51] = 0.0;
   out_4304163029800659692[52] = 0.0;
   out_4304163029800659692[53] = 0.0;
   out_4304163029800659692[54] = 0.0;
   out_4304163029800659692[55] = 0.0;
   out_4304163029800659692[56] = 0.0;
   out_4304163029800659692[57] = 1.0;
   out_4304163029800659692[58] = 0.0;
   out_4304163029800659692[59] = 0.0;
   out_4304163029800659692[60] = 0.0;
   out_4304163029800659692[61] = 0.0;
   out_4304163029800659692[62] = 0.0;
   out_4304163029800659692[63] = 0.0;
   out_4304163029800659692[64] = 0.0;
   out_4304163029800659692[65] = 0.0;
   out_4304163029800659692[66] = 0.0;
   out_4304163029800659692[67] = 0.0;
   out_4304163029800659692[68] = 0.0;
   out_4304163029800659692[69] = 0.0;
   out_4304163029800659692[70] = 0.0;
   out_4304163029800659692[71] = 0.0;
   out_4304163029800659692[72] = 0.0;
   out_4304163029800659692[73] = 0.0;
   out_4304163029800659692[74] = 0.0;
   out_4304163029800659692[75] = 0.0;
   out_4304163029800659692[76] = 1.0;
   out_4304163029800659692[77] = 0.0;
   out_4304163029800659692[78] = 0.0;
   out_4304163029800659692[79] = 0.0;
   out_4304163029800659692[80] = 0.0;
   out_4304163029800659692[81] = 0.0;
   out_4304163029800659692[82] = 0.0;
   out_4304163029800659692[83] = 0.0;
   out_4304163029800659692[84] = 0.0;
   out_4304163029800659692[85] = 0.0;
   out_4304163029800659692[86] = 0.0;
   out_4304163029800659692[87] = 0.0;
   out_4304163029800659692[88] = 0.0;
   out_4304163029800659692[89] = 0.0;
   out_4304163029800659692[90] = 0.0;
   out_4304163029800659692[91] = 0.0;
   out_4304163029800659692[92] = 0.0;
   out_4304163029800659692[93] = 0.0;
   out_4304163029800659692[94] = 0.0;
   out_4304163029800659692[95] = 1.0;
   out_4304163029800659692[96] = 0.0;
   out_4304163029800659692[97] = 0.0;
   out_4304163029800659692[98] = 0.0;
   out_4304163029800659692[99] = 0.0;
   out_4304163029800659692[100] = 0.0;
   out_4304163029800659692[101] = 0.0;
   out_4304163029800659692[102] = 0.0;
   out_4304163029800659692[103] = 0.0;
   out_4304163029800659692[104] = 0.0;
   out_4304163029800659692[105] = 0.0;
   out_4304163029800659692[106] = 0.0;
   out_4304163029800659692[107] = 0.0;
   out_4304163029800659692[108] = 0.0;
   out_4304163029800659692[109] = 0.0;
   out_4304163029800659692[110] = 0.0;
   out_4304163029800659692[111] = 0.0;
   out_4304163029800659692[112] = 0.0;
   out_4304163029800659692[113] = 0.0;
   out_4304163029800659692[114] = 1.0;
   out_4304163029800659692[115] = 0.0;
   out_4304163029800659692[116] = 0.0;
   out_4304163029800659692[117] = 0.0;
   out_4304163029800659692[118] = 0.0;
   out_4304163029800659692[119] = 0.0;
   out_4304163029800659692[120] = 0.0;
   out_4304163029800659692[121] = 0.0;
   out_4304163029800659692[122] = 0.0;
   out_4304163029800659692[123] = 0.0;
   out_4304163029800659692[124] = 0.0;
   out_4304163029800659692[125] = 0.0;
   out_4304163029800659692[126] = 0.0;
   out_4304163029800659692[127] = 0.0;
   out_4304163029800659692[128] = 0.0;
   out_4304163029800659692[129] = 0.0;
   out_4304163029800659692[130] = 0.0;
   out_4304163029800659692[131] = 0.0;
   out_4304163029800659692[132] = 0.0;
   out_4304163029800659692[133] = 1.0;
   out_4304163029800659692[134] = 0.0;
   out_4304163029800659692[135] = 0.0;
   out_4304163029800659692[136] = 0.0;
   out_4304163029800659692[137] = 0.0;
   out_4304163029800659692[138] = 0.0;
   out_4304163029800659692[139] = 0.0;
   out_4304163029800659692[140] = 0.0;
   out_4304163029800659692[141] = 0.0;
   out_4304163029800659692[142] = 0.0;
   out_4304163029800659692[143] = 0.0;
   out_4304163029800659692[144] = 0.0;
   out_4304163029800659692[145] = 0.0;
   out_4304163029800659692[146] = 0.0;
   out_4304163029800659692[147] = 0.0;
   out_4304163029800659692[148] = 0.0;
   out_4304163029800659692[149] = 0.0;
   out_4304163029800659692[150] = 0.0;
   out_4304163029800659692[151] = 0.0;
   out_4304163029800659692[152] = 1.0;
   out_4304163029800659692[153] = 0.0;
   out_4304163029800659692[154] = 0.0;
   out_4304163029800659692[155] = 0.0;
   out_4304163029800659692[156] = 0.0;
   out_4304163029800659692[157] = 0.0;
   out_4304163029800659692[158] = 0.0;
   out_4304163029800659692[159] = 0.0;
   out_4304163029800659692[160] = 0.0;
   out_4304163029800659692[161] = 0.0;
   out_4304163029800659692[162] = 0.0;
   out_4304163029800659692[163] = 0.0;
   out_4304163029800659692[164] = 0.0;
   out_4304163029800659692[165] = 0.0;
   out_4304163029800659692[166] = 0.0;
   out_4304163029800659692[167] = 0.0;
   out_4304163029800659692[168] = 0.0;
   out_4304163029800659692[169] = 0.0;
   out_4304163029800659692[170] = 0.0;
   out_4304163029800659692[171] = 1.0;
   out_4304163029800659692[172] = 0.0;
   out_4304163029800659692[173] = 0.0;
   out_4304163029800659692[174] = 0.0;
   out_4304163029800659692[175] = 0.0;
   out_4304163029800659692[176] = 0.0;
   out_4304163029800659692[177] = 0.0;
   out_4304163029800659692[178] = 0.0;
   out_4304163029800659692[179] = 0.0;
   out_4304163029800659692[180] = 0.0;
   out_4304163029800659692[181] = 0.0;
   out_4304163029800659692[182] = 0.0;
   out_4304163029800659692[183] = 0.0;
   out_4304163029800659692[184] = 0.0;
   out_4304163029800659692[185] = 0.0;
   out_4304163029800659692[186] = 0.0;
   out_4304163029800659692[187] = 0.0;
   out_4304163029800659692[188] = 0.0;
   out_4304163029800659692[189] = 0.0;
   out_4304163029800659692[190] = 1.0;
   out_4304163029800659692[191] = 0.0;
   out_4304163029800659692[192] = 0.0;
   out_4304163029800659692[193] = 0.0;
   out_4304163029800659692[194] = 0.0;
   out_4304163029800659692[195] = 0.0;
   out_4304163029800659692[196] = 0.0;
   out_4304163029800659692[197] = 0.0;
   out_4304163029800659692[198] = 0.0;
   out_4304163029800659692[199] = 0.0;
   out_4304163029800659692[200] = 0.0;
   out_4304163029800659692[201] = 0.0;
   out_4304163029800659692[202] = 0.0;
   out_4304163029800659692[203] = 0.0;
   out_4304163029800659692[204] = 0.0;
   out_4304163029800659692[205] = 0.0;
   out_4304163029800659692[206] = 0.0;
   out_4304163029800659692[207] = 0.0;
   out_4304163029800659692[208] = 0.0;
   out_4304163029800659692[209] = 1.0;
   out_4304163029800659692[210] = 0.0;
   out_4304163029800659692[211] = 0.0;
   out_4304163029800659692[212] = 0.0;
   out_4304163029800659692[213] = 0.0;
   out_4304163029800659692[214] = 0.0;
   out_4304163029800659692[215] = 0.0;
   out_4304163029800659692[216] = 0.0;
   out_4304163029800659692[217] = 0.0;
   out_4304163029800659692[218] = 0.0;
   out_4304163029800659692[219] = 0.0;
   out_4304163029800659692[220] = 0.0;
   out_4304163029800659692[221] = 0.0;
   out_4304163029800659692[222] = 0.0;
   out_4304163029800659692[223] = 0.0;
   out_4304163029800659692[224] = 0.0;
   out_4304163029800659692[225] = 0.0;
   out_4304163029800659692[226] = 0.0;
   out_4304163029800659692[227] = 0.0;
   out_4304163029800659692[228] = 1.0;
   out_4304163029800659692[229] = 0.0;
   out_4304163029800659692[230] = 0.0;
   out_4304163029800659692[231] = 0.0;
   out_4304163029800659692[232] = 0.0;
   out_4304163029800659692[233] = 0.0;
   out_4304163029800659692[234] = 0.0;
   out_4304163029800659692[235] = 0.0;
   out_4304163029800659692[236] = 0.0;
   out_4304163029800659692[237] = 0.0;
   out_4304163029800659692[238] = 0.0;
   out_4304163029800659692[239] = 0.0;
   out_4304163029800659692[240] = 0.0;
   out_4304163029800659692[241] = 0.0;
   out_4304163029800659692[242] = 0.0;
   out_4304163029800659692[243] = 0.0;
   out_4304163029800659692[244] = 0.0;
   out_4304163029800659692[245] = 0.0;
   out_4304163029800659692[246] = 0.0;
   out_4304163029800659692[247] = 1.0;
   out_4304163029800659692[248] = 0.0;
   out_4304163029800659692[249] = 0.0;
   out_4304163029800659692[250] = 0.0;
   out_4304163029800659692[251] = 0.0;
   out_4304163029800659692[252] = 0.0;
   out_4304163029800659692[253] = 0.0;
   out_4304163029800659692[254] = 0.0;
   out_4304163029800659692[255] = 0.0;
   out_4304163029800659692[256] = 0.0;
   out_4304163029800659692[257] = 0.0;
   out_4304163029800659692[258] = 0.0;
   out_4304163029800659692[259] = 0.0;
   out_4304163029800659692[260] = 0.0;
   out_4304163029800659692[261] = 0.0;
   out_4304163029800659692[262] = 0.0;
   out_4304163029800659692[263] = 0.0;
   out_4304163029800659692[264] = 0.0;
   out_4304163029800659692[265] = 0.0;
   out_4304163029800659692[266] = 1.0;
   out_4304163029800659692[267] = 0.0;
   out_4304163029800659692[268] = 0.0;
   out_4304163029800659692[269] = 0.0;
   out_4304163029800659692[270] = 0.0;
   out_4304163029800659692[271] = 0.0;
   out_4304163029800659692[272] = 0.0;
   out_4304163029800659692[273] = 0.0;
   out_4304163029800659692[274] = 0.0;
   out_4304163029800659692[275] = 0.0;
   out_4304163029800659692[276] = 0.0;
   out_4304163029800659692[277] = 0.0;
   out_4304163029800659692[278] = 0.0;
   out_4304163029800659692[279] = 0.0;
   out_4304163029800659692[280] = 0.0;
   out_4304163029800659692[281] = 0.0;
   out_4304163029800659692[282] = 0.0;
   out_4304163029800659692[283] = 0.0;
   out_4304163029800659692[284] = 0.0;
   out_4304163029800659692[285] = 1.0;
   out_4304163029800659692[286] = 0.0;
   out_4304163029800659692[287] = 0.0;
   out_4304163029800659692[288] = 0.0;
   out_4304163029800659692[289] = 0.0;
   out_4304163029800659692[290] = 0.0;
   out_4304163029800659692[291] = 0.0;
   out_4304163029800659692[292] = 0.0;
   out_4304163029800659692[293] = 0.0;
   out_4304163029800659692[294] = 0.0;
   out_4304163029800659692[295] = 0.0;
   out_4304163029800659692[296] = 0.0;
   out_4304163029800659692[297] = 0.0;
   out_4304163029800659692[298] = 0.0;
   out_4304163029800659692[299] = 0.0;
   out_4304163029800659692[300] = 0.0;
   out_4304163029800659692[301] = 0.0;
   out_4304163029800659692[302] = 0.0;
   out_4304163029800659692[303] = 0.0;
   out_4304163029800659692[304] = 1.0;
   out_4304163029800659692[305] = 0.0;
   out_4304163029800659692[306] = 0.0;
   out_4304163029800659692[307] = 0.0;
   out_4304163029800659692[308] = 0.0;
   out_4304163029800659692[309] = 0.0;
   out_4304163029800659692[310] = 0.0;
   out_4304163029800659692[311] = 0.0;
   out_4304163029800659692[312] = 0.0;
   out_4304163029800659692[313] = 0.0;
   out_4304163029800659692[314] = 0.0;
   out_4304163029800659692[315] = 0.0;
   out_4304163029800659692[316] = 0.0;
   out_4304163029800659692[317] = 0.0;
   out_4304163029800659692[318] = 0.0;
   out_4304163029800659692[319] = 0.0;
   out_4304163029800659692[320] = 0.0;
   out_4304163029800659692[321] = 0.0;
   out_4304163029800659692[322] = 0.0;
   out_4304163029800659692[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7809694961382882469) {
   out_7809694961382882469[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7809694961382882469[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7809694961382882469[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7809694961382882469[3] = dt*state[12] + state[3];
   out_7809694961382882469[4] = dt*state[13] + state[4];
   out_7809694961382882469[5] = dt*state[14] + state[5];
   out_7809694961382882469[6] = state[6];
   out_7809694961382882469[7] = state[7];
   out_7809694961382882469[8] = state[8];
   out_7809694961382882469[9] = state[9];
   out_7809694961382882469[10] = state[10];
   out_7809694961382882469[11] = state[11];
   out_7809694961382882469[12] = state[12];
   out_7809694961382882469[13] = state[13];
   out_7809694961382882469[14] = state[14];
   out_7809694961382882469[15] = state[15];
   out_7809694961382882469[16] = state[16];
   out_7809694961382882469[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4402047608279739822) {
   out_4402047608279739822[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4402047608279739822[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4402047608279739822[2] = 0;
   out_4402047608279739822[3] = 0;
   out_4402047608279739822[4] = 0;
   out_4402047608279739822[5] = 0;
   out_4402047608279739822[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4402047608279739822[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4402047608279739822[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4402047608279739822[9] = 0;
   out_4402047608279739822[10] = 0;
   out_4402047608279739822[11] = 0;
   out_4402047608279739822[12] = 0;
   out_4402047608279739822[13] = 0;
   out_4402047608279739822[14] = 0;
   out_4402047608279739822[15] = 0;
   out_4402047608279739822[16] = 0;
   out_4402047608279739822[17] = 0;
   out_4402047608279739822[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4402047608279739822[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4402047608279739822[20] = 0;
   out_4402047608279739822[21] = 0;
   out_4402047608279739822[22] = 0;
   out_4402047608279739822[23] = 0;
   out_4402047608279739822[24] = 0;
   out_4402047608279739822[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4402047608279739822[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4402047608279739822[27] = 0;
   out_4402047608279739822[28] = 0;
   out_4402047608279739822[29] = 0;
   out_4402047608279739822[30] = 0;
   out_4402047608279739822[31] = 0;
   out_4402047608279739822[32] = 0;
   out_4402047608279739822[33] = 0;
   out_4402047608279739822[34] = 0;
   out_4402047608279739822[35] = 0;
   out_4402047608279739822[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4402047608279739822[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4402047608279739822[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4402047608279739822[39] = 0;
   out_4402047608279739822[40] = 0;
   out_4402047608279739822[41] = 0;
   out_4402047608279739822[42] = 0;
   out_4402047608279739822[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4402047608279739822[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4402047608279739822[45] = 0;
   out_4402047608279739822[46] = 0;
   out_4402047608279739822[47] = 0;
   out_4402047608279739822[48] = 0;
   out_4402047608279739822[49] = 0;
   out_4402047608279739822[50] = 0;
   out_4402047608279739822[51] = 0;
   out_4402047608279739822[52] = 0;
   out_4402047608279739822[53] = 0;
   out_4402047608279739822[54] = 0;
   out_4402047608279739822[55] = 0;
   out_4402047608279739822[56] = 0;
   out_4402047608279739822[57] = 1;
   out_4402047608279739822[58] = 0;
   out_4402047608279739822[59] = 0;
   out_4402047608279739822[60] = 0;
   out_4402047608279739822[61] = 0;
   out_4402047608279739822[62] = 0;
   out_4402047608279739822[63] = 0;
   out_4402047608279739822[64] = 0;
   out_4402047608279739822[65] = 0;
   out_4402047608279739822[66] = dt;
   out_4402047608279739822[67] = 0;
   out_4402047608279739822[68] = 0;
   out_4402047608279739822[69] = 0;
   out_4402047608279739822[70] = 0;
   out_4402047608279739822[71] = 0;
   out_4402047608279739822[72] = 0;
   out_4402047608279739822[73] = 0;
   out_4402047608279739822[74] = 0;
   out_4402047608279739822[75] = 0;
   out_4402047608279739822[76] = 1;
   out_4402047608279739822[77] = 0;
   out_4402047608279739822[78] = 0;
   out_4402047608279739822[79] = 0;
   out_4402047608279739822[80] = 0;
   out_4402047608279739822[81] = 0;
   out_4402047608279739822[82] = 0;
   out_4402047608279739822[83] = 0;
   out_4402047608279739822[84] = 0;
   out_4402047608279739822[85] = dt;
   out_4402047608279739822[86] = 0;
   out_4402047608279739822[87] = 0;
   out_4402047608279739822[88] = 0;
   out_4402047608279739822[89] = 0;
   out_4402047608279739822[90] = 0;
   out_4402047608279739822[91] = 0;
   out_4402047608279739822[92] = 0;
   out_4402047608279739822[93] = 0;
   out_4402047608279739822[94] = 0;
   out_4402047608279739822[95] = 1;
   out_4402047608279739822[96] = 0;
   out_4402047608279739822[97] = 0;
   out_4402047608279739822[98] = 0;
   out_4402047608279739822[99] = 0;
   out_4402047608279739822[100] = 0;
   out_4402047608279739822[101] = 0;
   out_4402047608279739822[102] = 0;
   out_4402047608279739822[103] = 0;
   out_4402047608279739822[104] = dt;
   out_4402047608279739822[105] = 0;
   out_4402047608279739822[106] = 0;
   out_4402047608279739822[107] = 0;
   out_4402047608279739822[108] = 0;
   out_4402047608279739822[109] = 0;
   out_4402047608279739822[110] = 0;
   out_4402047608279739822[111] = 0;
   out_4402047608279739822[112] = 0;
   out_4402047608279739822[113] = 0;
   out_4402047608279739822[114] = 1;
   out_4402047608279739822[115] = 0;
   out_4402047608279739822[116] = 0;
   out_4402047608279739822[117] = 0;
   out_4402047608279739822[118] = 0;
   out_4402047608279739822[119] = 0;
   out_4402047608279739822[120] = 0;
   out_4402047608279739822[121] = 0;
   out_4402047608279739822[122] = 0;
   out_4402047608279739822[123] = 0;
   out_4402047608279739822[124] = 0;
   out_4402047608279739822[125] = 0;
   out_4402047608279739822[126] = 0;
   out_4402047608279739822[127] = 0;
   out_4402047608279739822[128] = 0;
   out_4402047608279739822[129] = 0;
   out_4402047608279739822[130] = 0;
   out_4402047608279739822[131] = 0;
   out_4402047608279739822[132] = 0;
   out_4402047608279739822[133] = 1;
   out_4402047608279739822[134] = 0;
   out_4402047608279739822[135] = 0;
   out_4402047608279739822[136] = 0;
   out_4402047608279739822[137] = 0;
   out_4402047608279739822[138] = 0;
   out_4402047608279739822[139] = 0;
   out_4402047608279739822[140] = 0;
   out_4402047608279739822[141] = 0;
   out_4402047608279739822[142] = 0;
   out_4402047608279739822[143] = 0;
   out_4402047608279739822[144] = 0;
   out_4402047608279739822[145] = 0;
   out_4402047608279739822[146] = 0;
   out_4402047608279739822[147] = 0;
   out_4402047608279739822[148] = 0;
   out_4402047608279739822[149] = 0;
   out_4402047608279739822[150] = 0;
   out_4402047608279739822[151] = 0;
   out_4402047608279739822[152] = 1;
   out_4402047608279739822[153] = 0;
   out_4402047608279739822[154] = 0;
   out_4402047608279739822[155] = 0;
   out_4402047608279739822[156] = 0;
   out_4402047608279739822[157] = 0;
   out_4402047608279739822[158] = 0;
   out_4402047608279739822[159] = 0;
   out_4402047608279739822[160] = 0;
   out_4402047608279739822[161] = 0;
   out_4402047608279739822[162] = 0;
   out_4402047608279739822[163] = 0;
   out_4402047608279739822[164] = 0;
   out_4402047608279739822[165] = 0;
   out_4402047608279739822[166] = 0;
   out_4402047608279739822[167] = 0;
   out_4402047608279739822[168] = 0;
   out_4402047608279739822[169] = 0;
   out_4402047608279739822[170] = 0;
   out_4402047608279739822[171] = 1;
   out_4402047608279739822[172] = 0;
   out_4402047608279739822[173] = 0;
   out_4402047608279739822[174] = 0;
   out_4402047608279739822[175] = 0;
   out_4402047608279739822[176] = 0;
   out_4402047608279739822[177] = 0;
   out_4402047608279739822[178] = 0;
   out_4402047608279739822[179] = 0;
   out_4402047608279739822[180] = 0;
   out_4402047608279739822[181] = 0;
   out_4402047608279739822[182] = 0;
   out_4402047608279739822[183] = 0;
   out_4402047608279739822[184] = 0;
   out_4402047608279739822[185] = 0;
   out_4402047608279739822[186] = 0;
   out_4402047608279739822[187] = 0;
   out_4402047608279739822[188] = 0;
   out_4402047608279739822[189] = 0;
   out_4402047608279739822[190] = 1;
   out_4402047608279739822[191] = 0;
   out_4402047608279739822[192] = 0;
   out_4402047608279739822[193] = 0;
   out_4402047608279739822[194] = 0;
   out_4402047608279739822[195] = 0;
   out_4402047608279739822[196] = 0;
   out_4402047608279739822[197] = 0;
   out_4402047608279739822[198] = 0;
   out_4402047608279739822[199] = 0;
   out_4402047608279739822[200] = 0;
   out_4402047608279739822[201] = 0;
   out_4402047608279739822[202] = 0;
   out_4402047608279739822[203] = 0;
   out_4402047608279739822[204] = 0;
   out_4402047608279739822[205] = 0;
   out_4402047608279739822[206] = 0;
   out_4402047608279739822[207] = 0;
   out_4402047608279739822[208] = 0;
   out_4402047608279739822[209] = 1;
   out_4402047608279739822[210] = 0;
   out_4402047608279739822[211] = 0;
   out_4402047608279739822[212] = 0;
   out_4402047608279739822[213] = 0;
   out_4402047608279739822[214] = 0;
   out_4402047608279739822[215] = 0;
   out_4402047608279739822[216] = 0;
   out_4402047608279739822[217] = 0;
   out_4402047608279739822[218] = 0;
   out_4402047608279739822[219] = 0;
   out_4402047608279739822[220] = 0;
   out_4402047608279739822[221] = 0;
   out_4402047608279739822[222] = 0;
   out_4402047608279739822[223] = 0;
   out_4402047608279739822[224] = 0;
   out_4402047608279739822[225] = 0;
   out_4402047608279739822[226] = 0;
   out_4402047608279739822[227] = 0;
   out_4402047608279739822[228] = 1;
   out_4402047608279739822[229] = 0;
   out_4402047608279739822[230] = 0;
   out_4402047608279739822[231] = 0;
   out_4402047608279739822[232] = 0;
   out_4402047608279739822[233] = 0;
   out_4402047608279739822[234] = 0;
   out_4402047608279739822[235] = 0;
   out_4402047608279739822[236] = 0;
   out_4402047608279739822[237] = 0;
   out_4402047608279739822[238] = 0;
   out_4402047608279739822[239] = 0;
   out_4402047608279739822[240] = 0;
   out_4402047608279739822[241] = 0;
   out_4402047608279739822[242] = 0;
   out_4402047608279739822[243] = 0;
   out_4402047608279739822[244] = 0;
   out_4402047608279739822[245] = 0;
   out_4402047608279739822[246] = 0;
   out_4402047608279739822[247] = 1;
   out_4402047608279739822[248] = 0;
   out_4402047608279739822[249] = 0;
   out_4402047608279739822[250] = 0;
   out_4402047608279739822[251] = 0;
   out_4402047608279739822[252] = 0;
   out_4402047608279739822[253] = 0;
   out_4402047608279739822[254] = 0;
   out_4402047608279739822[255] = 0;
   out_4402047608279739822[256] = 0;
   out_4402047608279739822[257] = 0;
   out_4402047608279739822[258] = 0;
   out_4402047608279739822[259] = 0;
   out_4402047608279739822[260] = 0;
   out_4402047608279739822[261] = 0;
   out_4402047608279739822[262] = 0;
   out_4402047608279739822[263] = 0;
   out_4402047608279739822[264] = 0;
   out_4402047608279739822[265] = 0;
   out_4402047608279739822[266] = 1;
   out_4402047608279739822[267] = 0;
   out_4402047608279739822[268] = 0;
   out_4402047608279739822[269] = 0;
   out_4402047608279739822[270] = 0;
   out_4402047608279739822[271] = 0;
   out_4402047608279739822[272] = 0;
   out_4402047608279739822[273] = 0;
   out_4402047608279739822[274] = 0;
   out_4402047608279739822[275] = 0;
   out_4402047608279739822[276] = 0;
   out_4402047608279739822[277] = 0;
   out_4402047608279739822[278] = 0;
   out_4402047608279739822[279] = 0;
   out_4402047608279739822[280] = 0;
   out_4402047608279739822[281] = 0;
   out_4402047608279739822[282] = 0;
   out_4402047608279739822[283] = 0;
   out_4402047608279739822[284] = 0;
   out_4402047608279739822[285] = 1;
   out_4402047608279739822[286] = 0;
   out_4402047608279739822[287] = 0;
   out_4402047608279739822[288] = 0;
   out_4402047608279739822[289] = 0;
   out_4402047608279739822[290] = 0;
   out_4402047608279739822[291] = 0;
   out_4402047608279739822[292] = 0;
   out_4402047608279739822[293] = 0;
   out_4402047608279739822[294] = 0;
   out_4402047608279739822[295] = 0;
   out_4402047608279739822[296] = 0;
   out_4402047608279739822[297] = 0;
   out_4402047608279739822[298] = 0;
   out_4402047608279739822[299] = 0;
   out_4402047608279739822[300] = 0;
   out_4402047608279739822[301] = 0;
   out_4402047608279739822[302] = 0;
   out_4402047608279739822[303] = 0;
   out_4402047608279739822[304] = 1;
   out_4402047608279739822[305] = 0;
   out_4402047608279739822[306] = 0;
   out_4402047608279739822[307] = 0;
   out_4402047608279739822[308] = 0;
   out_4402047608279739822[309] = 0;
   out_4402047608279739822[310] = 0;
   out_4402047608279739822[311] = 0;
   out_4402047608279739822[312] = 0;
   out_4402047608279739822[313] = 0;
   out_4402047608279739822[314] = 0;
   out_4402047608279739822[315] = 0;
   out_4402047608279739822[316] = 0;
   out_4402047608279739822[317] = 0;
   out_4402047608279739822[318] = 0;
   out_4402047608279739822[319] = 0;
   out_4402047608279739822[320] = 0;
   out_4402047608279739822[321] = 0;
   out_4402047608279739822[322] = 0;
   out_4402047608279739822[323] = 1;
}
void h_4(double *state, double *unused, double *out_1761018668225147827) {
   out_1761018668225147827[0] = state[6] + state[9];
   out_1761018668225147827[1] = state[7] + state[10];
   out_1761018668225147827[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6123861755706956553) {
   out_6123861755706956553[0] = 0;
   out_6123861755706956553[1] = 0;
   out_6123861755706956553[2] = 0;
   out_6123861755706956553[3] = 0;
   out_6123861755706956553[4] = 0;
   out_6123861755706956553[5] = 0;
   out_6123861755706956553[6] = 1;
   out_6123861755706956553[7] = 0;
   out_6123861755706956553[8] = 0;
   out_6123861755706956553[9] = 1;
   out_6123861755706956553[10] = 0;
   out_6123861755706956553[11] = 0;
   out_6123861755706956553[12] = 0;
   out_6123861755706956553[13] = 0;
   out_6123861755706956553[14] = 0;
   out_6123861755706956553[15] = 0;
   out_6123861755706956553[16] = 0;
   out_6123861755706956553[17] = 0;
   out_6123861755706956553[18] = 0;
   out_6123861755706956553[19] = 0;
   out_6123861755706956553[20] = 0;
   out_6123861755706956553[21] = 0;
   out_6123861755706956553[22] = 0;
   out_6123861755706956553[23] = 0;
   out_6123861755706956553[24] = 0;
   out_6123861755706956553[25] = 1;
   out_6123861755706956553[26] = 0;
   out_6123861755706956553[27] = 0;
   out_6123861755706956553[28] = 1;
   out_6123861755706956553[29] = 0;
   out_6123861755706956553[30] = 0;
   out_6123861755706956553[31] = 0;
   out_6123861755706956553[32] = 0;
   out_6123861755706956553[33] = 0;
   out_6123861755706956553[34] = 0;
   out_6123861755706956553[35] = 0;
   out_6123861755706956553[36] = 0;
   out_6123861755706956553[37] = 0;
   out_6123861755706956553[38] = 0;
   out_6123861755706956553[39] = 0;
   out_6123861755706956553[40] = 0;
   out_6123861755706956553[41] = 0;
   out_6123861755706956553[42] = 0;
   out_6123861755706956553[43] = 0;
   out_6123861755706956553[44] = 1;
   out_6123861755706956553[45] = 0;
   out_6123861755706956553[46] = 0;
   out_6123861755706956553[47] = 1;
   out_6123861755706956553[48] = 0;
   out_6123861755706956553[49] = 0;
   out_6123861755706956553[50] = 0;
   out_6123861755706956553[51] = 0;
   out_6123861755706956553[52] = 0;
   out_6123861755706956553[53] = 0;
}
void h_10(double *state, double *unused, double *out_5906261859060682989) {
   out_5906261859060682989[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5906261859060682989[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5906261859060682989[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8717187080084033317) {
   out_8717187080084033317[0] = 0;
   out_8717187080084033317[1] = 9.8100000000000005*cos(state[1]);
   out_8717187080084033317[2] = 0;
   out_8717187080084033317[3] = 0;
   out_8717187080084033317[4] = -state[8];
   out_8717187080084033317[5] = state[7];
   out_8717187080084033317[6] = 0;
   out_8717187080084033317[7] = state[5];
   out_8717187080084033317[8] = -state[4];
   out_8717187080084033317[9] = 0;
   out_8717187080084033317[10] = 0;
   out_8717187080084033317[11] = 0;
   out_8717187080084033317[12] = 1;
   out_8717187080084033317[13] = 0;
   out_8717187080084033317[14] = 0;
   out_8717187080084033317[15] = 1;
   out_8717187080084033317[16] = 0;
   out_8717187080084033317[17] = 0;
   out_8717187080084033317[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8717187080084033317[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8717187080084033317[20] = 0;
   out_8717187080084033317[21] = state[8];
   out_8717187080084033317[22] = 0;
   out_8717187080084033317[23] = -state[6];
   out_8717187080084033317[24] = -state[5];
   out_8717187080084033317[25] = 0;
   out_8717187080084033317[26] = state[3];
   out_8717187080084033317[27] = 0;
   out_8717187080084033317[28] = 0;
   out_8717187080084033317[29] = 0;
   out_8717187080084033317[30] = 0;
   out_8717187080084033317[31] = 1;
   out_8717187080084033317[32] = 0;
   out_8717187080084033317[33] = 0;
   out_8717187080084033317[34] = 1;
   out_8717187080084033317[35] = 0;
   out_8717187080084033317[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8717187080084033317[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8717187080084033317[38] = 0;
   out_8717187080084033317[39] = -state[7];
   out_8717187080084033317[40] = state[6];
   out_8717187080084033317[41] = 0;
   out_8717187080084033317[42] = state[4];
   out_8717187080084033317[43] = -state[3];
   out_8717187080084033317[44] = 0;
   out_8717187080084033317[45] = 0;
   out_8717187080084033317[46] = 0;
   out_8717187080084033317[47] = 0;
   out_8717187080084033317[48] = 0;
   out_8717187080084033317[49] = 0;
   out_8717187080084033317[50] = 1;
   out_8717187080084033317[51] = 0;
   out_8717187080084033317[52] = 0;
   out_8717187080084033317[53] = 1;
}
void h_13(double *state, double *unused, double *out_5437403947989237748) {
   out_5437403947989237748[0] = state[3];
   out_5437403947989237748[1] = state[4];
   out_5437403947989237748[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8489126854700071039) {
   out_8489126854700071039[0] = 0;
   out_8489126854700071039[1] = 0;
   out_8489126854700071039[2] = 0;
   out_8489126854700071039[3] = 1;
   out_8489126854700071039[4] = 0;
   out_8489126854700071039[5] = 0;
   out_8489126854700071039[6] = 0;
   out_8489126854700071039[7] = 0;
   out_8489126854700071039[8] = 0;
   out_8489126854700071039[9] = 0;
   out_8489126854700071039[10] = 0;
   out_8489126854700071039[11] = 0;
   out_8489126854700071039[12] = 0;
   out_8489126854700071039[13] = 0;
   out_8489126854700071039[14] = 0;
   out_8489126854700071039[15] = 0;
   out_8489126854700071039[16] = 0;
   out_8489126854700071039[17] = 0;
   out_8489126854700071039[18] = 0;
   out_8489126854700071039[19] = 0;
   out_8489126854700071039[20] = 0;
   out_8489126854700071039[21] = 0;
   out_8489126854700071039[22] = 1;
   out_8489126854700071039[23] = 0;
   out_8489126854700071039[24] = 0;
   out_8489126854700071039[25] = 0;
   out_8489126854700071039[26] = 0;
   out_8489126854700071039[27] = 0;
   out_8489126854700071039[28] = 0;
   out_8489126854700071039[29] = 0;
   out_8489126854700071039[30] = 0;
   out_8489126854700071039[31] = 0;
   out_8489126854700071039[32] = 0;
   out_8489126854700071039[33] = 0;
   out_8489126854700071039[34] = 0;
   out_8489126854700071039[35] = 0;
   out_8489126854700071039[36] = 0;
   out_8489126854700071039[37] = 0;
   out_8489126854700071039[38] = 0;
   out_8489126854700071039[39] = 0;
   out_8489126854700071039[40] = 0;
   out_8489126854700071039[41] = 1;
   out_8489126854700071039[42] = 0;
   out_8489126854700071039[43] = 0;
   out_8489126854700071039[44] = 0;
   out_8489126854700071039[45] = 0;
   out_8489126854700071039[46] = 0;
   out_8489126854700071039[47] = 0;
   out_8489126854700071039[48] = 0;
   out_8489126854700071039[49] = 0;
   out_8489126854700071039[50] = 0;
   out_8489126854700071039[51] = 0;
   out_8489126854700071039[52] = 0;
   out_8489126854700071039[53] = 0;
}
void h_14(double *state, double *unused, double *out_2973157686650314108) {
   out_2973157686650314108[0] = state[6];
   out_2973157686650314108[1] = state[7];
   out_2973157686650314108[2] = state[8];
}
void H_14(double *state, double *unused, double *out_9206650188002328849) {
   out_9206650188002328849[0] = 0;
   out_9206650188002328849[1] = 0;
   out_9206650188002328849[2] = 0;
   out_9206650188002328849[3] = 0;
   out_9206650188002328849[4] = 0;
   out_9206650188002328849[5] = 0;
   out_9206650188002328849[6] = 1;
   out_9206650188002328849[7] = 0;
   out_9206650188002328849[8] = 0;
   out_9206650188002328849[9] = 0;
   out_9206650188002328849[10] = 0;
   out_9206650188002328849[11] = 0;
   out_9206650188002328849[12] = 0;
   out_9206650188002328849[13] = 0;
   out_9206650188002328849[14] = 0;
   out_9206650188002328849[15] = 0;
   out_9206650188002328849[16] = 0;
   out_9206650188002328849[17] = 0;
   out_9206650188002328849[18] = 0;
   out_9206650188002328849[19] = 0;
   out_9206650188002328849[20] = 0;
   out_9206650188002328849[21] = 0;
   out_9206650188002328849[22] = 0;
   out_9206650188002328849[23] = 0;
   out_9206650188002328849[24] = 0;
   out_9206650188002328849[25] = 1;
   out_9206650188002328849[26] = 0;
   out_9206650188002328849[27] = 0;
   out_9206650188002328849[28] = 0;
   out_9206650188002328849[29] = 0;
   out_9206650188002328849[30] = 0;
   out_9206650188002328849[31] = 0;
   out_9206650188002328849[32] = 0;
   out_9206650188002328849[33] = 0;
   out_9206650188002328849[34] = 0;
   out_9206650188002328849[35] = 0;
   out_9206650188002328849[36] = 0;
   out_9206650188002328849[37] = 0;
   out_9206650188002328849[38] = 0;
   out_9206650188002328849[39] = 0;
   out_9206650188002328849[40] = 0;
   out_9206650188002328849[41] = 0;
   out_9206650188002328849[42] = 0;
   out_9206650188002328849[43] = 0;
   out_9206650188002328849[44] = 1;
   out_9206650188002328849[45] = 0;
   out_9206650188002328849[46] = 0;
   out_9206650188002328849[47] = 0;
   out_9206650188002328849[48] = 0;
   out_9206650188002328849[49] = 0;
   out_9206650188002328849[50] = 0;
   out_9206650188002328849[51] = 0;
   out_9206650188002328849[52] = 0;
   out_9206650188002328849[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_937271495952840532) {
  err_fun(nom_x, delta_x, out_937271495952840532);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_712402659692030222) {
  inv_err_fun(nom_x, true_x, out_712402659692030222);
}
void pose_H_mod_fun(double *state, double *out_4304163029800659692) {
  H_mod_fun(state, out_4304163029800659692);
}
void pose_f_fun(double *state, double dt, double *out_7809694961382882469) {
  f_fun(state,  dt, out_7809694961382882469);
}
void pose_F_fun(double *state, double dt, double *out_4402047608279739822) {
  F_fun(state,  dt, out_4402047608279739822);
}
void pose_h_4(double *state, double *unused, double *out_1761018668225147827) {
  h_4(state, unused, out_1761018668225147827);
}
void pose_H_4(double *state, double *unused, double *out_6123861755706956553) {
  H_4(state, unused, out_6123861755706956553);
}
void pose_h_10(double *state, double *unused, double *out_5906261859060682989) {
  h_10(state, unused, out_5906261859060682989);
}
void pose_H_10(double *state, double *unused, double *out_8717187080084033317) {
  H_10(state, unused, out_8717187080084033317);
}
void pose_h_13(double *state, double *unused, double *out_5437403947989237748) {
  h_13(state, unused, out_5437403947989237748);
}
void pose_H_13(double *state, double *unused, double *out_8489126854700071039) {
  H_13(state, unused, out_8489126854700071039);
}
void pose_h_14(double *state, double *unused, double *out_2973157686650314108) {
  h_14(state, unused, out_2973157686650314108);
}
void pose_H_14(double *state, double *unused, double *out_9206650188002328849) {
  H_14(state, unused, out_9206650188002328849);
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
