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
void err_fun(double *nom_x, double *delta_x, double *out_7636423458425794019) {
   out_7636423458425794019[0] = delta_x[0] + nom_x[0];
   out_7636423458425794019[1] = delta_x[1] + nom_x[1];
   out_7636423458425794019[2] = delta_x[2] + nom_x[2];
   out_7636423458425794019[3] = delta_x[3] + nom_x[3];
   out_7636423458425794019[4] = delta_x[4] + nom_x[4];
   out_7636423458425794019[5] = delta_x[5] + nom_x[5];
   out_7636423458425794019[6] = delta_x[6] + nom_x[6];
   out_7636423458425794019[7] = delta_x[7] + nom_x[7];
   out_7636423458425794019[8] = delta_x[8] + nom_x[8];
   out_7636423458425794019[9] = delta_x[9] + nom_x[9];
   out_7636423458425794019[10] = delta_x[10] + nom_x[10];
   out_7636423458425794019[11] = delta_x[11] + nom_x[11];
   out_7636423458425794019[12] = delta_x[12] + nom_x[12];
   out_7636423458425794019[13] = delta_x[13] + nom_x[13];
   out_7636423458425794019[14] = delta_x[14] + nom_x[14];
   out_7636423458425794019[15] = delta_x[15] + nom_x[15];
   out_7636423458425794019[16] = delta_x[16] + nom_x[16];
   out_7636423458425794019[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4233815579108349573) {
   out_4233815579108349573[0] = -nom_x[0] + true_x[0];
   out_4233815579108349573[1] = -nom_x[1] + true_x[1];
   out_4233815579108349573[2] = -nom_x[2] + true_x[2];
   out_4233815579108349573[3] = -nom_x[3] + true_x[3];
   out_4233815579108349573[4] = -nom_x[4] + true_x[4];
   out_4233815579108349573[5] = -nom_x[5] + true_x[5];
   out_4233815579108349573[6] = -nom_x[6] + true_x[6];
   out_4233815579108349573[7] = -nom_x[7] + true_x[7];
   out_4233815579108349573[8] = -nom_x[8] + true_x[8];
   out_4233815579108349573[9] = -nom_x[9] + true_x[9];
   out_4233815579108349573[10] = -nom_x[10] + true_x[10];
   out_4233815579108349573[11] = -nom_x[11] + true_x[11];
   out_4233815579108349573[12] = -nom_x[12] + true_x[12];
   out_4233815579108349573[13] = -nom_x[13] + true_x[13];
   out_4233815579108349573[14] = -nom_x[14] + true_x[14];
   out_4233815579108349573[15] = -nom_x[15] + true_x[15];
   out_4233815579108349573[16] = -nom_x[16] + true_x[16];
   out_4233815579108349573[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_534131660440936662) {
   out_534131660440936662[0] = 1.0;
   out_534131660440936662[1] = 0.0;
   out_534131660440936662[2] = 0.0;
   out_534131660440936662[3] = 0.0;
   out_534131660440936662[4] = 0.0;
   out_534131660440936662[5] = 0.0;
   out_534131660440936662[6] = 0.0;
   out_534131660440936662[7] = 0.0;
   out_534131660440936662[8] = 0.0;
   out_534131660440936662[9] = 0.0;
   out_534131660440936662[10] = 0.0;
   out_534131660440936662[11] = 0.0;
   out_534131660440936662[12] = 0.0;
   out_534131660440936662[13] = 0.0;
   out_534131660440936662[14] = 0.0;
   out_534131660440936662[15] = 0.0;
   out_534131660440936662[16] = 0.0;
   out_534131660440936662[17] = 0.0;
   out_534131660440936662[18] = 0.0;
   out_534131660440936662[19] = 1.0;
   out_534131660440936662[20] = 0.0;
   out_534131660440936662[21] = 0.0;
   out_534131660440936662[22] = 0.0;
   out_534131660440936662[23] = 0.0;
   out_534131660440936662[24] = 0.0;
   out_534131660440936662[25] = 0.0;
   out_534131660440936662[26] = 0.0;
   out_534131660440936662[27] = 0.0;
   out_534131660440936662[28] = 0.0;
   out_534131660440936662[29] = 0.0;
   out_534131660440936662[30] = 0.0;
   out_534131660440936662[31] = 0.0;
   out_534131660440936662[32] = 0.0;
   out_534131660440936662[33] = 0.0;
   out_534131660440936662[34] = 0.0;
   out_534131660440936662[35] = 0.0;
   out_534131660440936662[36] = 0.0;
   out_534131660440936662[37] = 0.0;
   out_534131660440936662[38] = 1.0;
   out_534131660440936662[39] = 0.0;
   out_534131660440936662[40] = 0.0;
   out_534131660440936662[41] = 0.0;
   out_534131660440936662[42] = 0.0;
   out_534131660440936662[43] = 0.0;
   out_534131660440936662[44] = 0.0;
   out_534131660440936662[45] = 0.0;
   out_534131660440936662[46] = 0.0;
   out_534131660440936662[47] = 0.0;
   out_534131660440936662[48] = 0.0;
   out_534131660440936662[49] = 0.0;
   out_534131660440936662[50] = 0.0;
   out_534131660440936662[51] = 0.0;
   out_534131660440936662[52] = 0.0;
   out_534131660440936662[53] = 0.0;
   out_534131660440936662[54] = 0.0;
   out_534131660440936662[55] = 0.0;
   out_534131660440936662[56] = 0.0;
   out_534131660440936662[57] = 1.0;
   out_534131660440936662[58] = 0.0;
   out_534131660440936662[59] = 0.0;
   out_534131660440936662[60] = 0.0;
   out_534131660440936662[61] = 0.0;
   out_534131660440936662[62] = 0.0;
   out_534131660440936662[63] = 0.0;
   out_534131660440936662[64] = 0.0;
   out_534131660440936662[65] = 0.0;
   out_534131660440936662[66] = 0.0;
   out_534131660440936662[67] = 0.0;
   out_534131660440936662[68] = 0.0;
   out_534131660440936662[69] = 0.0;
   out_534131660440936662[70] = 0.0;
   out_534131660440936662[71] = 0.0;
   out_534131660440936662[72] = 0.0;
   out_534131660440936662[73] = 0.0;
   out_534131660440936662[74] = 0.0;
   out_534131660440936662[75] = 0.0;
   out_534131660440936662[76] = 1.0;
   out_534131660440936662[77] = 0.0;
   out_534131660440936662[78] = 0.0;
   out_534131660440936662[79] = 0.0;
   out_534131660440936662[80] = 0.0;
   out_534131660440936662[81] = 0.0;
   out_534131660440936662[82] = 0.0;
   out_534131660440936662[83] = 0.0;
   out_534131660440936662[84] = 0.0;
   out_534131660440936662[85] = 0.0;
   out_534131660440936662[86] = 0.0;
   out_534131660440936662[87] = 0.0;
   out_534131660440936662[88] = 0.0;
   out_534131660440936662[89] = 0.0;
   out_534131660440936662[90] = 0.0;
   out_534131660440936662[91] = 0.0;
   out_534131660440936662[92] = 0.0;
   out_534131660440936662[93] = 0.0;
   out_534131660440936662[94] = 0.0;
   out_534131660440936662[95] = 1.0;
   out_534131660440936662[96] = 0.0;
   out_534131660440936662[97] = 0.0;
   out_534131660440936662[98] = 0.0;
   out_534131660440936662[99] = 0.0;
   out_534131660440936662[100] = 0.0;
   out_534131660440936662[101] = 0.0;
   out_534131660440936662[102] = 0.0;
   out_534131660440936662[103] = 0.0;
   out_534131660440936662[104] = 0.0;
   out_534131660440936662[105] = 0.0;
   out_534131660440936662[106] = 0.0;
   out_534131660440936662[107] = 0.0;
   out_534131660440936662[108] = 0.0;
   out_534131660440936662[109] = 0.0;
   out_534131660440936662[110] = 0.0;
   out_534131660440936662[111] = 0.0;
   out_534131660440936662[112] = 0.0;
   out_534131660440936662[113] = 0.0;
   out_534131660440936662[114] = 1.0;
   out_534131660440936662[115] = 0.0;
   out_534131660440936662[116] = 0.0;
   out_534131660440936662[117] = 0.0;
   out_534131660440936662[118] = 0.0;
   out_534131660440936662[119] = 0.0;
   out_534131660440936662[120] = 0.0;
   out_534131660440936662[121] = 0.0;
   out_534131660440936662[122] = 0.0;
   out_534131660440936662[123] = 0.0;
   out_534131660440936662[124] = 0.0;
   out_534131660440936662[125] = 0.0;
   out_534131660440936662[126] = 0.0;
   out_534131660440936662[127] = 0.0;
   out_534131660440936662[128] = 0.0;
   out_534131660440936662[129] = 0.0;
   out_534131660440936662[130] = 0.0;
   out_534131660440936662[131] = 0.0;
   out_534131660440936662[132] = 0.0;
   out_534131660440936662[133] = 1.0;
   out_534131660440936662[134] = 0.0;
   out_534131660440936662[135] = 0.0;
   out_534131660440936662[136] = 0.0;
   out_534131660440936662[137] = 0.0;
   out_534131660440936662[138] = 0.0;
   out_534131660440936662[139] = 0.0;
   out_534131660440936662[140] = 0.0;
   out_534131660440936662[141] = 0.0;
   out_534131660440936662[142] = 0.0;
   out_534131660440936662[143] = 0.0;
   out_534131660440936662[144] = 0.0;
   out_534131660440936662[145] = 0.0;
   out_534131660440936662[146] = 0.0;
   out_534131660440936662[147] = 0.0;
   out_534131660440936662[148] = 0.0;
   out_534131660440936662[149] = 0.0;
   out_534131660440936662[150] = 0.0;
   out_534131660440936662[151] = 0.0;
   out_534131660440936662[152] = 1.0;
   out_534131660440936662[153] = 0.0;
   out_534131660440936662[154] = 0.0;
   out_534131660440936662[155] = 0.0;
   out_534131660440936662[156] = 0.0;
   out_534131660440936662[157] = 0.0;
   out_534131660440936662[158] = 0.0;
   out_534131660440936662[159] = 0.0;
   out_534131660440936662[160] = 0.0;
   out_534131660440936662[161] = 0.0;
   out_534131660440936662[162] = 0.0;
   out_534131660440936662[163] = 0.0;
   out_534131660440936662[164] = 0.0;
   out_534131660440936662[165] = 0.0;
   out_534131660440936662[166] = 0.0;
   out_534131660440936662[167] = 0.0;
   out_534131660440936662[168] = 0.0;
   out_534131660440936662[169] = 0.0;
   out_534131660440936662[170] = 0.0;
   out_534131660440936662[171] = 1.0;
   out_534131660440936662[172] = 0.0;
   out_534131660440936662[173] = 0.0;
   out_534131660440936662[174] = 0.0;
   out_534131660440936662[175] = 0.0;
   out_534131660440936662[176] = 0.0;
   out_534131660440936662[177] = 0.0;
   out_534131660440936662[178] = 0.0;
   out_534131660440936662[179] = 0.0;
   out_534131660440936662[180] = 0.0;
   out_534131660440936662[181] = 0.0;
   out_534131660440936662[182] = 0.0;
   out_534131660440936662[183] = 0.0;
   out_534131660440936662[184] = 0.0;
   out_534131660440936662[185] = 0.0;
   out_534131660440936662[186] = 0.0;
   out_534131660440936662[187] = 0.0;
   out_534131660440936662[188] = 0.0;
   out_534131660440936662[189] = 0.0;
   out_534131660440936662[190] = 1.0;
   out_534131660440936662[191] = 0.0;
   out_534131660440936662[192] = 0.0;
   out_534131660440936662[193] = 0.0;
   out_534131660440936662[194] = 0.0;
   out_534131660440936662[195] = 0.0;
   out_534131660440936662[196] = 0.0;
   out_534131660440936662[197] = 0.0;
   out_534131660440936662[198] = 0.0;
   out_534131660440936662[199] = 0.0;
   out_534131660440936662[200] = 0.0;
   out_534131660440936662[201] = 0.0;
   out_534131660440936662[202] = 0.0;
   out_534131660440936662[203] = 0.0;
   out_534131660440936662[204] = 0.0;
   out_534131660440936662[205] = 0.0;
   out_534131660440936662[206] = 0.0;
   out_534131660440936662[207] = 0.0;
   out_534131660440936662[208] = 0.0;
   out_534131660440936662[209] = 1.0;
   out_534131660440936662[210] = 0.0;
   out_534131660440936662[211] = 0.0;
   out_534131660440936662[212] = 0.0;
   out_534131660440936662[213] = 0.0;
   out_534131660440936662[214] = 0.0;
   out_534131660440936662[215] = 0.0;
   out_534131660440936662[216] = 0.0;
   out_534131660440936662[217] = 0.0;
   out_534131660440936662[218] = 0.0;
   out_534131660440936662[219] = 0.0;
   out_534131660440936662[220] = 0.0;
   out_534131660440936662[221] = 0.0;
   out_534131660440936662[222] = 0.0;
   out_534131660440936662[223] = 0.0;
   out_534131660440936662[224] = 0.0;
   out_534131660440936662[225] = 0.0;
   out_534131660440936662[226] = 0.0;
   out_534131660440936662[227] = 0.0;
   out_534131660440936662[228] = 1.0;
   out_534131660440936662[229] = 0.0;
   out_534131660440936662[230] = 0.0;
   out_534131660440936662[231] = 0.0;
   out_534131660440936662[232] = 0.0;
   out_534131660440936662[233] = 0.0;
   out_534131660440936662[234] = 0.0;
   out_534131660440936662[235] = 0.0;
   out_534131660440936662[236] = 0.0;
   out_534131660440936662[237] = 0.0;
   out_534131660440936662[238] = 0.0;
   out_534131660440936662[239] = 0.0;
   out_534131660440936662[240] = 0.0;
   out_534131660440936662[241] = 0.0;
   out_534131660440936662[242] = 0.0;
   out_534131660440936662[243] = 0.0;
   out_534131660440936662[244] = 0.0;
   out_534131660440936662[245] = 0.0;
   out_534131660440936662[246] = 0.0;
   out_534131660440936662[247] = 1.0;
   out_534131660440936662[248] = 0.0;
   out_534131660440936662[249] = 0.0;
   out_534131660440936662[250] = 0.0;
   out_534131660440936662[251] = 0.0;
   out_534131660440936662[252] = 0.0;
   out_534131660440936662[253] = 0.0;
   out_534131660440936662[254] = 0.0;
   out_534131660440936662[255] = 0.0;
   out_534131660440936662[256] = 0.0;
   out_534131660440936662[257] = 0.0;
   out_534131660440936662[258] = 0.0;
   out_534131660440936662[259] = 0.0;
   out_534131660440936662[260] = 0.0;
   out_534131660440936662[261] = 0.0;
   out_534131660440936662[262] = 0.0;
   out_534131660440936662[263] = 0.0;
   out_534131660440936662[264] = 0.0;
   out_534131660440936662[265] = 0.0;
   out_534131660440936662[266] = 1.0;
   out_534131660440936662[267] = 0.0;
   out_534131660440936662[268] = 0.0;
   out_534131660440936662[269] = 0.0;
   out_534131660440936662[270] = 0.0;
   out_534131660440936662[271] = 0.0;
   out_534131660440936662[272] = 0.0;
   out_534131660440936662[273] = 0.0;
   out_534131660440936662[274] = 0.0;
   out_534131660440936662[275] = 0.0;
   out_534131660440936662[276] = 0.0;
   out_534131660440936662[277] = 0.0;
   out_534131660440936662[278] = 0.0;
   out_534131660440936662[279] = 0.0;
   out_534131660440936662[280] = 0.0;
   out_534131660440936662[281] = 0.0;
   out_534131660440936662[282] = 0.0;
   out_534131660440936662[283] = 0.0;
   out_534131660440936662[284] = 0.0;
   out_534131660440936662[285] = 1.0;
   out_534131660440936662[286] = 0.0;
   out_534131660440936662[287] = 0.0;
   out_534131660440936662[288] = 0.0;
   out_534131660440936662[289] = 0.0;
   out_534131660440936662[290] = 0.0;
   out_534131660440936662[291] = 0.0;
   out_534131660440936662[292] = 0.0;
   out_534131660440936662[293] = 0.0;
   out_534131660440936662[294] = 0.0;
   out_534131660440936662[295] = 0.0;
   out_534131660440936662[296] = 0.0;
   out_534131660440936662[297] = 0.0;
   out_534131660440936662[298] = 0.0;
   out_534131660440936662[299] = 0.0;
   out_534131660440936662[300] = 0.0;
   out_534131660440936662[301] = 0.0;
   out_534131660440936662[302] = 0.0;
   out_534131660440936662[303] = 0.0;
   out_534131660440936662[304] = 1.0;
   out_534131660440936662[305] = 0.0;
   out_534131660440936662[306] = 0.0;
   out_534131660440936662[307] = 0.0;
   out_534131660440936662[308] = 0.0;
   out_534131660440936662[309] = 0.0;
   out_534131660440936662[310] = 0.0;
   out_534131660440936662[311] = 0.0;
   out_534131660440936662[312] = 0.0;
   out_534131660440936662[313] = 0.0;
   out_534131660440936662[314] = 0.0;
   out_534131660440936662[315] = 0.0;
   out_534131660440936662[316] = 0.0;
   out_534131660440936662[317] = 0.0;
   out_534131660440936662[318] = 0.0;
   out_534131660440936662[319] = 0.0;
   out_534131660440936662[320] = 0.0;
   out_534131660440936662[321] = 0.0;
   out_534131660440936662[322] = 0.0;
   out_534131660440936662[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2390572541081456385) {
   out_2390572541081456385[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2390572541081456385[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2390572541081456385[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2390572541081456385[3] = dt*state[12] + state[3];
   out_2390572541081456385[4] = dt*state[13] + state[4];
   out_2390572541081456385[5] = dt*state[14] + state[5];
   out_2390572541081456385[6] = state[6];
   out_2390572541081456385[7] = state[7];
   out_2390572541081456385[8] = state[8];
   out_2390572541081456385[9] = state[9];
   out_2390572541081456385[10] = state[10];
   out_2390572541081456385[11] = state[11];
   out_2390572541081456385[12] = state[12];
   out_2390572541081456385[13] = state[13];
   out_2390572541081456385[14] = state[14];
   out_2390572541081456385[15] = state[15];
   out_2390572541081456385[16] = state[16];
   out_2390572541081456385[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1513223696750910511) {
   out_1513223696750910511[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1513223696750910511[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1513223696750910511[2] = 0;
   out_1513223696750910511[3] = 0;
   out_1513223696750910511[4] = 0;
   out_1513223696750910511[5] = 0;
   out_1513223696750910511[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1513223696750910511[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1513223696750910511[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1513223696750910511[9] = 0;
   out_1513223696750910511[10] = 0;
   out_1513223696750910511[11] = 0;
   out_1513223696750910511[12] = 0;
   out_1513223696750910511[13] = 0;
   out_1513223696750910511[14] = 0;
   out_1513223696750910511[15] = 0;
   out_1513223696750910511[16] = 0;
   out_1513223696750910511[17] = 0;
   out_1513223696750910511[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1513223696750910511[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1513223696750910511[20] = 0;
   out_1513223696750910511[21] = 0;
   out_1513223696750910511[22] = 0;
   out_1513223696750910511[23] = 0;
   out_1513223696750910511[24] = 0;
   out_1513223696750910511[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1513223696750910511[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1513223696750910511[27] = 0;
   out_1513223696750910511[28] = 0;
   out_1513223696750910511[29] = 0;
   out_1513223696750910511[30] = 0;
   out_1513223696750910511[31] = 0;
   out_1513223696750910511[32] = 0;
   out_1513223696750910511[33] = 0;
   out_1513223696750910511[34] = 0;
   out_1513223696750910511[35] = 0;
   out_1513223696750910511[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1513223696750910511[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1513223696750910511[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1513223696750910511[39] = 0;
   out_1513223696750910511[40] = 0;
   out_1513223696750910511[41] = 0;
   out_1513223696750910511[42] = 0;
   out_1513223696750910511[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1513223696750910511[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1513223696750910511[45] = 0;
   out_1513223696750910511[46] = 0;
   out_1513223696750910511[47] = 0;
   out_1513223696750910511[48] = 0;
   out_1513223696750910511[49] = 0;
   out_1513223696750910511[50] = 0;
   out_1513223696750910511[51] = 0;
   out_1513223696750910511[52] = 0;
   out_1513223696750910511[53] = 0;
   out_1513223696750910511[54] = 0;
   out_1513223696750910511[55] = 0;
   out_1513223696750910511[56] = 0;
   out_1513223696750910511[57] = 1;
   out_1513223696750910511[58] = 0;
   out_1513223696750910511[59] = 0;
   out_1513223696750910511[60] = 0;
   out_1513223696750910511[61] = 0;
   out_1513223696750910511[62] = 0;
   out_1513223696750910511[63] = 0;
   out_1513223696750910511[64] = 0;
   out_1513223696750910511[65] = 0;
   out_1513223696750910511[66] = dt;
   out_1513223696750910511[67] = 0;
   out_1513223696750910511[68] = 0;
   out_1513223696750910511[69] = 0;
   out_1513223696750910511[70] = 0;
   out_1513223696750910511[71] = 0;
   out_1513223696750910511[72] = 0;
   out_1513223696750910511[73] = 0;
   out_1513223696750910511[74] = 0;
   out_1513223696750910511[75] = 0;
   out_1513223696750910511[76] = 1;
   out_1513223696750910511[77] = 0;
   out_1513223696750910511[78] = 0;
   out_1513223696750910511[79] = 0;
   out_1513223696750910511[80] = 0;
   out_1513223696750910511[81] = 0;
   out_1513223696750910511[82] = 0;
   out_1513223696750910511[83] = 0;
   out_1513223696750910511[84] = 0;
   out_1513223696750910511[85] = dt;
   out_1513223696750910511[86] = 0;
   out_1513223696750910511[87] = 0;
   out_1513223696750910511[88] = 0;
   out_1513223696750910511[89] = 0;
   out_1513223696750910511[90] = 0;
   out_1513223696750910511[91] = 0;
   out_1513223696750910511[92] = 0;
   out_1513223696750910511[93] = 0;
   out_1513223696750910511[94] = 0;
   out_1513223696750910511[95] = 1;
   out_1513223696750910511[96] = 0;
   out_1513223696750910511[97] = 0;
   out_1513223696750910511[98] = 0;
   out_1513223696750910511[99] = 0;
   out_1513223696750910511[100] = 0;
   out_1513223696750910511[101] = 0;
   out_1513223696750910511[102] = 0;
   out_1513223696750910511[103] = 0;
   out_1513223696750910511[104] = dt;
   out_1513223696750910511[105] = 0;
   out_1513223696750910511[106] = 0;
   out_1513223696750910511[107] = 0;
   out_1513223696750910511[108] = 0;
   out_1513223696750910511[109] = 0;
   out_1513223696750910511[110] = 0;
   out_1513223696750910511[111] = 0;
   out_1513223696750910511[112] = 0;
   out_1513223696750910511[113] = 0;
   out_1513223696750910511[114] = 1;
   out_1513223696750910511[115] = 0;
   out_1513223696750910511[116] = 0;
   out_1513223696750910511[117] = 0;
   out_1513223696750910511[118] = 0;
   out_1513223696750910511[119] = 0;
   out_1513223696750910511[120] = 0;
   out_1513223696750910511[121] = 0;
   out_1513223696750910511[122] = 0;
   out_1513223696750910511[123] = 0;
   out_1513223696750910511[124] = 0;
   out_1513223696750910511[125] = 0;
   out_1513223696750910511[126] = 0;
   out_1513223696750910511[127] = 0;
   out_1513223696750910511[128] = 0;
   out_1513223696750910511[129] = 0;
   out_1513223696750910511[130] = 0;
   out_1513223696750910511[131] = 0;
   out_1513223696750910511[132] = 0;
   out_1513223696750910511[133] = 1;
   out_1513223696750910511[134] = 0;
   out_1513223696750910511[135] = 0;
   out_1513223696750910511[136] = 0;
   out_1513223696750910511[137] = 0;
   out_1513223696750910511[138] = 0;
   out_1513223696750910511[139] = 0;
   out_1513223696750910511[140] = 0;
   out_1513223696750910511[141] = 0;
   out_1513223696750910511[142] = 0;
   out_1513223696750910511[143] = 0;
   out_1513223696750910511[144] = 0;
   out_1513223696750910511[145] = 0;
   out_1513223696750910511[146] = 0;
   out_1513223696750910511[147] = 0;
   out_1513223696750910511[148] = 0;
   out_1513223696750910511[149] = 0;
   out_1513223696750910511[150] = 0;
   out_1513223696750910511[151] = 0;
   out_1513223696750910511[152] = 1;
   out_1513223696750910511[153] = 0;
   out_1513223696750910511[154] = 0;
   out_1513223696750910511[155] = 0;
   out_1513223696750910511[156] = 0;
   out_1513223696750910511[157] = 0;
   out_1513223696750910511[158] = 0;
   out_1513223696750910511[159] = 0;
   out_1513223696750910511[160] = 0;
   out_1513223696750910511[161] = 0;
   out_1513223696750910511[162] = 0;
   out_1513223696750910511[163] = 0;
   out_1513223696750910511[164] = 0;
   out_1513223696750910511[165] = 0;
   out_1513223696750910511[166] = 0;
   out_1513223696750910511[167] = 0;
   out_1513223696750910511[168] = 0;
   out_1513223696750910511[169] = 0;
   out_1513223696750910511[170] = 0;
   out_1513223696750910511[171] = 1;
   out_1513223696750910511[172] = 0;
   out_1513223696750910511[173] = 0;
   out_1513223696750910511[174] = 0;
   out_1513223696750910511[175] = 0;
   out_1513223696750910511[176] = 0;
   out_1513223696750910511[177] = 0;
   out_1513223696750910511[178] = 0;
   out_1513223696750910511[179] = 0;
   out_1513223696750910511[180] = 0;
   out_1513223696750910511[181] = 0;
   out_1513223696750910511[182] = 0;
   out_1513223696750910511[183] = 0;
   out_1513223696750910511[184] = 0;
   out_1513223696750910511[185] = 0;
   out_1513223696750910511[186] = 0;
   out_1513223696750910511[187] = 0;
   out_1513223696750910511[188] = 0;
   out_1513223696750910511[189] = 0;
   out_1513223696750910511[190] = 1;
   out_1513223696750910511[191] = 0;
   out_1513223696750910511[192] = 0;
   out_1513223696750910511[193] = 0;
   out_1513223696750910511[194] = 0;
   out_1513223696750910511[195] = 0;
   out_1513223696750910511[196] = 0;
   out_1513223696750910511[197] = 0;
   out_1513223696750910511[198] = 0;
   out_1513223696750910511[199] = 0;
   out_1513223696750910511[200] = 0;
   out_1513223696750910511[201] = 0;
   out_1513223696750910511[202] = 0;
   out_1513223696750910511[203] = 0;
   out_1513223696750910511[204] = 0;
   out_1513223696750910511[205] = 0;
   out_1513223696750910511[206] = 0;
   out_1513223696750910511[207] = 0;
   out_1513223696750910511[208] = 0;
   out_1513223696750910511[209] = 1;
   out_1513223696750910511[210] = 0;
   out_1513223696750910511[211] = 0;
   out_1513223696750910511[212] = 0;
   out_1513223696750910511[213] = 0;
   out_1513223696750910511[214] = 0;
   out_1513223696750910511[215] = 0;
   out_1513223696750910511[216] = 0;
   out_1513223696750910511[217] = 0;
   out_1513223696750910511[218] = 0;
   out_1513223696750910511[219] = 0;
   out_1513223696750910511[220] = 0;
   out_1513223696750910511[221] = 0;
   out_1513223696750910511[222] = 0;
   out_1513223696750910511[223] = 0;
   out_1513223696750910511[224] = 0;
   out_1513223696750910511[225] = 0;
   out_1513223696750910511[226] = 0;
   out_1513223696750910511[227] = 0;
   out_1513223696750910511[228] = 1;
   out_1513223696750910511[229] = 0;
   out_1513223696750910511[230] = 0;
   out_1513223696750910511[231] = 0;
   out_1513223696750910511[232] = 0;
   out_1513223696750910511[233] = 0;
   out_1513223696750910511[234] = 0;
   out_1513223696750910511[235] = 0;
   out_1513223696750910511[236] = 0;
   out_1513223696750910511[237] = 0;
   out_1513223696750910511[238] = 0;
   out_1513223696750910511[239] = 0;
   out_1513223696750910511[240] = 0;
   out_1513223696750910511[241] = 0;
   out_1513223696750910511[242] = 0;
   out_1513223696750910511[243] = 0;
   out_1513223696750910511[244] = 0;
   out_1513223696750910511[245] = 0;
   out_1513223696750910511[246] = 0;
   out_1513223696750910511[247] = 1;
   out_1513223696750910511[248] = 0;
   out_1513223696750910511[249] = 0;
   out_1513223696750910511[250] = 0;
   out_1513223696750910511[251] = 0;
   out_1513223696750910511[252] = 0;
   out_1513223696750910511[253] = 0;
   out_1513223696750910511[254] = 0;
   out_1513223696750910511[255] = 0;
   out_1513223696750910511[256] = 0;
   out_1513223696750910511[257] = 0;
   out_1513223696750910511[258] = 0;
   out_1513223696750910511[259] = 0;
   out_1513223696750910511[260] = 0;
   out_1513223696750910511[261] = 0;
   out_1513223696750910511[262] = 0;
   out_1513223696750910511[263] = 0;
   out_1513223696750910511[264] = 0;
   out_1513223696750910511[265] = 0;
   out_1513223696750910511[266] = 1;
   out_1513223696750910511[267] = 0;
   out_1513223696750910511[268] = 0;
   out_1513223696750910511[269] = 0;
   out_1513223696750910511[270] = 0;
   out_1513223696750910511[271] = 0;
   out_1513223696750910511[272] = 0;
   out_1513223696750910511[273] = 0;
   out_1513223696750910511[274] = 0;
   out_1513223696750910511[275] = 0;
   out_1513223696750910511[276] = 0;
   out_1513223696750910511[277] = 0;
   out_1513223696750910511[278] = 0;
   out_1513223696750910511[279] = 0;
   out_1513223696750910511[280] = 0;
   out_1513223696750910511[281] = 0;
   out_1513223696750910511[282] = 0;
   out_1513223696750910511[283] = 0;
   out_1513223696750910511[284] = 0;
   out_1513223696750910511[285] = 1;
   out_1513223696750910511[286] = 0;
   out_1513223696750910511[287] = 0;
   out_1513223696750910511[288] = 0;
   out_1513223696750910511[289] = 0;
   out_1513223696750910511[290] = 0;
   out_1513223696750910511[291] = 0;
   out_1513223696750910511[292] = 0;
   out_1513223696750910511[293] = 0;
   out_1513223696750910511[294] = 0;
   out_1513223696750910511[295] = 0;
   out_1513223696750910511[296] = 0;
   out_1513223696750910511[297] = 0;
   out_1513223696750910511[298] = 0;
   out_1513223696750910511[299] = 0;
   out_1513223696750910511[300] = 0;
   out_1513223696750910511[301] = 0;
   out_1513223696750910511[302] = 0;
   out_1513223696750910511[303] = 0;
   out_1513223696750910511[304] = 1;
   out_1513223696750910511[305] = 0;
   out_1513223696750910511[306] = 0;
   out_1513223696750910511[307] = 0;
   out_1513223696750910511[308] = 0;
   out_1513223696750910511[309] = 0;
   out_1513223696750910511[310] = 0;
   out_1513223696750910511[311] = 0;
   out_1513223696750910511[312] = 0;
   out_1513223696750910511[313] = 0;
   out_1513223696750910511[314] = 0;
   out_1513223696750910511[315] = 0;
   out_1513223696750910511[316] = 0;
   out_1513223696750910511[317] = 0;
   out_1513223696750910511[318] = 0;
   out_1513223696750910511[319] = 0;
   out_1513223696750910511[320] = 0;
   out_1513223696750910511[321] = 0;
   out_1513223696750910511[322] = 0;
   out_1513223696750910511[323] = 1;
}
void h_4(double *state, double *unused, double *out_7543652368314576620) {
   out_7543652368314576620[0] = state[6] + state[9];
   out_7543652368314576620[1] = state[7] + state[10];
   out_7543652368314576620[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4618386724598144073) {
   out_4618386724598144073[0] = 0;
   out_4618386724598144073[1] = 0;
   out_4618386724598144073[2] = 0;
   out_4618386724598144073[3] = 0;
   out_4618386724598144073[4] = 0;
   out_4618386724598144073[5] = 0;
   out_4618386724598144073[6] = 1;
   out_4618386724598144073[7] = 0;
   out_4618386724598144073[8] = 0;
   out_4618386724598144073[9] = 1;
   out_4618386724598144073[10] = 0;
   out_4618386724598144073[11] = 0;
   out_4618386724598144073[12] = 0;
   out_4618386724598144073[13] = 0;
   out_4618386724598144073[14] = 0;
   out_4618386724598144073[15] = 0;
   out_4618386724598144073[16] = 0;
   out_4618386724598144073[17] = 0;
   out_4618386724598144073[18] = 0;
   out_4618386724598144073[19] = 0;
   out_4618386724598144073[20] = 0;
   out_4618386724598144073[21] = 0;
   out_4618386724598144073[22] = 0;
   out_4618386724598144073[23] = 0;
   out_4618386724598144073[24] = 0;
   out_4618386724598144073[25] = 1;
   out_4618386724598144073[26] = 0;
   out_4618386724598144073[27] = 0;
   out_4618386724598144073[28] = 1;
   out_4618386724598144073[29] = 0;
   out_4618386724598144073[30] = 0;
   out_4618386724598144073[31] = 0;
   out_4618386724598144073[32] = 0;
   out_4618386724598144073[33] = 0;
   out_4618386724598144073[34] = 0;
   out_4618386724598144073[35] = 0;
   out_4618386724598144073[36] = 0;
   out_4618386724598144073[37] = 0;
   out_4618386724598144073[38] = 0;
   out_4618386724598144073[39] = 0;
   out_4618386724598144073[40] = 0;
   out_4618386724598144073[41] = 0;
   out_4618386724598144073[42] = 0;
   out_4618386724598144073[43] = 0;
   out_4618386724598144073[44] = 1;
   out_4618386724598144073[45] = 0;
   out_4618386724598144073[46] = 0;
   out_4618386724598144073[47] = 1;
   out_4618386724598144073[48] = 0;
   out_4618386724598144073[49] = 0;
   out_4618386724598144073[50] = 0;
   out_4618386724598144073[51] = 0;
   out_4618386724598144073[52] = 0;
   out_4618386724598144073[53] = 0;
}
void h_10(double *state, double *unused, double *out_1260309873169513594) {
   out_1260309873169513594[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1260309873169513594[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1260309873169513594[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3724360775848728158) {
   out_3724360775848728158[0] = 0;
   out_3724360775848728158[1] = 9.8100000000000005*cos(state[1]);
   out_3724360775848728158[2] = 0;
   out_3724360775848728158[3] = 0;
   out_3724360775848728158[4] = -state[8];
   out_3724360775848728158[5] = state[7];
   out_3724360775848728158[6] = 0;
   out_3724360775848728158[7] = state[5];
   out_3724360775848728158[8] = -state[4];
   out_3724360775848728158[9] = 0;
   out_3724360775848728158[10] = 0;
   out_3724360775848728158[11] = 0;
   out_3724360775848728158[12] = 1;
   out_3724360775848728158[13] = 0;
   out_3724360775848728158[14] = 0;
   out_3724360775848728158[15] = 1;
   out_3724360775848728158[16] = 0;
   out_3724360775848728158[17] = 0;
   out_3724360775848728158[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3724360775848728158[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3724360775848728158[20] = 0;
   out_3724360775848728158[21] = state[8];
   out_3724360775848728158[22] = 0;
   out_3724360775848728158[23] = -state[6];
   out_3724360775848728158[24] = -state[5];
   out_3724360775848728158[25] = 0;
   out_3724360775848728158[26] = state[3];
   out_3724360775848728158[27] = 0;
   out_3724360775848728158[28] = 0;
   out_3724360775848728158[29] = 0;
   out_3724360775848728158[30] = 0;
   out_3724360775848728158[31] = 1;
   out_3724360775848728158[32] = 0;
   out_3724360775848728158[33] = 0;
   out_3724360775848728158[34] = 1;
   out_3724360775848728158[35] = 0;
   out_3724360775848728158[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3724360775848728158[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3724360775848728158[38] = 0;
   out_3724360775848728158[39] = -state[7];
   out_3724360775848728158[40] = state[6];
   out_3724360775848728158[41] = 0;
   out_3724360775848728158[42] = state[4];
   out_3724360775848728158[43] = -state[3];
   out_3724360775848728158[44] = 0;
   out_3724360775848728158[45] = 0;
   out_3724360775848728158[46] = 0;
   out_3724360775848728158[47] = 0;
   out_3724360775848728158[48] = 0;
   out_3724360775848728158[49] = 0;
   out_3724360775848728158[50] = 1;
   out_3724360775848728158[51] = 0;
   out_3724360775848728158[52] = 0;
   out_3724360775848728158[53] = 1;
}
void h_13(double *state, double *unused, double *out_7136718217250129115) {
   out_7136718217250129115[0] = state[3];
   out_7136718217250129115[1] = state[4];
   out_7136718217250129115[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7830660549930476874) {
   out_7830660549930476874[0] = 0;
   out_7830660549930476874[1] = 0;
   out_7830660549930476874[2] = 0;
   out_7830660549930476874[3] = 1;
   out_7830660549930476874[4] = 0;
   out_7830660549930476874[5] = 0;
   out_7830660549930476874[6] = 0;
   out_7830660549930476874[7] = 0;
   out_7830660549930476874[8] = 0;
   out_7830660549930476874[9] = 0;
   out_7830660549930476874[10] = 0;
   out_7830660549930476874[11] = 0;
   out_7830660549930476874[12] = 0;
   out_7830660549930476874[13] = 0;
   out_7830660549930476874[14] = 0;
   out_7830660549930476874[15] = 0;
   out_7830660549930476874[16] = 0;
   out_7830660549930476874[17] = 0;
   out_7830660549930476874[18] = 0;
   out_7830660549930476874[19] = 0;
   out_7830660549930476874[20] = 0;
   out_7830660549930476874[21] = 0;
   out_7830660549930476874[22] = 1;
   out_7830660549930476874[23] = 0;
   out_7830660549930476874[24] = 0;
   out_7830660549930476874[25] = 0;
   out_7830660549930476874[26] = 0;
   out_7830660549930476874[27] = 0;
   out_7830660549930476874[28] = 0;
   out_7830660549930476874[29] = 0;
   out_7830660549930476874[30] = 0;
   out_7830660549930476874[31] = 0;
   out_7830660549930476874[32] = 0;
   out_7830660549930476874[33] = 0;
   out_7830660549930476874[34] = 0;
   out_7830660549930476874[35] = 0;
   out_7830660549930476874[36] = 0;
   out_7830660549930476874[37] = 0;
   out_7830660549930476874[38] = 0;
   out_7830660549930476874[39] = 0;
   out_7830660549930476874[40] = 0;
   out_7830660549930476874[41] = 1;
   out_7830660549930476874[42] = 0;
   out_7830660549930476874[43] = 0;
   out_7830660549930476874[44] = 0;
   out_7830660549930476874[45] = 0;
   out_7830660549930476874[46] = 0;
   out_7830660549930476874[47] = 0;
   out_7830660549930476874[48] = 0;
   out_7830660549930476874[49] = 0;
   out_7830660549930476874[50] = 0;
   out_7830660549930476874[51] = 0;
   out_7830660549930476874[52] = 0;
   out_7830660549930476874[53] = 0;
}
void h_14(double *state, double *unused, double *out_5010661569828504853) {
   out_5010661569828504853[0] = state[6];
   out_5010661569828504853[1] = state[7];
   out_5010661569828504853[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8581627580937628602) {
   out_8581627580937628602[0] = 0;
   out_8581627580937628602[1] = 0;
   out_8581627580937628602[2] = 0;
   out_8581627580937628602[3] = 0;
   out_8581627580937628602[4] = 0;
   out_8581627580937628602[5] = 0;
   out_8581627580937628602[6] = 1;
   out_8581627580937628602[7] = 0;
   out_8581627580937628602[8] = 0;
   out_8581627580937628602[9] = 0;
   out_8581627580937628602[10] = 0;
   out_8581627580937628602[11] = 0;
   out_8581627580937628602[12] = 0;
   out_8581627580937628602[13] = 0;
   out_8581627580937628602[14] = 0;
   out_8581627580937628602[15] = 0;
   out_8581627580937628602[16] = 0;
   out_8581627580937628602[17] = 0;
   out_8581627580937628602[18] = 0;
   out_8581627580937628602[19] = 0;
   out_8581627580937628602[20] = 0;
   out_8581627580937628602[21] = 0;
   out_8581627580937628602[22] = 0;
   out_8581627580937628602[23] = 0;
   out_8581627580937628602[24] = 0;
   out_8581627580937628602[25] = 1;
   out_8581627580937628602[26] = 0;
   out_8581627580937628602[27] = 0;
   out_8581627580937628602[28] = 0;
   out_8581627580937628602[29] = 0;
   out_8581627580937628602[30] = 0;
   out_8581627580937628602[31] = 0;
   out_8581627580937628602[32] = 0;
   out_8581627580937628602[33] = 0;
   out_8581627580937628602[34] = 0;
   out_8581627580937628602[35] = 0;
   out_8581627580937628602[36] = 0;
   out_8581627580937628602[37] = 0;
   out_8581627580937628602[38] = 0;
   out_8581627580937628602[39] = 0;
   out_8581627580937628602[40] = 0;
   out_8581627580937628602[41] = 0;
   out_8581627580937628602[42] = 0;
   out_8581627580937628602[43] = 0;
   out_8581627580937628602[44] = 1;
   out_8581627580937628602[45] = 0;
   out_8581627580937628602[46] = 0;
   out_8581627580937628602[47] = 0;
   out_8581627580937628602[48] = 0;
   out_8581627580937628602[49] = 0;
   out_8581627580937628602[50] = 0;
   out_8581627580937628602[51] = 0;
   out_8581627580937628602[52] = 0;
   out_8581627580937628602[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7636423458425794019) {
  err_fun(nom_x, delta_x, out_7636423458425794019);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4233815579108349573) {
  inv_err_fun(nom_x, true_x, out_4233815579108349573);
}
void pose_H_mod_fun(double *state, double *out_534131660440936662) {
  H_mod_fun(state, out_534131660440936662);
}
void pose_f_fun(double *state, double dt, double *out_2390572541081456385) {
  f_fun(state,  dt, out_2390572541081456385);
}
void pose_F_fun(double *state, double dt, double *out_1513223696750910511) {
  F_fun(state,  dt, out_1513223696750910511);
}
void pose_h_4(double *state, double *unused, double *out_7543652368314576620) {
  h_4(state, unused, out_7543652368314576620);
}
void pose_H_4(double *state, double *unused, double *out_4618386724598144073) {
  H_4(state, unused, out_4618386724598144073);
}
void pose_h_10(double *state, double *unused, double *out_1260309873169513594) {
  h_10(state, unused, out_1260309873169513594);
}
void pose_H_10(double *state, double *unused, double *out_3724360775848728158) {
  H_10(state, unused, out_3724360775848728158);
}
void pose_h_13(double *state, double *unused, double *out_7136718217250129115) {
  h_13(state, unused, out_7136718217250129115);
}
void pose_H_13(double *state, double *unused, double *out_7830660549930476874) {
  H_13(state, unused, out_7830660549930476874);
}
void pose_h_14(double *state, double *unused, double *out_5010661569828504853) {
  h_14(state, unused, out_5010661569828504853);
}
void pose_H_14(double *state, double *unused, double *out_8581627580937628602) {
  H_14(state, unused, out_8581627580937628602);
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
