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
void err_fun(double *nom_x, double *delta_x, double *out_6531280423659383110) {
   out_6531280423659383110[0] = delta_x[0] + nom_x[0];
   out_6531280423659383110[1] = delta_x[1] + nom_x[1];
   out_6531280423659383110[2] = delta_x[2] + nom_x[2];
   out_6531280423659383110[3] = delta_x[3] + nom_x[3];
   out_6531280423659383110[4] = delta_x[4] + nom_x[4];
   out_6531280423659383110[5] = delta_x[5] + nom_x[5];
   out_6531280423659383110[6] = delta_x[6] + nom_x[6];
   out_6531280423659383110[7] = delta_x[7] + nom_x[7];
   out_6531280423659383110[8] = delta_x[8] + nom_x[8];
   out_6531280423659383110[9] = delta_x[9] + nom_x[9];
   out_6531280423659383110[10] = delta_x[10] + nom_x[10];
   out_6531280423659383110[11] = delta_x[11] + nom_x[11];
   out_6531280423659383110[12] = delta_x[12] + nom_x[12];
   out_6531280423659383110[13] = delta_x[13] + nom_x[13];
   out_6531280423659383110[14] = delta_x[14] + nom_x[14];
   out_6531280423659383110[15] = delta_x[15] + nom_x[15];
   out_6531280423659383110[16] = delta_x[16] + nom_x[16];
   out_6531280423659383110[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2847042605170284069) {
   out_2847042605170284069[0] = -nom_x[0] + true_x[0];
   out_2847042605170284069[1] = -nom_x[1] + true_x[1];
   out_2847042605170284069[2] = -nom_x[2] + true_x[2];
   out_2847042605170284069[3] = -nom_x[3] + true_x[3];
   out_2847042605170284069[4] = -nom_x[4] + true_x[4];
   out_2847042605170284069[5] = -nom_x[5] + true_x[5];
   out_2847042605170284069[6] = -nom_x[6] + true_x[6];
   out_2847042605170284069[7] = -nom_x[7] + true_x[7];
   out_2847042605170284069[8] = -nom_x[8] + true_x[8];
   out_2847042605170284069[9] = -nom_x[9] + true_x[9];
   out_2847042605170284069[10] = -nom_x[10] + true_x[10];
   out_2847042605170284069[11] = -nom_x[11] + true_x[11];
   out_2847042605170284069[12] = -nom_x[12] + true_x[12];
   out_2847042605170284069[13] = -nom_x[13] + true_x[13];
   out_2847042605170284069[14] = -nom_x[14] + true_x[14];
   out_2847042605170284069[15] = -nom_x[15] + true_x[15];
   out_2847042605170284069[16] = -nom_x[16] + true_x[16];
   out_2847042605170284069[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1201664963462517165) {
   out_1201664963462517165[0] = 1.0;
   out_1201664963462517165[1] = 0.0;
   out_1201664963462517165[2] = 0.0;
   out_1201664963462517165[3] = 0.0;
   out_1201664963462517165[4] = 0.0;
   out_1201664963462517165[5] = 0.0;
   out_1201664963462517165[6] = 0.0;
   out_1201664963462517165[7] = 0.0;
   out_1201664963462517165[8] = 0.0;
   out_1201664963462517165[9] = 0.0;
   out_1201664963462517165[10] = 0.0;
   out_1201664963462517165[11] = 0.0;
   out_1201664963462517165[12] = 0.0;
   out_1201664963462517165[13] = 0.0;
   out_1201664963462517165[14] = 0.0;
   out_1201664963462517165[15] = 0.0;
   out_1201664963462517165[16] = 0.0;
   out_1201664963462517165[17] = 0.0;
   out_1201664963462517165[18] = 0.0;
   out_1201664963462517165[19] = 1.0;
   out_1201664963462517165[20] = 0.0;
   out_1201664963462517165[21] = 0.0;
   out_1201664963462517165[22] = 0.0;
   out_1201664963462517165[23] = 0.0;
   out_1201664963462517165[24] = 0.0;
   out_1201664963462517165[25] = 0.0;
   out_1201664963462517165[26] = 0.0;
   out_1201664963462517165[27] = 0.0;
   out_1201664963462517165[28] = 0.0;
   out_1201664963462517165[29] = 0.0;
   out_1201664963462517165[30] = 0.0;
   out_1201664963462517165[31] = 0.0;
   out_1201664963462517165[32] = 0.0;
   out_1201664963462517165[33] = 0.0;
   out_1201664963462517165[34] = 0.0;
   out_1201664963462517165[35] = 0.0;
   out_1201664963462517165[36] = 0.0;
   out_1201664963462517165[37] = 0.0;
   out_1201664963462517165[38] = 1.0;
   out_1201664963462517165[39] = 0.0;
   out_1201664963462517165[40] = 0.0;
   out_1201664963462517165[41] = 0.0;
   out_1201664963462517165[42] = 0.0;
   out_1201664963462517165[43] = 0.0;
   out_1201664963462517165[44] = 0.0;
   out_1201664963462517165[45] = 0.0;
   out_1201664963462517165[46] = 0.0;
   out_1201664963462517165[47] = 0.0;
   out_1201664963462517165[48] = 0.0;
   out_1201664963462517165[49] = 0.0;
   out_1201664963462517165[50] = 0.0;
   out_1201664963462517165[51] = 0.0;
   out_1201664963462517165[52] = 0.0;
   out_1201664963462517165[53] = 0.0;
   out_1201664963462517165[54] = 0.0;
   out_1201664963462517165[55] = 0.0;
   out_1201664963462517165[56] = 0.0;
   out_1201664963462517165[57] = 1.0;
   out_1201664963462517165[58] = 0.0;
   out_1201664963462517165[59] = 0.0;
   out_1201664963462517165[60] = 0.0;
   out_1201664963462517165[61] = 0.0;
   out_1201664963462517165[62] = 0.0;
   out_1201664963462517165[63] = 0.0;
   out_1201664963462517165[64] = 0.0;
   out_1201664963462517165[65] = 0.0;
   out_1201664963462517165[66] = 0.0;
   out_1201664963462517165[67] = 0.0;
   out_1201664963462517165[68] = 0.0;
   out_1201664963462517165[69] = 0.0;
   out_1201664963462517165[70] = 0.0;
   out_1201664963462517165[71] = 0.0;
   out_1201664963462517165[72] = 0.0;
   out_1201664963462517165[73] = 0.0;
   out_1201664963462517165[74] = 0.0;
   out_1201664963462517165[75] = 0.0;
   out_1201664963462517165[76] = 1.0;
   out_1201664963462517165[77] = 0.0;
   out_1201664963462517165[78] = 0.0;
   out_1201664963462517165[79] = 0.0;
   out_1201664963462517165[80] = 0.0;
   out_1201664963462517165[81] = 0.0;
   out_1201664963462517165[82] = 0.0;
   out_1201664963462517165[83] = 0.0;
   out_1201664963462517165[84] = 0.0;
   out_1201664963462517165[85] = 0.0;
   out_1201664963462517165[86] = 0.0;
   out_1201664963462517165[87] = 0.0;
   out_1201664963462517165[88] = 0.0;
   out_1201664963462517165[89] = 0.0;
   out_1201664963462517165[90] = 0.0;
   out_1201664963462517165[91] = 0.0;
   out_1201664963462517165[92] = 0.0;
   out_1201664963462517165[93] = 0.0;
   out_1201664963462517165[94] = 0.0;
   out_1201664963462517165[95] = 1.0;
   out_1201664963462517165[96] = 0.0;
   out_1201664963462517165[97] = 0.0;
   out_1201664963462517165[98] = 0.0;
   out_1201664963462517165[99] = 0.0;
   out_1201664963462517165[100] = 0.0;
   out_1201664963462517165[101] = 0.0;
   out_1201664963462517165[102] = 0.0;
   out_1201664963462517165[103] = 0.0;
   out_1201664963462517165[104] = 0.0;
   out_1201664963462517165[105] = 0.0;
   out_1201664963462517165[106] = 0.0;
   out_1201664963462517165[107] = 0.0;
   out_1201664963462517165[108] = 0.0;
   out_1201664963462517165[109] = 0.0;
   out_1201664963462517165[110] = 0.0;
   out_1201664963462517165[111] = 0.0;
   out_1201664963462517165[112] = 0.0;
   out_1201664963462517165[113] = 0.0;
   out_1201664963462517165[114] = 1.0;
   out_1201664963462517165[115] = 0.0;
   out_1201664963462517165[116] = 0.0;
   out_1201664963462517165[117] = 0.0;
   out_1201664963462517165[118] = 0.0;
   out_1201664963462517165[119] = 0.0;
   out_1201664963462517165[120] = 0.0;
   out_1201664963462517165[121] = 0.0;
   out_1201664963462517165[122] = 0.0;
   out_1201664963462517165[123] = 0.0;
   out_1201664963462517165[124] = 0.0;
   out_1201664963462517165[125] = 0.0;
   out_1201664963462517165[126] = 0.0;
   out_1201664963462517165[127] = 0.0;
   out_1201664963462517165[128] = 0.0;
   out_1201664963462517165[129] = 0.0;
   out_1201664963462517165[130] = 0.0;
   out_1201664963462517165[131] = 0.0;
   out_1201664963462517165[132] = 0.0;
   out_1201664963462517165[133] = 1.0;
   out_1201664963462517165[134] = 0.0;
   out_1201664963462517165[135] = 0.0;
   out_1201664963462517165[136] = 0.0;
   out_1201664963462517165[137] = 0.0;
   out_1201664963462517165[138] = 0.0;
   out_1201664963462517165[139] = 0.0;
   out_1201664963462517165[140] = 0.0;
   out_1201664963462517165[141] = 0.0;
   out_1201664963462517165[142] = 0.0;
   out_1201664963462517165[143] = 0.0;
   out_1201664963462517165[144] = 0.0;
   out_1201664963462517165[145] = 0.0;
   out_1201664963462517165[146] = 0.0;
   out_1201664963462517165[147] = 0.0;
   out_1201664963462517165[148] = 0.0;
   out_1201664963462517165[149] = 0.0;
   out_1201664963462517165[150] = 0.0;
   out_1201664963462517165[151] = 0.0;
   out_1201664963462517165[152] = 1.0;
   out_1201664963462517165[153] = 0.0;
   out_1201664963462517165[154] = 0.0;
   out_1201664963462517165[155] = 0.0;
   out_1201664963462517165[156] = 0.0;
   out_1201664963462517165[157] = 0.0;
   out_1201664963462517165[158] = 0.0;
   out_1201664963462517165[159] = 0.0;
   out_1201664963462517165[160] = 0.0;
   out_1201664963462517165[161] = 0.0;
   out_1201664963462517165[162] = 0.0;
   out_1201664963462517165[163] = 0.0;
   out_1201664963462517165[164] = 0.0;
   out_1201664963462517165[165] = 0.0;
   out_1201664963462517165[166] = 0.0;
   out_1201664963462517165[167] = 0.0;
   out_1201664963462517165[168] = 0.0;
   out_1201664963462517165[169] = 0.0;
   out_1201664963462517165[170] = 0.0;
   out_1201664963462517165[171] = 1.0;
   out_1201664963462517165[172] = 0.0;
   out_1201664963462517165[173] = 0.0;
   out_1201664963462517165[174] = 0.0;
   out_1201664963462517165[175] = 0.0;
   out_1201664963462517165[176] = 0.0;
   out_1201664963462517165[177] = 0.0;
   out_1201664963462517165[178] = 0.0;
   out_1201664963462517165[179] = 0.0;
   out_1201664963462517165[180] = 0.0;
   out_1201664963462517165[181] = 0.0;
   out_1201664963462517165[182] = 0.0;
   out_1201664963462517165[183] = 0.0;
   out_1201664963462517165[184] = 0.0;
   out_1201664963462517165[185] = 0.0;
   out_1201664963462517165[186] = 0.0;
   out_1201664963462517165[187] = 0.0;
   out_1201664963462517165[188] = 0.0;
   out_1201664963462517165[189] = 0.0;
   out_1201664963462517165[190] = 1.0;
   out_1201664963462517165[191] = 0.0;
   out_1201664963462517165[192] = 0.0;
   out_1201664963462517165[193] = 0.0;
   out_1201664963462517165[194] = 0.0;
   out_1201664963462517165[195] = 0.0;
   out_1201664963462517165[196] = 0.0;
   out_1201664963462517165[197] = 0.0;
   out_1201664963462517165[198] = 0.0;
   out_1201664963462517165[199] = 0.0;
   out_1201664963462517165[200] = 0.0;
   out_1201664963462517165[201] = 0.0;
   out_1201664963462517165[202] = 0.0;
   out_1201664963462517165[203] = 0.0;
   out_1201664963462517165[204] = 0.0;
   out_1201664963462517165[205] = 0.0;
   out_1201664963462517165[206] = 0.0;
   out_1201664963462517165[207] = 0.0;
   out_1201664963462517165[208] = 0.0;
   out_1201664963462517165[209] = 1.0;
   out_1201664963462517165[210] = 0.0;
   out_1201664963462517165[211] = 0.0;
   out_1201664963462517165[212] = 0.0;
   out_1201664963462517165[213] = 0.0;
   out_1201664963462517165[214] = 0.0;
   out_1201664963462517165[215] = 0.0;
   out_1201664963462517165[216] = 0.0;
   out_1201664963462517165[217] = 0.0;
   out_1201664963462517165[218] = 0.0;
   out_1201664963462517165[219] = 0.0;
   out_1201664963462517165[220] = 0.0;
   out_1201664963462517165[221] = 0.0;
   out_1201664963462517165[222] = 0.0;
   out_1201664963462517165[223] = 0.0;
   out_1201664963462517165[224] = 0.0;
   out_1201664963462517165[225] = 0.0;
   out_1201664963462517165[226] = 0.0;
   out_1201664963462517165[227] = 0.0;
   out_1201664963462517165[228] = 1.0;
   out_1201664963462517165[229] = 0.0;
   out_1201664963462517165[230] = 0.0;
   out_1201664963462517165[231] = 0.0;
   out_1201664963462517165[232] = 0.0;
   out_1201664963462517165[233] = 0.0;
   out_1201664963462517165[234] = 0.0;
   out_1201664963462517165[235] = 0.0;
   out_1201664963462517165[236] = 0.0;
   out_1201664963462517165[237] = 0.0;
   out_1201664963462517165[238] = 0.0;
   out_1201664963462517165[239] = 0.0;
   out_1201664963462517165[240] = 0.0;
   out_1201664963462517165[241] = 0.0;
   out_1201664963462517165[242] = 0.0;
   out_1201664963462517165[243] = 0.0;
   out_1201664963462517165[244] = 0.0;
   out_1201664963462517165[245] = 0.0;
   out_1201664963462517165[246] = 0.0;
   out_1201664963462517165[247] = 1.0;
   out_1201664963462517165[248] = 0.0;
   out_1201664963462517165[249] = 0.0;
   out_1201664963462517165[250] = 0.0;
   out_1201664963462517165[251] = 0.0;
   out_1201664963462517165[252] = 0.0;
   out_1201664963462517165[253] = 0.0;
   out_1201664963462517165[254] = 0.0;
   out_1201664963462517165[255] = 0.0;
   out_1201664963462517165[256] = 0.0;
   out_1201664963462517165[257] = 0.0;
   out_1201664963462517165[258] = 0.0;
   out_1201664963462517165[259] = 0.0;
   out_1201664963462517165[260] = 0.0;
   out_1201664963462517165[261] = 0.0;
   out_1201664963462517165[262] = 0.0;
   out_1201664963462517165[263] = 0.0;
   out_1201664963462517165[264] = 0.0;
   out_1201664963462517165[265] = 0.0;
   out_1201664963462517165[266] = 1.0;
   out_1201664963462517165[267] = 0.0;
   out_1201664963462517165[268] = 0.0;
   out_1201664963462517165[269] = 0.0;
   out_1201664963462517165[270] = 0.0;
   out_1201664963462517165[271] = 0.0;
   out_1201664963462517165[272] = 0.0;
   out_1201664963462517165[273] = 0.0;
   out_1201664963462517165[274] = 0.0;
   out_1201664963462517165[275] = 0.0;
   out_1201664963462517165[276] = 0.0;
   out_1201664963462517165[277] = 0.0;
   out_1201664963462517165[278] = 0.0;
   out_1201664963462517165[279] = 0.0;
   out_1201664963462517165[280] = 0.0;
   out_1201664963462517165[281] = 0.0;
   out_1201664963462517165[282] = 0.0;
   out_1201664963462517165[283] = 0.0;
   out_1201664963462517165[284] = 0.0;
   out_1201664963462517165[285] = 1.0;
   out_1201664963462517165[286] = 0.0;
   out_1201664963462517165[287] = 0.0;
   out_1201664963462517165[288] = 0.0;
   out_1201664963462517165[289] = 0.0;
   out_1201664963462517165[290] = 0.0;
   out_1201664963462517165[291] = 0.0;
   out_1201664963462517165[292] = 0.0;
   out_1201664963462517165[293] = 0.0;
   out_1201664963462517165[294] = 0.0;
   out_1201664963462517165[295] = 0.0;
   out_1201664963462517165[296] = 0.0;
   out_1201664963462517165[297] = 0.0;
   out_1201664963462517165[298] = 0.0;
   out_1201664963462517165[299] = 0.0;
   out_1201664963462517165[300] = 0.0;
   out_1201664963462517165[301] = 0.0;
   out_1201664963462517165[302] = 0.0;
   out_1201664963462517165[303] = 0.0;
   out_1201664963462517165[304] = 1.0;
   out_1201664963462517165[305] = 0.0;
   out_1201664963462517165[306] = 0.0;
   out_1201664963462517165[307] = 0.0;
   out_1201664963462517165[308] = 0.0;
   out_1201664963462517165[309] = 0.0;
   out_1201664963462517165[310] = 0.0;
   out_1201664963462517165[311] = 0.0;
   out_1201664963462517165[312] = 0.0;
   out_1201664963462517165[313] = 0.0;
   out_1201664963462517165[314] = 0.0;
   out_1201664963462517165[315] = 0.0;
   out_1201664963462517165[316] = 0.0;
   out_1201664963462517165[317] = 0.0;
   out_1201664963462517165[318] = 0.0;
   out_1201664963462517165[319] = 0.0;
   out_1201664963462517165[320] = 0.0;
   out_1201664963462517165[321] = 0.0;
   out_1201664963462517165[322] = 0.0;
   out_1201664963462517165[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4925442091395050631) {
   out_4925442091395050631[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4925442091395050631[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4925442091395050631[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4925442091395050631[3] = dt*state[12] + state[3];
   out_4925442091395050631[4] = dt*state[13] + state[4];
   out_4925442091395050631[5] = dt*state[14] + state[5];
   out_4925442091395050631[6] = state[6];
   out_4925442091395050631[7] = state[7];
   out_4925442091395050631[8] = state[8];
   out_4925442091395050631[9] = state[9];
   out_4925442091395050631[10] = state[10];
   out_4925442091395050631[11] = state[11];
   out_4925442091395050631[12] = state[12];
   out_4925442091395050631[13] = state[13];
   out_4925442091395050631[14] = state[14];
   out_4925442091395050631[15] = state[15];
   out_4925442091395050631[16] = state[16];
   out_4925442091395050631[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3854196706556040023) {
   out_3854196706556040023[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3854196706556040023[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3854196706556040023[2] = 0;
   out_3854196706556040023[3] = 0;
   out_3854196706556040023[4] = 0;
   out_3854196706556040023[5] = 0;
   out_3854196706556040023[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3854196706556040023[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3854196706556040023[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3854196706556040023[9] = 0;
   out_3854196706556040023[10] = 0;
   out_3854196706556040023[11] = 0;
   out_3854196706556040023[12] = 0;
   out_3854196706556040023[13] = 0;
   out_3854196706556040023[14] = 0;
   out_3854196706556040023[15] = 0;
   out_3854196706556040023[16] = 0;
   out_3854196706556040023[17] = 0;
   out_3854196706556040023[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3854196706556040023[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3854196706556040023[20] = 0;
   out_3854196706556040023[21] = 0;
   out_3854196706556040023[22] = 0;
   out_3854196706556040023[23] = 0;
   out_3854196706556040023[24] = 0;
   out_3854196706556040023[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3854196706556040023[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3854196706556040023[27] = 0;
   out_3854196706556040023[28] = 0;
   out_3854196706556040023[29] = 0;
   out_3854196706556040023[30] = 0;
   out_3854196706556040023[31] = 0;
   out_3854196706556040023[32] = 0;
   out_3854196706556040023[33] = 0;
   out_3854196706556040023[34] = 0;
   out_3854196706556040023[35] = 0;
   out_3854196706556040023[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3854196706556040023[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3854196706556040023[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3854196706556040023[39] = 0;
   out_3854196706556040023[40] = 0;
   out_3854196706556040023[41] = 0;
   out_3854196706556040023[42] = 0;
   out_3854196706556040023[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3854196706556040023[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3854196706556040023[45] = 0;
   out_3854196706556040023[46] = 0;
   out_3854196706556040023[47] = 0;
   out_3854196706556040023[48] = 0;
   out_3854196706556040023[49] = 0;
   out_3854196706556040023[50] = 0;
   out_3854196706556040023[51] = 0;
   out_3854196706556040023[52] = 0;
   out_3854196706556040023[53] = 0;
   out_3854196706556040023[54] = 0;
   out_3854196706556040023[55] = 0;
   out_3854196706556040023[56] = 0;
   out_3854196706556040023[57] = 1;
   out_3854196706556040023[58] = 0;
   out_3854196706556040023[59] = 0;
   out_3854196706556040023[60] = 0;
   out_3854196706556040023[61] = 0;
   out_3854196706556040023[62] = 0;
   out_3854196706556040023[63] = 0;
   out_3854196706556040023[64] = 0;
   out_3854196706556040023[65] = 0;
   out_3854196706556040023[66] = dt;
   out_3854196706556040023[67] = 0;
   out_3854196706556040023[68] = 0;
   out_3854196706556040023[69] = 0;
   out_3854196706556040023[70] = 0;
   out_3854196706556040023[71] = 0;
   out_3854196706556040023[72] = 0;
   out_3854196706556040023[73] = 0;
   out_3854196706556040023[74] = 0;
   out_3854196706556040023[75] = 0;
   out_3854196706556040023[76] = 1;
   out_3854196706556040023[77] = 0;
   out_3854196706556040023[78] = 0;
   out_3854196706556040023[79] = 0;
   out_3854196706556040023[80] = 0;
   out_3854196706556040023[81] = 0;
   out_3854196706556040023[82] = 0;
   out_3854196706556040023[83] = 0;
   out_3854196706556040023[84] = 0;
   out_3854196706556040023[85] = dt;
   out_3854196706556040023[86] = 0;
   out_3854196706556040023[87] = 0;
   out_3854196706556040023[88] = 0;
   out_3854196706556040023[89] = 0;
   out_3854196706556040023[90] = 0;
   out_3854196706556040023[91] = 0;
   out_3854196706556040023[92] = 0;
   out_3854196706556040023[93] = 0;
   out_3854196706556040023[94] = 0;
   out_3854196706556040023[95] = 1;
   out_3854196706556040023[96] = 0;
   out_3854196706556040023[97] = 0;
   out_3854196706556040023[98] = 0;
   out_3854196706556040023[99] = 0;
   out_3854196706556040023[100] = 0;
   out_3854196706556040023[101] = 0;
   out_3854196706556040023[102] = 0;
   out_3854196706556040023[103] = 0;
   out_3854196706556040023[104] = dt;
   out_3854196706556040023[105] = 0;
   out_3854196706556040023[106] = 0;
   out_3854196706556040023[107] = 0;
   out_3854196706556040023[108] = 0;
   out_3854196706556040023[109] = 0;
   out_3854196706556040023[110] = 0;
   out_3854196706556040023[111] = 0;
   out_3854196706556040023[112] = 0;
   out_3854196706556040023[113] = 0;
   out_3854196706556040023[114] = 1;
   out_3854196706556040023[115] = 0;
   out_3854196706556040023[116] = 0;
   out_3854196706556040023[117] = 0;
   out_3854196706556040023[118] = 0;
   out_3854196706556040023[119] = 0;
   out_3854196706556040023[120] = 0;
   out_3854196706556040023[121] = 0;
   out_3854196706556040023[122] = 0;
   out_3854196706556040023[123] = 0;
   out_3854196706556040023[124] = 0;
   out_3854196706556040023[125] = 0;
   out_3854196706556040023[126] = 0;
   out_3854196706556040023[127] = 0;
   out_3854196706556040023[128] = 0;
   out_3854196706556040023[129] = 0;
   out_3854196706556040023[130] = 0;
   out_3854196706556040023[131] = 0;
   out_3854196706556040023[132] = 0;
   out_3854196706556040023[133] = 1;
   out_3854196706556040023[134] = 0;
   out_3854196706556040023[135] = 0;
   out_3854196706556040023[136] = 0;
   out_3854196706556040023[137] = 0;
   out_3854196706556040023[138] = 0;
   out_3854196706556040023[139] = 0;
   out_3854196706556040023[140] = 0;
   out_3854196706556040023[141] = 0;
   out_3854196706556040023[142] = 0;
   out_3854196706556040023[143] = 0;
   out_3854196706556040023[144] = 0;
   out_3854196706556040023[145] = 0;
   out_3854196706556040023[146] = 0;
   out_3854196706556040023[147] = 0;
   out_3854196706556040023[148] = 0;
   out_3854196706556040023[149] = 0;
   out_3854196706556040023[150] = 0;
   out_3854196706556040023[151] = 0;
   out_3854196706556040023[152] = 1;
   out_3854196706556040023[153] = 0;
   out_3854196706556040023[154] = 0;
   out_3854196706556040023[155] = 0;
   out_3854196706556040023[156] = 0;
   out_3854196706556040023[157] = 0;
   out_3854196706556040023[158] = 0;
   out_3854196706556040023[159] = 0;
   out_3854196706556040023[160] = 0;
   out_3854196706556040023[161] = 0;
   out_3854196706556040023[162] = 0;
   out_3854196706556040023[163] = 0;
   out_3854196706556040023[164] = 0;
   out_3854196706556040023[165] = 0;
   out_3854196706556040023[166] = 0;
   out_3854196706556040023[167] = 0;
   out_3854196706556040023[168] = 0;
   out_3854196706556040023[169] = 0;
   out_3854196706556040023[170] = 0;
   out_3854196706556040023[171] = 1;
   out_3854196706556040023[172] = 0;
   out_3854196706556040023[173] = 0;
   out_3854196706556040023[174] = 0;
   out_3854196706556040023[175] = 0;
   out_3854196706556040023[176] = 0;
   out_3854196706556040023[177] = 0;
   out_3854196706556040023[178] = 0;
   out_3854196706556040023[179] = 0;
   out_3854196706556040023[180] = 0;
   out_3854196706556040023[181] = 0;
   out_3854196706556040023[182] = 0;
   out_3854196706556040023[183] = 0;
   out_3854196706556040023[184] = 0;
   out_3854196706556040023[185] = 0;
   out_3854196706556040023[186] = 0;
   out_3854196706556040023[187] = 0;
   out_3854196706556040023[188] = 0;
   out_3854196706556040023[189] = 0;
   out_3854196706556040023[190] = 1;
   out_3854196706556040023[191] = 0;
   out_3854196706556040023[192] = 0;
   out_3854196706556040023[193] = 0;
   out_3854196706556040023[194] = 0;
   out_3854196706556040023[195] = 0;
   out_3854196706556040023[196] = 0;
   out_3854196706556040023[197] = 0;
   out_3854196706556040023[198] = 0;
   out_3854196706556040023[199] = 0;
   out_3854196706556040023[200] = 0;
   out_3854196706556040023[201] = 0;
   out_3854196706556040023[202] = 0;
   out_3854196706556040023[203] = 0;
   out_3854196706556040023[204] = 0;
   out_3854196706556040023[205] = 0;
   out_3854196706556040023[206] = 0;
   out_3854196706556040023[207] = 0;
   out_3854196706556040023[208] = 0;
   out_3854196706556040023[209] = 1;
   out_3854196706556040023[210] = 0;
   out_3854196706556040023[211] = 0;
   out_3854196706556040023[212] = 0;
   out_3854196706556040023[213] = 0;
   out_3854196706556040023[214] = 0;
   out_3854196706556040023[215] = 0;
   out_3854196706556040023[216] = 0;
   out_3854196706556040023[217] = 0;
   out_3854196706556040023[218] = 0;
   out_3854196706556040023[219] = 0;
   out_3854196706556040023[220] = 0;
   out_3854196706556040023[221] = 0;
   out_3854196706556040023[222] = 0;
   out_3854196706556040023[223] = 0;
   out_3854196706556040023[224] = 0;
   out_3854196706556040023[225] = 0;
   out_3854196706556040023[226] = 0;
   out_3854196706556040023[227] = 0;
   out_3854196706556040023[228] = 1;
   out_3854196706556040023[229] = 0;
   out_3854196706556040023[230] = 0;
   out_3854196706556040023[231] = 0;
   out_3854196706556040023[232] = 0;
   out_3854196706556040023[233] = 0;
   out_3854196706556040023[234] = 0;
   out_3854196706556040023[235] = 0;
   out_3854196706556040023[236] = 0;
   out_3854196706556040023[237] = 0;
   out_3854196706556040023[238] = 0;
   out_3854196706556040023[239] = 0;
   out_3854196706556040023[240] = 0;
   out_3854196706556040023[241] = 0;
   out_3854196706556040023[242] = 0;
   out_3854196706556040023[243] = 0;
   out_3854196706556040023[244] = 0;
   out_3854196706556040023[245] = 0;
   out_3854196706556040023[246] = 0;
   out_3854196706556040023[247] = 1;
   out_3854196706556040023[248] = 0;
   out_3854196706556040023[249] = 0;
   out_3854196706556040023[250] = 0;
   out_3854196706556040023[251] = 0;
   out_3854196706556040023[252] = 0;
   out_3854196706556040023[253] = 0;
   out_3854196706556040023[254] = 0;
   out_3854196706556040023[255] = 0;
   out_3854196706556040023[256] = 0;
   out_3854196706556040023[257] = 0;
   out_3854196706556040023[258] = 0;
   out_3854196706556040023[259] = 0;
   out_3854196706556040023[260] = 0;
   out_3854196706556040023[261] = 0;
   out_3854196706556040023[262] = 0;
   out_3854196706556040023[263] = 0;
   out_3854196706556040023[264] = 0;
   out_3854196706556040023[265] = 0;
   out_3854196706556040023[266] = 1;
   out_3854196706556040023[267] = 0;
   out_3854196706556040023[268] = 0;
   out_3854196706556040023[269] = 0;
   out_3854196706556040023[270] = 0;
   out_3854196706556040023[271] = 0;
   out_3854196706556040023[272] = 0;
   out_3854196706556040023[273] = 0;
   out_3854196706556040023[274] = 0;
   out_3854196706556040023[275] = 0;
   out_3854196706556040023[276] = 0;
   out_3854196706556040023[277] = 0;
   out_3854196706556040023[278] = 0;
   out_3854196706556040023[279] = 0;
   out_3854196706556040023[280] = 0;
   out_3854196706556040023[281] = 0;
   out_3854196706556040023[282] = 0;
   out_3854196706556040023[283] = 0;
   out_3854196706556040023[284] = 0;
   out_3854196706556040023[285] = 1;
   out_3854196706556040023[286] = 0;
   out_3854196706556040023[287] = 0;
   out_3854196706556040023[288] = 0;
   out_3854196706556040023[289] = 0;
   out_3854196706556040023[290] = 0;
   out_3854196706556040023[291] = 0;
   out_3854196706556040023[292] = 0;
   out_3854196706556040023[293] = 0;
   out_3854196706556040023[294] = 0;
   out_3854196706556040023[295] = 0;
   out_3854196706556040023[296] = 0;
   out_3854196706556040023[297] = 0;
   out_3854196706556040023[298] = 0;
   out_3854196706556040023[299] = 0;
   out_3854196706556040023[300] = 0;
   out_3854196706556040023[301] = 0;
   out_3854196706556040023[302] = 0;
   out_3854196706556040023[303] = 0;
   out_3854196706556040023[304] = 1;
   out_3854196706556040023[305] = 0;
   out_3854196706556040023[306] = 0;
   out_3854196706556040023[307] = 0;
   out_3854196706556040023[308] = 0;
   out_3854196706556040023[309] = 0;
   out_3854196706556040023[310] = 0;
   out_3854196706556040023[311] = 0;
   out_3854196706556040023[312] = 0;
   out_3854196706556040023[313] = 0;
   out_3854196706556040023[314] = 0;
   out_3854196706556040023[315] = 0;
   out_3854196706556040023[316] = 0;
   out_3854196706556040023[317] = 0;
   out_3854196706556040023[318] = 0;
   out_3854196706556040023[319] = 0;
   out_3854196706556040023[320] = 0;
   out_3854196706556040023[321] = 0;
   out_3854196706556040023[322] = 0;
   out_3854196706556040023[323] = 1;
}
void h_4(double *state, double *unused, double *out_6044371799568265897) {
   out_6044371799568265897[0] = state[6] + state[9];
   out_6044371799568265897[1] = state[7] + state[10];
   out_6044371799568265897[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8751938887176636728) {
   out_8751938887176636728[0] = 0;
   out_8751938887176636728[1] = 0;
   out_8751938887176636728[2] = 0;
   out_8751938887176636728[3] = 0;
   out_8751938887176636728[4] = 0;
   out_8751938887176636728[5] = 0;
   out_8751938887176636728[6] = 1;
   out_8751938887176636728[7] = 0;
   out_8751938887176636728[8] = 0;
   out_8751938887176636728[9] = 1;
   out_8751938887176636728[10] = 0;
   out_8751938887176636728[11] = 0;
   out_8751938887176636728[12] = 0;
   out_8751938887176636728[13] = 0;
   out_8751938887176636728[14] = 0;
   out_8751938887176636728[15] = 0;
   out_8751938887176636728[16] = 0;
   out_8751938887176636728[17] = 0;
   out_8751938887176636728[18] = 0;
   out_8751938887176636728[19] = 0;
   out_8751938887176636728[20] = 0;
   out_8751938887176636728[21] = 0;
   out_8751938887176636728[22] = 0;
   out_8751938887176636728[23] = 0;
   out_8751938887176636728[24] = 0;
   out_8751938887176636728[25] = 1;
   out_8751938887176636728[26] = 0;
   out_8751938887176636728[27] = 0;
   out_8751938887176636728[28] = 1;
   out_8751938887176636728[29] = 0;
   out_8751938887176636728[30] = 0;
   out_8751938887176636728[31] = 0;
   out_8751938887176636728[32] = 0;
   out_8751938887176636728[33] = 0;
   out_8751938887176636728[34] = 0;
   out_8751938887176636728[35] = 0;
   out_8751938887176636728[36] = 0;
   out_8751938887176636728[37] = 0;
   out_8751938887176636728[38] = 0;
   out_8751938887176636728[39] = 0;
   out_8751938887176636728[40] = 0;
   out_8751938887176636728[41] = 0;
   out_8751938887176636728[42] = 0;
   out_8751938887176636728[43] = 0;
   out_8751938887176636728[44] = 1;
   out_8751938887176636728[45] = 0;
   out_8751938887176636728[46] = 0;
   out_8751938887176636728[47] = 1;
   out_8751938887176636728[48] = 0;
   out_8751938887176636728[49] = 0;
   out_8751938887176636728[50] = 0;
   out_8751938887176636728[51] = 0;
   out_8751938887176636728[52] = 0;
   out_8751938887176636728[53] = 0;
}
void h_10(double *state, double *unused, double *out_9126782512040865980) {
   out_9126782512040865980[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_9126782512040865980[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_9126782512040865980[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2728048388349900962) {
   out_2728048388349900962[0] = 0;
   out_2728048388349900962[1] = 9.8100000000000005*cos(state[1]);
   out_2728048388349900962[2] = 0;
   out_2728048388349900962[3] = 0;
   out_2728048388349900962[4] = -state[8];
   out_2728048388349900962[5] = state[7];
   out_2728048388349900962[6] = 0;
   out_2728048388349900962[7] = state[5];
   out_2728048388349900962[8] = -state[4];
   out_2728048388349900962[9] = 0;
   out_2728048388349900962[10] = 0;
   out_2728048388349900962[11] = 0;
   out_2728048388349900962[12] = 1;
   out_2728048388349900962[13] = 0;
   out_2728048388349900962[14] = 0;
   out_2728048388349900962[15] = 1;
   out_2728048388349900962[16] = 0;
   out_2728048388349900962[17] = 0;
   out_2728048388349900962[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2728048388349900962[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2728048388349900962[20] = 0;
   out_2728048388349900962[21] = state[8];
   out_2728048388349900962[22] = 0;
   out_2728048388349900962[23] = -state[6];
   out_2728048388349900962[24] = -state[5];
   out_2728048388349900962[25] = 0;
   out_2728048388349900962[26] = state[3];
   out_2728048388349900962[27] = 0;
   out_2728048388349900962[28] = 0;
   out_2728048388349900962[29] = 0;
   out_2728048388349900962[30] = 0;
   out_2728048388349900962[31] = 1;
   out_2728048388349900962[32] = 0;
   out_2728048388349900962[33] = 0;
   out_2728048388349900962[34] = 1;
   out_2728048388349900962[35] = 0;
   out_2728048388349900962[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2728048388349900962[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2728048388349900962[38] = 0;
   out_2728048388349900962[39] = -state[7];
   out_2728048388349900962[40] = state[6];
   out_2728048388349900962[41] = 0;
   out_2728048388349900962[42] = state[4];
   out_2728048388349900962[43] = -state[3];
   out_2728048388349900962[44] = 0;
   out_2728048388349900962[45] = 0;
   out_2728048388349900962[46] = 0;
   out_2728048388349900962[47] = 0;
   out_2728048388349900962[48] = 0;
   out_2728048388349900962[49] = 0;
   out_2728048388349900962[50] = 1;
   out_2728048388349900962[51] = 0;
   out_2728048388349900962[52] = 0;
   out_2728048388349900962[53] = 1;
}
void h_13(double *state, double *unused, double *out_6648711810487729870) {
   out_6648711810487729870[0] = state[3];
   out_6648711810487729870[1] = state[4];
   out_6648711810487729870[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1141307678859935799) {
   out_1141307678859935799[0] = 0;
   out_1141307678859935799[1] = 0;
   out_1141307678859935799[2] = 0;
   out_1141307678859935799[3] = 1;
   out_1141307678859935799[4] = 0;
   out_1141307678859935799[5] = 0;
   out_1141307678859935799[6] = 0;
   out_1141307678859935799[7] = 0;
   out_1141307678859935799[8] = 0;
   out_1141307678859935799[9] = 0;
   out_1141307678859935799[10] = 0;
   out_1141307678859935799[11] = 0;
   out_1141307678859935799[12] = 0;
   out_1141307678859935799[13] = 0;
   out_1141307678859935799[14] = 0;
   out_1141307678859935799[15] = 0;
   out_1141307678859935799[16] = 0;
   out_1141307678859935799[17] = 0;
   out_1141307678859935799[18] = 0;
   out_1141307678859935799[19] = 0;
   out_1141307678859935799[20] = 0;
   out_1141307678859935799[21] = 0;
   out_1141307678859935799[22] = 1;
   out_1141307678859935799[23] = 0;
   out_1141307678859935799[24] = 0;
   out_1141307678859935799[25] = 0;
   out_1141307678859935799[26] = 0;
   out_1141307678859935799[27] = 0;
   out_1141307678859935799[28] = 0;
   out_1141307678859935799[29] = 0;
   out_1141307678859935799[30] = 0;
   out_1141307678859935799[31] = 0;
   out_1141307678859935799[32] = 0;
   out_1141307678859935799[33] = 0;
   out_1141307678859935799[34] = 0;
   out_1141307678859935799[35] = 0;
   out_1141307678859935799[36] = 0;
   out_1141307678859935799[37] = 0;
   out_1141307678859935799[38] = 0;
   out_1141307678859935799[39] = 0;
   out_1141307678859935799[40] = 0;
   out_1141307678859935799[41] = 1;
   out_1141307678859935799[42] = 0;
   out_1141307678859935799[43] = 0;
   out_1141307678859935799[44] = 0;
   out_1141307678859935799[45] = 0;
   out_1141307678859935799[46] = 0;
   out_1141307678859935799[47] = 0;
   out_1141307678859935799[48] = 0;
   out_1141307678859935799[49] = 0;
   out_1141307678859935799[50] = 0;
   out_1141307678859935799[51] = 0;
   out_1141307678859935799[52] = 0;
   out_1141307678859935799[53] = 0;
}
void h_14(double *state, double *unused, double *out_6901319929397273887) {
   out_6901319929397273887[0] = state[6];
   out_6901319929397273887[1] = state[7];
   out_6901319929397273887[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4788698030837152199) {
   out_4788698030837152199[0] = 0;
   out_4788698030837152199[1] = 0;
   out_4788698030837152199[2] = 0;
   out_4788698030837152199[3] = 0;
   out_4788698030837152199[4] = 0;
   out_4788698030837152199[5] = 0;
   out_4788698030837152199[6] = 1;
   out_4788698030837152199[7] = 0;
   out_4788698030837152199[8] = 0;
   out_4788698030837152199[9] = 0;
   out_4788698030837152199[10] = 0;
   out_4788698030837152199[11] = 0;
   out_4788698030837152199[12] = 0;
   out_4788698030837152199[13] = 0;
   out_4788698030837152199[14] = 0;
   out_4788698030837152199[15] = 0;
   out_4788698030837152199[16] = 0;
   out_4788698030837152199[17] = 0;
   out_4788698030837152199[18] = 0;
   out_4788698030837152199[19] = 0;
   out_4788698030837152199[20] = 0;
   out_4788698030837152199[21] = 0;
   out_4788698030837152199[22] = 0;
   out_4788698030837152199[23] = 0;
   out_4788698030837152199[24] = 0;
   out_4788698030837152199[25] = 1;
   out_4788698030837152199[26] = 0;
   out_4788698030837152199[27] = 0;
   out_4788698030837152199[28] = 0;
   out_4788698030837152199[29] = 0;
   out_4788698030837152199[30] = 0;
   out_4788698030837152199[31] = 0;
   out_4788698030837152199[32] = 0;
   out_4788698030837152199[33] = 0;
   out_4788698030837152199[34] = 0;
   out_4788698030837152199[35] = 0;
   out_4788698030837152199[36] = 0;
   out_4788698030837152199[37] = 0;
   out_4788698030837152199[38] = 0;
   out_4788698030837152199[39] = 0;
   out_4788698030837152199[40] = 0;
   out_4788698030837152199[41] = 0;
   out_4788698030837152199[42] = 0;
   out_4788698030837152199[43] = 0;
   out_4788698030837152199[44] = 1;
   out_4788698030837152199[45] = 0;
   out_4788698030837152199[46] = 0;
   out_4788698030837152199[47] = 0;
   out_4788698030837152199[48] = 0;
   out_4788698030837152199[49] = 0;
   out_4788698030837152199[50] = 0;
   out_4788698030837152199[51] = 0;
   out_4788698030837152199[52] = 0;
   out_4788698030837152199[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_6531280423659383110) {
  err_fun(nom_x, delta_x, out_6531280423659383110);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2847042605170284069) {
  inv_err_fun(nom_x, true_x, out_2847042605170284069);
}
void pose_H_mod_fun(double *state, double *out_1201664963462517165) {
  H_mod_fun(state, out_1201664963462517165);
}
void pose_f_fun(double *state, double dt, double *out_4925442091395050631) {
  f_fun(state,  dt, out_4925442091395050631);
}
void pose_F_fun(double *state, double dt, double *out_3854196706556040023) {
  F_fun(state,  dt, out_3854196706556040023);
}
void pose_h_4(double *state, double *unused, double *out_6044371799568265897) {
  h_4(state, unused, out_6044371799568265897);
}
void pose_H_4(double *state, double *unused, double *out_8751938887176636728) {
  H_4(state, unused, out_8751938887176636728);
}
void pose_h_10(double *state, double *unused, double *out_9126782512040865980) {
  h_10(state, unused, out_9126782512040865980);
}
void pose_H_10(double *state, double *unused, double *out_2728048388349900962) {
  H_10(state, unused, out_2728048388349900962);
}
void pose_h_13(double *state, double *unused, double *out_6648711810487729870) {
  h_13(state, unused, out_6648711810487729870);
}
void pose_H_13(double *state, double *unused, double *out_1141307678859935799) {
  H_13(state, unused, out_1141307678859935799);
}
void pose_h_14(double *state, double *unused, double *out_6901319929397273887) {
  h_14(state, unused, out_6901319929397273887);
}
void pose_H_14(double *state, double *unused, double *out_4788698030837152199) {
  H_14(state, unused, out_4788698030837152199);
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
