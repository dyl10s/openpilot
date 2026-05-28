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
void err_fun(double *nom_x, double *delta_x, double *out_8207359146711228947) {
   out_8207359146711228947[0] = delta_x[0] + nom_x[0];
   out_8207359146711228947[1] = delta_x[1] + nom_x[1];
   out_8207359146711228947[2] = delta_x[2] + nom_x[2];
   out_8207359146711228947[3] = delta_x[3] + nom_x[3];
   out_8207359146711228947[4] = delta_x[4] + nom_x[4];
   out_8207359146711228947[5] = delta_x[5] + nom_x[5];
   out_8207359146711228947[6] = delta_x[6] + nom_x[6];
   out_8207359146711228947[7] = delta_x[7] + nom_x[7];
   out_8207359146711228947[8] = delta_x[8] + nom_x[8];
   out_8207359146711228947[9] = delta_x[9] + nom_x[9];
   out_8207359146711228947[10] = delta_x[10] + nom_x[10];
   out_8207359146711228947[11] = delta_x[11] + nom_x[11];
   out_8207359146711228947[12] = delta_x[12] + nom_x[12];
   out_8207359146711228947[13] = delta_x[13] + nom_x[13];
   out_8207359146711228947[14] = delta_x[14] + nom_x[14];
   out_8207359146711228947[15] = delta_x[15] + nom_x[15];
   out_8207359146711228947[16] = delta_x[16] + nom_x[16];
   out_8207359146711228947[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8369219426901598353) {
   out_8369219426901598353[0] = -nom_x[0] + true_x[0];
   out_8369219426901598353[1] = -nom_x[1] + true_x[1];
   out_8369219426901598353[2] = -nom_x[2] + true_x[2];
   out_8369219426901598353[3] = -nom_x[3] + true_x[3];
   out_8369219426901598353[4] = -nom_x[4] + true_x[4];
   out_8369219426901598353[5] = -nom_x[5] + true_x[5];
   out_8369219426901598353[6] = -nom_x[6] + true_x[6];
   out_8369219426901598353[7] = -nom_x[7] + true_x[7];
   out_8369219426901598353[8] = -nom_x[8] + true_x[8];
   out_8369219426901598353[9] = -nom_x[9] + true_x[9];
   out_8369219426901598353[10] = -nom_x[10] + true_x[10];
   out_8369219426901598353[11] = -nom_x[11] + true_x[11];
   out_8369219426901598353[12] = -nom_x[12] + true_x[12];
   out_8369219426901598353[13] = -nom_x[13] + true_x[13];
   out_8369219426901598353[14] = -nom_x[14] + true_x[14];
   out_8369219426901598353[15] = -nom_x[15] + true_x[15];
   out_8369219426901598353[16] = -nom_x[16] + true_x[16];
   out_8369219426901598353[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7202306802530511060) {
   out_7202306802530511060[0] = 1.0;
   out_7202306802530511060[1] = 0.0;
   out_7202306802530511060[2] = 0.0;
   out_7202306802530511060[3] = 0.0;
   out_7202306802530511060[4] = 0.0;
   out_7202306802530511060[5] = 0.0;
   out_7202306802530511060[6] = 0.0;
   out_7202306802530511060[7] = 0.0;
   out_7202306802530511060[8] = 0.0;
   out_7202306802530511060[9] = 0.0;
   out_7202306802530511060[10] = 0.0;
   out_7202306802530511060[11] = 0.0;
   out_7202306802530511060[12] = 0.0;
   out_7202306802530511060[13] = 0.0;
   out_7202306802530511060[14] = 0.0;
   out_7202306802530511060[15] = 0.0;
   out_7202306802530511060[16] = 0.0;
   out_7202306802530511060[17] = 0.0;
   out_7202306802530511060[18] = 0.0;
   out_7202306802530511060[19] = 1.0;
   out_7202306802530511060[20] = 0.0;
   out_7202306802530511060[21] = 0.0;
   out_7202306802530511060[22] = 0.0;
   out_7202306802530511060[23] = 0.0;
   out_7202306802530511060[24] = 0.0;
   out_7202306802530511060[25] = 0.0;
   out_7202306802530511060[26] = 0.0;
   out_7202306802530511060[27] = 0.0;
   out_7202306802530511060[28] = 0.0;
   out_7202306802530511060[29] = 0.0;
   out_7202306802530511060[30] = 0.0;
   out_7202306802530511060[31] = 0.0;
   out_7202306802530511060[32] = 0.0;
   out_7202306802530511060[33] = 0.0;
   out_7202306802530511060[34] = 0.0;
   out_7202306802530511060[35] = 0.0;
   out_7202306802530511060[36] = 0.0;
   out_7202306802530511060[37] = 0.0;
   out_7202306802530511060[38] = 1.0;
   out_7202306802530511060[39] = 0.0;
   out_7202306802530511060[40] = 0.0;
   out_7202306802530511060[41] = 0.0;
   out_7202306802530511060[42] = 0.0;
   out_7202306802530511060[43] = 0.0;
   out_7202306802530511060[44] = 0.0;
   out_7202306802530511060[45] = 0.0;
   out_7202306802530511060[46] = 0.0;
   out_7202306802530511060[47] = 0.0;
   out_7202306802530511060[48] = 0.0;
   out_7202306802530511060[49] = 0.0;
   out_7202306802530511060[50] = 0.0;
   out_7202306802530511060[51] = 0.0;
   out_7202306802530511060[52] = 0.0;
   out_7202306802530511060[53] = 0.0;
   out_7202306802530511060[54] = 0.0;
   out_7202306802530511060[55] = 0.0;
   out_7202306802530511060[56] = 0.0;
   out_7202306802530511060[57] = 1.0;
   out_7202306802530511060[58] = 0.0;
   out_7202306802530511060[59] = 0.0;
   out_7202306802530511060[60] = 0.0;
   out_7202306802530511060[61] = 0.0;
   out_7202306802530511060[62] = 0.0;
   out_7202306802530511060[63] = 0.0;
   out_7202306802530511060[64] = 0.0;
   out_7202306802530511060[65] = 0.0;
   out_7202306802530511060[66] = 0.0;
   out_7202306802530511060[67] = 0.0;
   out_7202306802530511060[68] = 0.0;
   out_7202306802530511060[69] = 0.0;
   out_7202306802530511060[70] = 0.0;
   out_7202306802530511060[71] = 0.0;
   out_7202306802530511060[72] = 0.0;
   out_7202306802530511060[73] = 0.0;
   out_7202306802530511060[74] = 0.0;
   out_7202306802530511060[75] = 0.0;
   out_7202306802530511060[76] = 1.0;
   out_7202306802530511060[77] = 0.0;
   out_7202306802530511060[78] = 0.0;
   out_7202306802530511060[79] = 0.0;
   out_7202306802530511060[80] = 0.0;
   out_7202306802530511060[81] = 0.0;
   out_7202306802530511060[82] = 0.0;
   out_7202306802530511060[83] = 0.0;
   out_7202306802530511060[84] = 0.0;
   out_7202306802530511060[85] = 0.0;
   out_7202306802530511060[86] = 0.0;
   out_7202306802530511060[87] = 0.0;
   out_7202306802530511060[88] = 0.0;
   out_7202306802530511060[89] = 0.0;
   out_7202306802530511060[90] = 0.0;
   out_7202306802530511060[91] = 0.0;
   out_7202306802530511060[92] = 0.0;
   out_7202306802530511060[93] = 0.0;
   out_7202306802530511060[94] = 0.0;
   out_7202306802530511060[95] = 1.0;
   out_7202306802530511060[96] = 0.0;
   out_7202306802530511060[97] = 0.0;
   out_7202306802530511060[98] = 0.0;
   out_7202306802530511060[99] = 0.0;
   out_7202306802530511060[100] = 0.0;
   out_7202306802530511060[101] = 0.0;
   out_7202306802530511060[102] = 0.0;
   out_7202306802530511060[103] = 0.0;
   out_7202306802530511060[104] = 0.0;
   out_7202306802530511060[105] = 0.0;
   out_7202306802530511060[106] = 0.0;
   out_7202306802530511060[107] = 0.0;
   out_7202306802530511060[108] = 0.0;
   out_7202306802530511060[109] = 0.0;
   out_7202306802530511060[110] = 0.0;
   out_7202306802530511060[111] = 0.0;
   out_7202306802530511060[112] = 0.0;
   out_7202306802530511060[113] = 0.0;
   out_7202306802530511060[114] = 1.0;
   out_7202306802530511060[115] = 0.0;
   out_7202306802530511060[116] = 0.0;
   out_7202306802530511060[117] = 0.0;
   out_7202306802530511060[118] = 0.0;
   out_7202306802530511060[119] = 0.0;
   out_7202306802530511060[120] = 0.0;
   out_7202306802530511060[121] = 0.0;
   out_7202306802530511060[122] = 0.0;
   out_7202306802530511060[123] = 0.0;
   out_7202306802530511060[124] = 0.0;
   out_7202306802530511060[125] = 0.0;
   out_7202306802530511060[126] = 0.0;
   out_7202306802530511060[127] = 0.0;
   out_7202306802530511060[128] = 0.0;
   out_7202306802530511060[129] = 0.0;
   out_7202306802530511060[130] = 0.0;
   out_7202306802530511060[131] = 0.0;
   out_7202306802530511060[132] = 0.0;
   out_7202306802530511060[133] = 1.0;
   out_7202306802530511060[134] = 0.0;
   out_7202306802530511060[135] = 0.0;
   out_7202306802530511060[136] = 0.0;
   out_7202306802530511060[137] = 0.0;
   out_7202306802530511060[138] = 0.0;
   out_7202306802530511060[139] = 0.0;
   out_7202306802530511060[140] = 0.0;
   out_7202306802530511060[141] = 0.0;
   out_7202306802530511060[142] = 0.0;
   out_7202306802530511060[143] = 0.0;
   out_7202306802530511060[144] = 0.0;
   out_7202306802530511060[145] = 0.0;
   out_7202306802530511060[146] = 0.0;
   out_7202306802530511060[147] = 0.0;
   out_7202306802530511060[148] = 0.0;
   out_7202306802530511060[149] = 0.0;
   out_7202306802530511060[150] = 0.0;
   out_7202306802530511060[151] = 0.0;
   out_7202306802530511060[152] = 1.0;
   out_7202306802530511060[153] = 0.0;
   out_7202306802530511060[154] = 0.0;
   out_7202306802530511060[155] = 0.0;
   out_7202306802530511060[156] = 0.0;
   out_7202306802530511060[157] = 0.0;
   out_7202306802530511060[158] = 0.0;
   out_7202306802530511060[159] = 0.0;
   out_7202306802530511060[160] = 0.0;
   out_7202306802530511060[161] = 0.0;
   out_7202306802530511060[162] = 0.0;
   out_7202306802530511060[163] = 0.0;
   out_7202306802530511060[164] = 0.0;
   out_7202306802530511060[165] = 0.0;
   out_7202306802530511060[166] = 0.0;
   out_7202306802530511060[167] = 0.0;
   out_7202306802530511060[168] = 0.0;
   out_7202306802530511060[169] = 0.0;
   out_7202306802530511060[170] = 0.0;
   out_7202306802530511060[171] = 1.0;
   out_7202306802530511060[172] = 0.0;
   out_7202306802530511060[173] = 0.0;
   out_7202306802530511060[174] = 0.0;
   out_7202306802530511060[175] = 0.0;
   out_7202306802530511060[176] = 0.0;
   out_7202306802530511060[177] = 0.0;
   out_7202306802530511060[178] = 0.0;
   out_7202306802530511060[179] = 0.0;
   out_7202306802530511060[180] = 0.0;
   out_7202306802530511060[181] = 0.0;
   out_7202306802530511060[182] = 0.0;
   out_7202306802530511060[183] = 0.0;
   out_7202306802530511060[184] = 0.0;
   out_7202306802530511060[185] = 0.0;
   out_7202306802530511060[186] = 0.0;
   out_7202306802530511060[187] = 0.0;
   out_7202306802530511060[188] = 0.0;
   out_7202306802530511060[189] = 0.0;
   out_7202306802530511060[190] = 1.0;
   out_7202306802530511060[191] = 0.0;
   out_7202306802530511060[192] = 0.0;
   out_7202306802530511060[193] = 0.0;
   out_7202306802530511060[194] = 0.0;
   out_7202306802530511060[195] = 0.0;
   out_7202306802530511060[196] = 0.0;
   out_7202306802530511060[197] = 0.0;
   out_7202306802530511060[198] = 0.0;
   out_7202306802530511060[199] = 0.0;
   out_7202306802530511060[200] = 0.0;
   out_7202306802530511060[201] = 0.0;
   out_7202306802530511060[202] = 0.0;
   out_7202306802530511060[203] = 0.0;
   out_7202306802530511060[204] = 0.0;
   out_7202306802530511060[205] = 0.0;
   out_7202306802530511060[206] = 0.0;
   out_7202306802530511060[207] = 0.0;
   out_7202306802530511060[208] = 0.0;
   out_7202306802530511060[209] = 1.0;
   out_7202306802530511060[210] = 0.0;
   out_7202306802530511060[211] = 0.0;
   out_7202306802530511060[212] = 0.0;
   out_7202306802530511060[213] = 0.0;
   out_7202306802530511060[214] = 0.0;
   out_7202306802530511060[215] = 0.0;
   out_7202306802530511060[216] = 0.0;
   out_7202306802530511060[217] = 0.0;
   out_7202306802530511060[218] = 0.0;
   out_7202306802530511060[219] = 0.0;
   out_7202306802530511060[220] = 0.0;
   out_7202306802530511060[221] = 0.0;
   out_7202306802530511060[222] = 0.0;
   out_7202306802530511060[223] = 0.0;
   out_7202306802530511060[224] = 0.0;
   out_7202306802530511060[225] = 0.0;
   out_7202306802530511060[226] = 0.0;
   out_7202306802530511060[227] = 0.0;
   out_7202306802530511060[228] = 1.0;
   out_7202306802530511060[229] = 0.0;
   out_7202306802530511060[230] = 0.0;
   out_7202306802530511060[231] = 0.0;
   out_7202306802530511060[232] = 0.0;
   out_7202306802530511060[233] = 0.0;
   out_7202306802530511060[234] = 0.0;
   out_7202306802530511060[235] = 0.0;
   out_7202306802530511060[236] = 0.0;
   out_7202306802530511060[237] = 0.0;
   out_7202306802530511060[238] = 0.0;
   out_7202306802530511060[239] = 0.0;
   out_7202306802530511060[240] = 0.0;
   out_7202306802530511060[241] = 0.0;
   out_7202306802530511060[242] = 0.0;
   out_7202306802530511060[243] = 0.0;
   out_7202306802530511060[244] = 0.0;
   out_7202306802530511060[245] = 0.0;
   out_7202306802530511060[246] = 0.0;
   out_7202306802530511060[247] = 1.0;
   out_7202306802530511060[248] = 0.0;
   out_7202306802530511060[249] = 0.0;
   out_7202306802530511060[250] = 0.0;
   out_7202306802530511060[251] = 0.0;
   out_7202306802530511060[252] = 0.0;
   out_7202306802530511060[253] = 0.0;
   out_7202306802530511060[254] = 0.0;
   out_7202306802530511060[255] = 0.0;
   out_7202306802530511060[256] = 0.0;
   out_7202306802530511060[257] = 0.0;
   out_7202306802530511060[258] = 0.0;
   out_7202306802530511060[259] = 0.0;
   out_7202306802530511060[260] = 0.0;
   out_7202306802530511060[261] = 0.0;
   out_7202306802530511060[262] = 0.0;
   out_7202306802530511060[263] = 0.0;
   out_7202306802530511060[264] = 0.0;
   out_7202306802530511060[265] = 0.0;
   out_7202306802530511060[266] = 1.0;
   out_7202306802530511060[267] = 0.0;
   out_7202306802530511060[268] = 0.0;
   out_7202306802530511060[269] = 0.0;
   out_7202306802530511060[270] = 0.0;
   out_7202306802530511060[271] = 0.0;
   out_7202306802530511060[272] = 0.0;
   out_7202306802530511060[273] = 0.0;
   out_7202306802530511060[274] = 0.0;
   out_7202306802530511060[275] = 0.0;
   out_7202306802530511060[276] = 0.0;
   out_7202306802530511060[277] = 0.0;
   out_7202306802530511060[278] = 0.0;
   out_7202306802530511060[279] = 0.0;
   out_7202306802530511060[280] = 0.0;
   out_7202306802530511060[281] = 0.0;
   out_7202306802530511060[282] = 0.0;
   out_7202306802530511060[283] = 0.0;
   out_7202306802530511060[284] = 0.0;
   out_7202306802530511060[285] = 1.0;
   out_7202306802530511060[286] = 0.0;
   out_7202306802530511060[287] = 0.0;
   out_7202306802530511060[288] = 0.0;
   out_7202306802530511060[289] = 0.0;
   out_7202306802530511060[290] = 0.0;
   out_7202306802530511060[291] = 0.0;
   out_7202306802530511060[292] = 0.0;
   out_7202306802530511060[293] = 0.0;
   out_7202306802530511060[294] = 0.0;
   out_7202306802530511060[295] = 0.0;
   out_7202306802530511060[296] = 0.0;
   out_7202306802530511060[297] = 0.0;
   out_7202306802530511060[298] = 0.0;
   out_7202306802530511060[299] = 0.0;
   out_7202306802530511060[300] = 0.0;
   out_7202306802530511060[301] = 0.0;
   out_7202306802530511060[302] = 0.0;
   out_7202306802530511060[303] = 0.0;
   out_7202306802530511060[304] = 1.0;
   out_7202306802530511060[305] = 0.0;
   out_7202306802530511060[306] = 0.0;
   out_7202306802530511060[307] = 0.0;
   out_7202306802530511060[308] = 0.0;
   out_7202306802530511060[309] = 0.0;
   out_7202306802530511060[310] = 0.0;
   out_7202306802530511060[311] = 0.0;
   out_7202306802530511060[312] = 0.0;
   out_7202306802530511060[313] = 0.0;
   out_7202306802530511060[314] = 0.0;
   out_7202306802530511060[315] = 0.0;
   out_7202306802530511060[316] = 0.0;
   out_7202306802530511060[317] = 0.0;
   out_7202306802530511060[318] = 0.0;
   out_7202306802530511060[319] = 0.0;
   out_7202306802530511060[320] = 0.0;
   out_7202306802530511060[321] = 0.0;
   out_7202306802530511060[322] = 0.0;
   out_7202306802530511060[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4961001892384611064) {
   out_4961001892384611064[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4961001892384611064[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4961001892384611064[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4961001892384611064[3] = dt*state[12] + state[3];
   out_4961001892384611064[4] = dt*state[13] + state[4];
   out_4961001892384611064[5] = dt*state[14] + state[5];
   out_4961001892384611064[6] = state[6];
   out_4961001892384611064[7] = state[7];
   out_4961001892384611064[8] = state[8];
   out_4961001892384611064[9] = state[9];
   out_4961001892384611064[10] = state[10];
   out_4961001892384611064[11] = state[11];
   out_4961001892384611064[12] = state[12];
   out_4961001892384611064[13] = state[13];
   out_4961001892384611064[14] = state[14];
   out_4961001892384611064[15] = state[15];
   out_4961001892384611064[16] = state[16];
   out_4961001892384611064[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4383751150204030030) {
   out_4383751150204030030[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4383751150204030030[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4383751150204030030[2] = 0;
   out_4383751150204030030[3] = 0;
   out_4383751150204030030[4] = 0;
   out_4383751150204030030[5] = 0;
   out_4383751150204030030[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4383751150204030030[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4383751150204030030[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4383751150204030030[9] = 0;
   out_4383751150204030030[10] = 0;
   out_4383751150204030030[11] = 0;
   out_4383751150204030030[12] = 0;
   out_4383751150204030030[13] = 0;
   out_4383751150204030030[14] = 0;
   out_4383751150204030030[15] = 0;
   out_4383751150204030030[16] = 0;
   out_4383751150204030030[17] = 0;
   out_4383751150204030030[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4383751150204030030[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4383751150204030030[20] = 0;
   out_4383751150204030030[21] = 0;
   out_4383751150204030030[22] = 0;
   out_4383751150204030030[23] = 0;
   out_4383751150204030030[24] = 0;
   out_4383751150204030030[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4383751150204030030[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4383751150204030030[27] = 0;
   out_4383751150204030030[28] = 0;
   out_4383751150204030030[29] = 0;
   out_4383751150204030030[30] = 0;
   out_4383751150204030030[31] = 0;
   out_4383751150204030030[32] = 0;
   out_4383751150204030030[33] = 0;
   out_4383751150204030030[34] = 0;
   out_4383751150204030030[35] = 0;
   out_4383751150204030030[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4383751150204030030[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4383751150204030030[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4383751150204030030[39] = 0;
   out_4383751150204030030[40] = 0;
   out_4383751150204030030[41] = 0;
   out_4383751150204030030[42] = 0;
   out_4383751150204030030[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4383751150204030030[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4383751150204030030[45] = 0;
   out_4383751150204030030[46] = 0;
   out_4383751150204030030[47] = 0;
   out_4383751150204030030[48] = 0;
   out_4383751150204030030[49] = 0;
   out_4383751150204030030[50] = 0;
   out_4383751150204030030[51] = 0;
   out_4383751150204030030[52] = 0;
   out_4383751150204030030[53] = 0;
   out_4383751150204030030[54] = 0;
   out_4383751150204030030[55] = 0;
   out_4383751150204030030[56] = 0;
   out_4383751150204030030[57] = 1;
   out_4383751150204030030[58] = 0;
   out_4383751150204030030[59] = 0;
   out_4383751150204030030[60] = 0;
   out_4383751150204030030[61] = 0;
   out_4383751150204030030[62] = 0;
   out_4383751150204030030[63] = 0;
   out_4383751150204030030[64] = 0;
   out_4383751150204030030[65] = 0;
   out_4383751150204030030[66] = dt;
   out_4383751150204030030[67] = 0;
   out_4383751150204030030[68] = 0;
   out_4383751150204030030[69] = 0;
   out_4383751150204030030[70] = 0;
   out_4383751150204030030[71] = 0;
   out_4383751150204030030[72] = 0;
   out_4383751150204030030[73] = 0;
   out_4383751150204030030[74] = 0;
   out_4383751150204030030[75] = 0;
   out_4383751150204030030[76] = 1;
   out_4383751150204030030[77] = 0;
   out_4383751150204030030[78] = 0;
   out_4383751150204030030[79] = 0;
   out_4383751150204030030[80] = 0;
   out_4383751150204030030[81] = 0;
   out_4383751150204030030[82] = 0;
   out_4383751150204030030[83] = 0;
   out_4383751150204030030[84] = 0;
   out_4383751150204030030[85] = dt;
   out_4383751150204030030[86] = 0;
   out_4383751150204030030[87] = 0;
   out_4383751150204030030[88] = 0;
   out_4383751150204030030[89] = 0;
   out_4383751150204030030[90] = 0;
   out_4383751150204030030[91] = 0;
   out_4383751150204030030[92] = 0;
   out_4383751150204030030[93] = 0;
   out_4383751150204030030[94] = 0;
   out_4383751150204030030[95] = 1;
   out_4383751150204030030[96] = 0;
   out_4383751150204030030[97] = 0;
   out_4383751150204030030[98] = 0;
   out_4383751150204030030[99] = 0;
   out_4383751150204030030[100] = 0;
   out_4383751150204030030[101] = 0;
   out_4383751150204030030[102] = 0;
   out_4383751150204030030[103] = 0;
   out_4383751150204030030[104] = dt;
   out_4383751150204030030[105] = 0;
   out_4383751150204030030[106] = 0;
   out_4383751150204030030[107] = 0;
   out_4383751150204030030[108] = 0;
   out_4383751150204030030[109] = 0;
   out_4383751150204030030[110] = 0;
   out_4383751150204030030[111] = 0;
   out_4383751150204030030[112] = 0;
   out_4383751150204030030[113] = 0;
   out_4383751150204030030[114] = 1;
   out_4383751150204030030[115] = 0;
   out_4383751150204030030[116] = 0;
   out_4383751150204030030[117] = 0;
   out_4383751150204030030[118] = 0;
   out_4383751150204030030[119] = 0;
   out_4383751150204030030[120] = 0;
   out_4383751150204030030[121] = 0;
   out_4383751150204030030[122] = 0;
   out_4383751150204030030[123] = 0;
   out_4383751150204030030[124] = 0;
   out_4383751150204030030[125] = 0;
   out_4383751150204030030[126] = 0;
   out_4383751150204030030[127] = 0;
   out_4383751150204030030[128] = 0;
   out_4383751150204030030[129] = 0;
   out_4383751150204030030[130] = 0;
   out_4383751150204030030[131] = 0;
   out_4383751150204030030[132] = 0;
   out_4383751150204030030[133] = 1;
   out_4383751150204030030[134] = 0;
   out_4383751150204030030[135] = 0;
   out_4383751150204030030[136] = 0;
   out_4383751150204030030[137] = 0;
   out_4383751150204030030[138] = 0;
   out_4383751150204030030[139] = 0;
   out_4383751150204030030[140] = 0;
   out_4383751150204030030[141] = 0;
   out_4383751150204030030[142] = 0;
   out_4383751150204030030[143] = 0;
   out_4383751150204030030[144] = 0;
   out_4383751150204030030[145] = 0;
   out_4383751150204030030[146] = 0;
   out_4383751150204030030[147] = 0;
   out_4383751150204030030[148] = 0;
   out_4383751150204030030[149] = 0;
   out_4383751150204030030[150] = 0;
   out_4383751150204030030[151] = 0;
   out_4383751150204030030[152] = 1;
   out_4383751150204030030[153] = 0;
   out_4383751150204030030[154] = 0;
   out_4383751150204030030[155] = 0;
   out_4383751150204030030[156] = 0;
   out_4383751150204030030[157] = 0;
   out_4383751150204030030[158] = 0;
   out_4383751150204030030[159] = 0;
   out_4383751150204030030[160] = 0;
   out_4383751150204030030[161] = 0;
   out_4383751150204030030[162] = 0;
   out_4383751150204030030[163] = 0;
   out_4383751150204030030[164] = 0;
   out_4383751150204030030[165] = 0;
   out_4383751150204030030[166] = 0;
   out_4383751150204030030[167] = 0;
   out_4383751150204030030[168] = 0;
   out_4383751150204030030[169] = 0;
   out_4383751150204030030[170] = 0;
   out_4383751150204030030[171] = 1;
   out_4383751150204030030[172] = 0;
   out_4383751150204030030[173] = 0;
   out_4383751150204030030[174] = 0;
   out_4383751150204030030[175] = 0;
   out_4383751150204030030[176] = 0;
   out_4383751150204030030[177] = 0;
   out_4383751150204030030[178] = 0;
   out_4383751150204030030[179] = 0;
   out_4383751150204030030[180] = 0;
   out_4383751150204030030[181] = 0;
   out_4383751150204030030[182] = 0;
   out_4383751150204030030[183] = 0;
   out_4383751150204030030[184] = 0;
   out_4383751150204030030[185] = 0;
   out_4383751150204030030[186] = 0;
   out_4383751150204030030[187] = 0;
   out_4383751150204030030[188] = 0;
   out_4383751150204030030[189] = 0;
   out_4383751150204030030[190] = 1;
   out_4383751150204030030[191] = 0;
   out_4383751150204030030[192] = 0;
   out_4383751150204030030[193] = 0;
   out_4383751150204030030[194] = 0;
   out_4383751150204030030[195] = 0;
   out_4383751150204030030[196] = 0;
   out_4383751150204030030[197] = 0;
   out_4383751150204030030[198] = 0;
   out_4383751150204030030[199] = 0;
   out_4383751150204030030[200] = 0;
   out_4383751150204030030[201] = 0;
   out_4383751150204030030[202] = 0;
   out_4383751150204030030[203] = 0;
   out_4383751150204030030[204] = 0;
   out_4383751150204030030[205] = 0;
   out_4383751150204030030[206] = 0;
   out_4383751150204030030[207] = 0;
   out_4383751150204030030[208] = 0;
   out_4383751150204030030[209] = 1;
   out_4383751150204030030[210] = 0;
   out_4383751150204030030[211] = 0;
   out_4383751150204030030[212] = 0;
   out_4383751150204030030[213] = 0;
   out_4383751150204030030[214] = 0;
   out_4383751150204030030[215] = 0;
   out_4383751150204030030[216] = 0;
   out_4383751150204030030[217] = 0;
   out_4383751150204030030[218] = 0;
   out_4383751150204030030[219] = 0;
   out_4383751150204030030[220] = 0;
   out_4383751150204030030[221] = 0;
   out_4383751150204030030[222] = 0;
   out_4383751150204030030[223] = 0;
   out_4383751150204030030[224] = 0;
   out_4383751150204030030[225] = 0;
   out_4383751150204030030[226] = 0;
   out_4383751150204030030[227] = 0;
   out_4383751150204030030[228] = 1;
   out_4383751150204030030[229] = 0;
   out_4383751150204030030[230] = 0;
   out_4383751150204030030[231] = 0;
   out_4383751150204030030[232] = 0;
   out_4383751150204030030[233] = 0;
   out_4383751150204030030[234] = 0;
   out_4383751150204030030[235] = 0;
   out_4383751150204030030[236] = 0;
   out_4383751150204030030[237] = 0;
   out_4383751150204030030[238] = 0;
   out_4383751150204030030[239] = 0;
   out_4383751150204030030[240] = 0;
   out_4383751150204030030[241] = 0;
   out_4383751150204030030[242] = 0;
   out_4383751150204030030[243] = 0;
   out_4383751150204030030[244] = 0;
   out_4383751150204030030[245] = 0;
   out_4383751150204030030[246] = 0;
   out_4383751150204030030[247] = 1;
   out_4383751150204030030[248] = 0;
   out_4383751150204030030[249] = 0;
   out_4383751150204030030[250] = 0;
   out_4383751150204030030[251] = 0;
   out_4383751150204030030[252] = 0;
   out_4383751150204030030[253] = 0;
   out_4383751150204030030[254] = 0;
   out_4383751150204030030[255] = 0;
   out_4383751150204030030[256] = 0;
   out_4383751150204030030[257] = 0;
   out_4383751150204030030[258] = 0;
   out_4383751150204030030[259] = 0;
   out_4383751150204030030[260] = 0;
   out_4383751150204030030[261] = 0;
   out_4383751150204030030[262] = 0;
   out_4383751150204030030[263] = 0;
   out_4383751150204030030[264] = 0;
   out_4383751150204030030[265] = 0;
   out_4383751150204030030[266] = 1;
   out_4383751150204030030[267] = 0;
   out_4383751150204030030[268] = 0;
   out_4383751150204030030[269] = 0;
   out_4383751150204030030[270] = 0;
   out_4383751150204030030[271] = 0;
   out_4383751150204030030[272] = 0;
   out_4383751150204030030[273] = 0;
   out_4383751150204030030[274] = 0;
   out_4383751150204030030[275] = 0;
   out_4383751150204030030[276] = 0;
   out_4383751150204030030[277] = 0;
   out_4383751150204030030[278] = 0;
   out_4383751150204030030[279] = 0;
   out_4383751150204030030[280] = 0;
   out_4383751150204030030[281] = 0;
   out_4383751150204030030[282] = 0;
   out_4383751150204030030[283] = 0;
   out_4383751150204030030[284] = 0;
   out_4383751150204030030[285] = 1;
   out_4383751150204030030[286] = 0;
   out_4383751150204030030[287] = 0;
   out_4383751150204030030[288] = 0;
   out_4383751150204030030[289] = 0;
   out_4383751150204030030[290] = 0;
   out_4383751150204030030[291] = 0;
   out_4383751150204030030[292] = 0;
   out_4383751150204030030[293] = 0;
   out_4383751150204030030[294] = 0;
   out_4383751150204030030[295] = 0;
   out_4383751150204030030[296] = 0;
   out_4383751150204030030[297] = 0;
   out_4383751150204030030[298] = 0;
   out_4383751150204030030[299] = 0;
   out_4383751150204030030[300] = 0;
   out_4383751150204030030[301] = 0;
   out_4383751150204030030[302] = 0;
   out_4383751150204030030[303] = 0;
   out_4383751150204030030[304] = 1;
   out_4383751150204030030[305] = 0;
   out_4383751150204030030[306] = 0;
   out_4383751150204030030[307] = 0;
   out_4383751150204030030[308] = 0;
   out_4383751150204030030[309] = 0;
   out_4383751150204030030[310] = 0;
   out_4383751150204030030[311] = 0;
   out_4383751150204030030[312] = 0;
   out_4383751150204030030[313] = 0;
   out_4383751150204030030[314] = 0;
   out_4383751150204030030[315] = 0;
   out_4383751150204030030[316] = 0;
   out_4383751150204030030[317] = 0;
   out_4383751150204030030[318] = 0;
   out_4383751150204030030[319] = 0;
   out_4383751150204030030[320] = 0;
   out_4383751150204030030[321] = 0;
   out_4383751150204030030[322] = 0;
   out_4383751150204030030[323] = 1;
}
void h_4(double *state, double *unused, double *out_878843833946471253) {
   out_878843833946471253[0] = state[6] + state[9];
   out_878843833946471253[1] = state[7] + state[10];
   out_878843833946471253[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7970215192388091303) {
   out_7970215192388091303[0] = 0;
   out_7970215192388091303[1] = 0;
   out_7970215192388091303[2] = 0;
   out_7970215192388091303[3] = 0;
   out_7970215192388091303[4] = 0;
   out_7970215192388091303[5] = 0;
   out_7970215192388091303[6] = 1;
   out_7970215192388091303[7] = 0;
   out_7970215192388091303[8] = 0;
   out_7970215192388091303[9] = 1;
   out_7970215192388091303[10] = 0;
   out_7970215192388091303[11] = 0;
   out_7970215192388091303[12] = 0;
   out_7970215192388091303[13] = 0;
   out_7970215192388091303[14] = 0;
   out_7970215192388091303[15] = 0;
   out_7970215192388091303[16] = 0;
   out_7970215192388091303[17] = 0;
   out_7970215192388091303[18] = 0;
   out_7970215192388091303[19] = 0;
   out_7970215192388091303[20] = 0;
   out_7970215192388091303[21] = 0;
   out_7970215192388091303[22] = 0;
   out_7970215192388091303[23] = 0;
   out_7970215192388091303[24] = 0;
   out_7970215192388091303[25] = 1;
   out_7970215192388091303[26] = 0;
   out_7970215192388091303[27] = 0;
   out_7970215192388091303[28] = 1;
   out_7970215192388091303[29] = 0;
   out_7970215192388091303[30] = 0;
   out_7970215192388091303[31] = 0;
   out_7970215192388091303[32] = 0;
   out_7970215192388091303[33] = 0;
   out_7970215192388091303[34] = 0;
   out_7970215192388091303[35] = 0;
   out_7970215192388091303[36] = 0;
   out_7970215192388091303[37] = 0;
   out_7970215192388091303[38] = 0;
   out_7970215192388091303[39] = 0;
   out_7970215192388091303[40] = 0;
   out_7970215192388091303[41] = 0;
   out_7970215192388091303[42] = 0;
   out_7970215192388091303[43] = 0;
   out_7970215192388091303[44] = 1;
   out_7970215192388091303[45] = 0;
   out_7970215192388091303[46] = 0;
   out_7970215192388091303[47] = 1;
   out_7970215192388091303[48] = 0;
   out_7970215192388091303[49] = 0;
   out_7970215192388091303[50] = 0;
   out_7970215192388091303[51] = 0;
   out_7970215192388091303[52] = 0;
   out_7970215192388091303[53] = 0;
}
void h_10(double *state, double *unused, double *out_1191517594273352576) {
   out_1191517594273352576[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1191517594273352576[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1191517594273352576[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_7914634342859917414) {
   out_7914634342859917414[0] = 0;
   out_7914634342859917414[1] = 9.8100000000000005*cos(state[1]);
   out_7914634342859917414[2] = 0;
   out_7914634342859917414[3] = 0;
   out_7914634342859917414[4] = -state[8];
   out_7914634342859917414[5] = state[7];
   out_7914634342859917414[6] = 0;
   out_7914634342859917414[7] = state[5];
   out_7914634342859917414[8] = -state[4];
   out_7914634342859917414[9] = 0;
   out_7914634342859917414[10] = 0;
   out_7914634342859917414[11] = 0;
   out_7914634342859917414[12] = 1;
   out_7914634342859917414[13] = 0;
   out_7914634342859917414[14] = 0;
   out_7914634342859917414[15] = 1;
   out_7914634342859917414[16] = 0;
   out_7914634342859917414[17] = 0;
   out_7914634342859917414[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_7914634342859917414[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_7914634342859917414[20] = 0;
   out_7914634342859917414[21] = state[8];
   out_7914634342859917414[22] = 0;
   out_7914634342859917414[23] = -state[6];
   out_7914634342859917414[24] = -state[5];
   out_7914634342859917414[25] = 0;
   out_7914634342859917414[26] = state[3];
   out_7914634342859917414[27] = 0;
   out_7914634342859917414[28] = 0;
   out_7914634342859917414[29] = 0;
   out_7914634342859917414[30] = 0;
   out_7914634342859917414[31] = 1;
   out_7914634342859917414[32] = 0;
   out_7914634342859917414[33] = 0;
   out_7914634342859917414[34] = 1;
   out_7914634342859917414[35] = 0;
   out_7914634342859917414[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_7914634342859917414[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_7914634342859917414[38] = 0;
   out_7914634342859917414[39] = -state[7];
   out_7914634342859917414[40] = state[6];
   out_7914634342859917414[41] = 0;
   out_7914634342859917414[42] = state[4];
   out_7914634342859917414[43] = -state[3];
   out_7914634342859917414[44] = 0;
   out_7914634342859917414[45] = 0;
   out_7914634342859917414[46] = 0;
   out_7914634342859917414[47] = 0;
   out_7914634342859917414[48] = 0;
   out_7914634342859917414[49] = 0;
   out_7914634342859917414[50] = 1;
   out_7914634342859917414[51] = 0;
   out_7914634342859917414[52] = 0;
   out_7914634342859917414[53] = 1;
}
void h_13(double *state, double *unused, double *out_5300060524255047032) {
   out_5300060524255047032[0] = state[3];
   out_5300060524255047032[1] = state[4];
   out_5300060524255047032[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7264255055989127512) {
   out_7264255055989127512[0] = 0;
   out_7264255055989127512[1] = 0;
   out_7264255055989127512[2] = 0;
   out_7264255055989127512[3] = 1;
   out_7264255055989127512[4] = 0;
   out_7264255055989127512[5] = 0;
   out_7264255055989127512[6] = 0;
   out_7264255055989127512[7] = 0;
   out_7264255055989127512[8] = 0;
   out_7264255055989127512[9] = 0;
   out_7264255055989127512[10] = 0;
   out_7264255055989127512[11] = 0;
   out_7264255055989127512[12] = 0;
   out_7264255055989127512[13] = 0;
   out_7264255055989127512[14] = 0;
   out_7264255055989127512[15] = 0;
   out_7264255055989127512[16] = 0;
   out_7264255055989127512[17] = 0;
   out_7264255055989127512[18] = 0;
   out_7264255055989127512[19] = 0;
   out_7264255055989127512[20] = 0;
   out_7264255055989127512[21] = 0;
   out_7264255055989127512[22] = 1;
   out_7264255055989127512[23] = 0;
   out_7264255055989127512[24] = 0;
   out_7264255055989127512[25] = 0;
   out_7264255055989127512[26] = 0;
   out_7264255055989127512[27] = 0;
   out_7264255055989127512[28] = 0;
   out_7264255055989127512[29] = 0;
   out_7264255055989127512[30] = 0;
   out_7264255055989127512[31] = 0;
   out_7264255055989127512[32] = 0;
   out_7264255055989127512[33] = 0;
   out_7264255055989127512[34] = 0;
   out_7264255055989127512[35] = 0;
   out_7264255055989127512[36] = 0;
   out_7264255055989127512[37] = 0;
   out_7264255055989127512[38] = 0;
   out_7264255055989127512[39] = 0;
   out_7264255055989127512[40] = 0;
   out_7264255055989127512[41] = 1;
   out_7264255055989127512[42] = 0;
   out_7264255055989127512[43] = 0;
   out_7264255055989127512[44] = 0;
   out_7264255055989127512[45] = 0;
   out_7264255055989127512[46] = 0;
   out_7264255055989127512[47] = 0;
   out_7264255055989127512[48] = 0;
   out_7264255055989127512[49] = 0;
   out_7264255055989127512[50] = 0;
   out_7264255055989127512[51] = 0;
   out_7264255055989127512[52] = 0;
   out_7264255055989127512[53] = 0;
}
void h_14(double *state, double *unused, double *out_3965460404426586337) {
   out_3965460404426586337[0] = state[6];
   out_3965460404426586337[1] = state[7];
   out_3965460404426586337[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6513288024981975784) {
   out_6513288024981975784[0] = 0;
   out_6513288024981975784[1] = 0;
   out_6513288024981975784[2] = 0;
   out_6513288024981975784[3] = 0;
   out_6513288024981975784[4] = 0;
   out_6513288024981975784[5] = 0;
   out_6513288024981975784[6] = 1;
   out_6513288024981975784[7] = 0;
   out_6513288024981975784[8] = 0;
   out_6513288024981975784[9] = 0;
   out_6513288024981975784[10] = 0;
   out_6513288024981975784[11] = 0;
   out_6513288024981975784[12] = 0;
   out_6513288024981975784[13] = 0;
   out_6513288024981975784[14] = 0;
   out_6513288024981975784[15] = 0;
   out_6513288024981975784[16] = 0;
   out_6513288024981975784[17] = 0;
   out_6513288024981975784[18] = 0;
   out_6513288024981975784[19] = 0;
   out_6513288024981975784[20] = 0;
   out_6513288024981975784[21] = 0;
   out_6513288024981975784[22] = 0;
   out_6513288024981975784[23] = 0;
   out_6513288024981975784[24] = 0;
   out_6513288024981975784[25] = 1;
   out_6513288024981975784[26] = 0;
   out_6513288024981975784[27] = 0;
   out_6513288024981975784[28] = 0;
   out_6513288024981975784[29] = 0;
   out_6513288024981975784[30] = 0;
   out_6513288024981975784[31] = 0;
   out_6513288024981975784[32] = 0;
   out_6513288024981975784[33] = 0;
   out_6513288024981975784[34] = 0;
   out_6513288024981975784[35] = 0;
   out_6513288024981975784[36] = 0;
   out_6513288024981975784[37] = 0;
   out_6513288024981975784[38] = 0;
   out_6513288024981975784[39] = 0;
   out_6513288024981975784[40] = 0;
   out_6513288024981975784[41] = 0;
   out_6513288024981975784[42] = 0;
   out_6513288024981975784[43] = 0;
   out_6513288024981975784[44] = 1;
   out_6513288024981975784[45] = 0;
   out_6513288024981975784[46] = 0;
   out_6513288024981975784[47] = 0;
   out_6513288024981975784[48] = 0;
   out_6513288024981975784[49] = 0;
   out_6513288024981975784[50] = 0;
   out_6513288024981975784[51] = 0;
   out_6513288024981975784[52] = 0;
   out_6513288024981975784[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8207359146711228947) {
  err_fun(nom_x, delta_x, out_8207359146711228947);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8369219426901598353) {
  inv_err_fun(nom_x, true_x, out_8369219426901598353);
}
void pose_H_mod_fun(double *state, double *out_7202306802530511060) {
  H_mod_fun(state, out_7202306802530511060);
}
void pose_f_fun(double *state, double dt, double *out_4961001892384611064) {
  f_fun(state,  dt, out_4961001892384611064);
}
void pose_F_fun(double *state, double dt, double *out_4383751150204030030) {
  F_fun(state,  dt, out_4383751150204030030);
}
void pose_h_4(double *state, double *unused, double *out_878843833946471253) {
  h_4(state, unused, out_878843833946471253);
}
void pose_H_4(double *state, double *unused, double *out_7970215192388091303) {
  H_4(state, unused, out_7970215192388091303);
}
void pose_h_10(double *state, double *unused, double *out_1191517594273352576) {
  h_10(state, unused, out_1191517594273352576);
}
void pose_H_10(double *state, double *unused, double *out_7914634342859917414) {
  H_10(state, unused, out_7914634342859917414);
}
void pose_h_13(double *state, double *unused, double *out_5300060524255047032) {
  h_13(state, unused, out_5300060524255047032);
}
void pose_H_13(double *state, double *unused, double *out_7264255055989127512) {
  H_13(state, unused, out_7264255055989127512);
}
void pose_h_14(double *state, double *unused, double *out_3965460404426586337) {
  h_14(state, unused, out_3965460404426586337);
}
void pose_H_14(double *state, double *unused, double *out_6513288024981975784) {
  H_14(state, unused, out_6513288024981975784);
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
