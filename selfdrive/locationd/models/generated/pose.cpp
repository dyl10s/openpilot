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
void err_fun(double *nom_x, double *delta_x, double *out_4890483987619646593) {
   out_4890483987619646593[0] = delta_x[0] + nom_x[0];
   out_4890483987619646593[1] = delta_x[1] + nom_x[1];
   out_4890483987619646593[2] = delta_x[2] + nom_x[2];
   out_4890483987619646593[3] = delta_x[3] + nom_x[3];
   out_4890483987619646593[4] = delta_x[4] + nom_x[4];
   out_4890483987619646593[5] = delta_x[5] + nom_x[5];
   out_4890483987619646593[6] = delta_x[6] + nom_x[6];
   out_4890483987619646593[7] = delta_x[7] + nom_x[7];
   out_4890483987619646593[8] = delta_x[8] + nom_x[8];
   out_4890483987619646593[9] = delta_x[9] + nom_x[9];
   out_4890483987619646593[10] = delta_x[10] + nom_x[10];
   out_4890483987619646593[11] = delta_x[11] + nom_x[11];
   out_4890483987619646593[12] = delta_x[12] + nom_x[12];
   out_4890483987619646593[13] = delta_x[13] + nom_x[13];
   out_4890483987619646593[14] = delta_x[14] + nom_x[14];
   out_4890483987619646593[15] = delta_x[15] + nom_x[15];
   out_4890483987619646593[16] = delta_x[16] + nom_x[16];
   out_4890483987619646593[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8601483282449025419) {
   out_8601483282449025419[0] = -nom_x[0] + true_x[0];
   out_8601483282449025419[1] = -nom_x[1] + true_x[1];
   out_8601483282449025419[2] = -nom_x[2] + true_x[2];
   out_8601483282449025419[3] = -nom_x[3] + true_x[3];
   out_8601483282449025419[4] = -nom_x[4] + true_x[4];
   out_8601483282449025419[5] = -nom_x[5] + true_x[5];
   out_8601483282449025419[6] = -nom_x[6] + true_x[6];
   out_8601483282449025419[7] = -nom_x[7] + true_x[7];
   out_8601483282449025419[8] = -nom_x[8] + true_x[8];
   out_8601483282449025419[9] = -nom_x[9] + true_x[9];
   out_8601483282449025419[10] = -nom_x[10] + true_x[10];
   out_8601483282449025419[11] = -nom_x[11] + true_x[11];
   out_8601483282449025419[12] = -nom_x[12] + true_x[12];
   out_8601483282449025419[13] = -nom_x[13] + true_x[13];
   out_8601483282449025419[14] = -nom_x[14] + true_x[14];
   out_8601483282449025419[15] = -nom_x[15] + true_x[15];
   out_8601483282449025419[16] = -nom_x[16] + true_x[16];
   out_8601483282449025419[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_998439548454101499) {
   out_998439548454101499[0] = 1.0;
   out_998439548454101499[1] = 0.0;
   out_998439548454101499[2] = 0.0;
   out_998439548454101499[3] = 0.0;
   out_998439548454101499[4] = 0.0;
   out_998439548454101499[5] = 0.0;
   out_998439548454101499[6] = 0.0;
   out_998439548454101499[7] = 0.0;
   out_998439548454101499[8] = 0.0;
   out_998439548454101499[9] = 0.0;
   out_998439548454101499[10] = 0.0;
   out_998439548454101499[11] = 0.0;
   out_998439548454101499[12] = 0.0;
   out_998439548454101499[13] = 0.0;
   out_998439548454101499[14] = 0.0;
   out_998439548454101499[15] = 0.0;
   out_998439548454101499[16] = 0.0;
   out_998439548454101499[17] = 0.0;
   out_998439548454101499[18] = 0.0;
   out_998439548454101499[19] = 1.0;
   out_998439548454101499[20] = 0.0;
   out_998439548454101499[21] = 0.0;
   out_998439548454101499[22] = 0.0;
   out_998439548454101499[23] = 0.0;
   out_998439548454101499[24] = 0.0;
   out_998439548454101499[25] = 0.0;
   out_998439548454101499[26] = 0.0;
   out_998439548454101499[27] = 0.0;
   out_998439548454101499[28] = 0.0;
   out_998439548454101499[29] = 0.0;
   out_998439548454101499[30] = 0.0;
   out_998439548454101499[31] = 0.0;
   out_998439548454101499[32] = 0.0;
   out_998439548454101499[33] = 0.0;
   out_998439548454101499[34] = 0.0;
   out_998439548454101499[35] = 0.0;
   out_998439548454101499[36] = 0.0;
   out_998439548454101499[37] = 0.0;
   out_998439548454101499[38] = 1.0;
   out_998439548454101499[39] = 0.0;
   out_998439548454101499[40] = 0.0;
   out_998439548454101499[41] = 0.0;
   out_998439548454101499[42] = 0.0;
   out_998439548454101499[43] = 0.0;
   out_998439548454101499[44] = 0.0;
   out_998439548454101499[45] = 0.0;
   out_998439548454101499[46] = 0.0;
   out_998439548454101499[47] = 0.0;
   out_998439548454101499[48] = 0.0;
   out_998439548454101499[49] = 0.0;
   out_998439548454101499[50] = 0.0;
   out_998439548454101499[51] = 0.0;
   out_998439548454101499[52] = 0.0;
   out_998439548454101499[53] = 0.0;
   out_998439548454101499[54] = 0.0;
   out_998439548454101499[55] = 0.0;
   out_998439548454101499[56] = 0.0;
   out_998439548454101499[57] = 1.0;
   out_998439548454101499[58] = 0.0;
   out_998439548454101499[59] = 0.0;
   out_998439548454101499[60] = 0.0;
   out_998439548454101499[61] = 0.0;
   out_998439548454101499[62] = 0.0;
   out_998439548454101499[63] = 0.0;
   out_998439548454101499[64] = 0.0;
   out_998439548454101499[65] = 0.0;
   out_998439548454101499[66] = 0.0;
   out_998439548454101499[67] = 0.0;
   out_998439548454101499[68] = 0.0;
   out_998439548454101499[69] = 0.0;
   out_998439548454101499[70] = 0.0;
   out_998439548454101499[71] = 0.0;
   out_998439548454101499[72] = 0.0;
   out_998439548454101499[73] = 0.0;
   out_998439548454101499[74] = 0.0;
   out_998439548454101499[75] = 0.0;
   out_998439548454101499[76] = 1.0;
   out_998439548454101499[77] = 0.0;
   out_998439548454101499[78] = 0.0;
   out_998439548454101499[79] = 0.0;
   out_998439548454101499[80] = 0.0;
   out_998439548454101499[81] = 0.0;
   out_998439548454101499[82] = 0.0;
   out_998439548454101499[83] = 0.0;
   out_998439548454101499[84] = 0.0;
   out_998439548454101499[85] = 0.0;
   out_998439548454101499[86] = 0.0;
   out_998439548454101499[87] = 0.0;
   out_998439548454101499[88] = 0.0;
   out_998439548454101499[89] = 0.0;
   out_998439548454101499[90] = 0.0;
   out_998439548454101499[91] = 0.0;
   out_998439548454101499[92] = 0.0;
   out_998439548454101499[93] = 0.0;
   out_998439548454101499[94] = 0.0;
   out_998439548454101499[95] = 1.0;
   out_998439548454101499[96] = 0.0;
   out_998439548454101499[97] = 0.0;
   out_998439548454101499[98] = 0.0;
   out_998439548454101499[99] = 0.0;
   out_998439548454101499[100] = 0.0;
   out_998439548454101499[101] = 0.0;
   out_998439548454101499[102] = 0.0;
   out_998439548454101499[103] = 0.0;
   out_998439548454101499[104] = 0.0;
   out_998439548454101499[105] = 0.0;
   out_998439548454101499[106] = 0.0;
   out_998439548454101499[107] = 0.0;
   out_998439548454101499[108] = 0.0;
   out_998439548454101499[109] = 0.0;
   out_998439548454101499[110] = 0.0;
   out_998439548454101499[111] = 0.0;
   out_998439548454101499[112] = 0.0;
   out_998439548454101499[113] = 0.0;
   out_998439548454101499[114] = 1.0;
   out_998439548454101499[115] = 0.0;
   out_998439548454101499[116] = 0.0;
   out_998439548454101499[117] = 0.0;
   out_998439548454101499[118] = 0.0;
   out_998439548454101499[119] = 0.0;
   out_998439548454101499[120] = 0.0;
   out_998439548454101499[121] = 0.0;
   out_998439548454101499[122] = 0.0;
   out_998439548454101499[123] = 0.0;
   out_998439548454101499[124] = 0.0;
   out_998439548454101499[125] = 0.0;
   out_998439548454101499[126] = 0.0;
   out_998439548454101499[127] = 0.0;
   out_998439548454101499[128] = 0.0;
   out_998439548454101499[129] = 0.0;
   out_998439548454101499[130] = 0.0;
   out_998439548454101499[131] = 0.0;
   out_998439548454101499[132] = 0.0;
   out_998439548454101499[133] = 1.0;
   out_998439548454101499[134] = 0.0;
   out_998439548454101499[135] = 0.0;
   out_998439548454101499[136] = 0.0;
   out_998439548454101499[137] = 0.0;
   out_998439548454101499[138] = 0.0;
   out_998439548454101499[139] = 0.0;
   out_998439548454101499[140] = 0.0;
   out_998439548454101499[141] = 0.0;
   out_998439548454101499[142] = 0.0;
   out_998439548454101499[143] = 0.0;
   out_998439548454101499[144] = 0.0;
   out_998439548454101499[145] = 0.0;
   out_998439548454101499[146] = 0.0;
   out_998439548454101499[147] = 0.0;
   out_998439548454101499[148] = 0.0;
   out_998439548454101499[149] = 0.0;
   out_998439548454101499[150] = 0.0;
   out_998439548454101499[151] = 0.0;
   out_998439548454101499[152] = 1.0;
   out_998439548454101499[153] = 0.0;
   out_998439548454101499[154] = 0.0;
   out_998439548454101499[155] = 0.0;
   out_998439548454101499[156] = 0.0;
   out_998439548454101499[157] = 0.0;
   out_998439548454101499[158] = 0.0;
   out_998439548454101499[159] = 0.0;
   out_998439548454101499[160] = 0.0;
   out_998439548454101499[161] = 0.0;
   out_998439548454101499[162] = 0.0;
   out_998439548454101499[163] = 0.0;
   out_998439548454101499[164] = 0.0;
   out_998439548454101499[165] = 0.0;
   out_998439548454101499[166] = 0.0;
   out_998439548454101499[167] = 0.0;
   out_998439548454101499[168] = 0.0;
   out_998439548454101499[169] = 0.0;
   out_998439548454101499[170] = 0.0;
   out_998439548454101499[171] = 1.0;
   out_998439548454101499[172] = 0.0;
   out_998439548454101499[173] = 0.0;
   out_998439548454101499[174] = 0.0;
   out_998439548454101499[175] = 0.0;
   out_998439548454101499[176] = 0.0;
   out_998439548454101499[177] = 0.0;
   out_998439548454101499[178] = 0.0;
   out_998439548454101499[179] = 0.0;
   out_998439548454101499[180] = 0.0;
   out_998439548454101499[181] = 0.0;
   out_998439548454101499[182] = 0.0;
   out_998439548454101499[183] = 0.0;
   out_998439548454101499[184] = 0.0;
   out_998439548454101499[185] = 0.0;
   out_998439548454101499[186] = 0.0;
   out_998439548454101499[187] = 0.0;
   out_998439548454101499[188] = 0.0;
   out_998439548454101499[189] = 0.0;
   out_998439548454101499[190] = 1.0;
   out_998439548454101499[191] = 0.0;
   out_998439548454101499[192] = 0.0;
   out_998439548454101499[193] = 0.0;
   out_998439548454101499[194] = 0.0;
   out_998439548454101499[195] = 0.0;
   out_998439548454101499[196] = 0.0;
   out_998439548454101499[197] = 0.0;
   out_998439548454101499[198] = 0.0;
   out_998439548454101499[199] = 0.0;
   out_998439548454101499[200] = 0.0;
   out_998439548454101499[201] = 0.0;
   out_998439548454101499[202] = 0.0;
   out_998439548454101499[203] = 0.0;
   out_998439548454101499[204] = 0.0;
   out_998439548454101499[205] = 0.0;
   out_998439548454101499[206] = 0.0;
   out_998439548454101499[207] = 0.0;
   out_998439548454101499[208] = 0.0;
   out_998439548454101499[209] = 1.0;
   out_998439548454101499[210] = 0.0;
   out_998439548454101499[211] = 0.0;
   out_998439548454101499[212] = 0.0;
   out_998439548454101499[213] = 0.0;
   out_998439548454101499[214] = 0.0;
   out_998439548454101499[215] = 0.0;
   out_998439548454101499[216] = 0.0;
   out_998439548454101499[217] = 0.0;
   out_998439548454101499[218] = 0.0;
   out_998439548454101499[219] = 0.0;
   out_998439548454101499[220] = 0.0;
   out_998439548454101499[221] = 0.0;
   out_998439548454101499[222] = 0.0;
   out_998439548454101499[223] = 0.0;
   out_998439548454101499[224] = 0.0;
   out_998439548454101499[225] = 0.0;
   out_998439548454101499[226] = 0.0;
   out_998439548454101499[227] = 0.0;
   out_998439548454101499[228] = 1.0;
   out_998439548454101499[229] = 0.0;
   out_998439548454101499[230] = 0.0;
   out_998439548454101499[231] = 0.0;
   out_998439548454101499[232] = 0.0;
   out_998439548454101499[233] = 0.0;
   out_998439548454101499[234] = 0.0;
   out_998439548454101499[235] = 0.0;
   out_998439548454101499[236] = 0.0;
   out_998439548454101499[237] = 0.0;
   out_998439548454101499[238] = 0.0;
   out_998439548454101499[239] = 0.0;
   out_998439548454101499[240] = 0.0;
   out_998439548454101499[241] = 0.0;
   out_998439548454101499[242] = 0.0;
   out_998439548454101499[243] = 0.0;
   out_998439548454101499[244] = 0.0;
   out_998439548454101499[245] = 0.0;
   out_998439548454101499[246] = 0.0;
   out_998439548454101499[247] = 1.0;
   out_998439548454101499[248] = 0.0;
   out_998439548454101499[249] = 0.0;
   out_998439548454101499[250] = 0.0;
   out_998439548454101499[251] = 0.0;
   out_998439548454101499[252] = 0.0;
   out_998439548454101499[253] = 0.0;
   out_998439548454101499[254] = 0.0;
   out_998439548454101499[255] = 0.0;
   out_998439548454101499[256] = 0.0;
   out_998439548454101499[257] = 0.0;
   out_998439548454101499[258] = 0.0;
   out_998439548454101499[259] = 0.0;
   out_998439548454101499[260] = 0.0;
   out_998439548454101499[261] = 0.0;
   out_998439548454101499[262] = 0.0;
   out_998439548454101499[263] = 0.0;
   out_998439548454101499[264] = 0.0;
   out_998439548454101499[265] = 0.0;
   out_998439548454101499[266] = 1.0;
   out_998439548454101499[267] = 0.0;
   out_998439548454101499[268] = 0.0;
   out_998439548454101499[269] = 0.0;
   out_998439548454101499[270] = 0.0;
   out_998439548454101499[271] = 0.0;
   out_998439548454101499[272] = 0.0;
   out_998439548454101499[273] = 0.0;
   out_998439548454101499[274] = 0.0;
   out_998439548454101499[275] = 0.0;
   out_998439548454101499[276] = 0.0;
   out_998439548454101499[277] = 0.0;
   out_998439548454101499[278] = 0.0;
   out_998439548454101499[279] = 0.0;
   out_998439548454101499[280] = 0.0;
   out_998439548454101499[281] = 0.0;
   out_998439548454101499[282] = 0.0;
   out_998439548454101499[283] = 0.0;
   out_998439548454101499[284] = 0.0;
   out_998439548454101499[285] = 1.0;
   out_998439548454101499[286] = 0.0;
   out_998439548454101499[287] = 0.0;
   out_998439548454101499[288] = 0.0;
   out_998439548454101499[289] = 0.0;
   out_998439548454101499[290] = 0.0;
   out_998439548454101499[291] = 0.0;
   out_998439548454101499[292] = 0.0;
   out_998439548454101499[293] = 0.0;
   out_998439548454101499[294] = 0.0;
   out_998439548454101499[295] = 0.0;
   out_998439548454101499[296] = 0.0;
   out_998439548454101499[297] = 0.0;
   out_998439548454101499[298] = 0.0;
   out_998439548454101499[299] = 0.0;
   out_998439548454101499[300] = 0.0;
   out_998439548454101499[301] = 0.0;
   out_998439548454101499[302] = 0.0;
   out_998439548454101499[303] = 0.0;
   out_998439548454101499[304] = 1.0;
   out_998439548454101499[305] = 0.0;
   out_998439548454101499[306] = 0.0;
   out_998439548454101499[307] = 0.0;
   out_998439548454101499[308] = 0.0;
   out_998439548454101499[309] = 0.0;
   out_998439548454101499[310] = 0.0;
   out_998439548454101499[311] = 0.0;
   out_998439548454101499[312] = 0.0;
   out_998439548454101499[313] = 0.0;
   out_998439548454101499[314] = 0.0;
   out_998439548454101499[315] = 0.0;
   out_998439548454101499[316] = 0.0;
   out_998439548454101499[317] = 0.0;
   out_998439548454101499[318] = 0.0;
   out_998439548454101499[319] = 0.0;
   out_998439548454101499[320] = 0.0;
   out_998439548454101499[321] = 0.0;
   out_998439548454101499[322] = 0.0;
   out_998439548454101499[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8602115666091671706) {
   out_8602115666091671706[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8602115666091671706[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8602115666091671706[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8602115666091671706[3] = dt*state[12] + state[3];
   out_8602115666091671706[4] = dt*state[13] + state[4];
   out_8602115666091671706[5] = dt*state[14] + state[5];
   out_8602115666091671706[6] = state[6];
   out_8602115666091671706[7] = state[7];
   out_8602115666091671706[8] = state[8];
   out_8602115666091671706[9] = state[9];
   out_8602115666091671706[10] = state[10];
   out_8602115666091671706[11] = state[11];
   out_8602115666091671706[12] = state[12];
   out_8602115666091671706[13] = state[13];
   out_8602115666091671706[14] = state[14];
   out_8602115666091671706[15] = state[15];
   out_8602115666091671706[16] = state[16];
   out_8602115666091671706[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2374776546689160763) {
   out_2374776546689160763[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2374776546689160763[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2374776546689160763[2] = 0;
   out_2374776546689160763[3] = 0;
   out_2374776546689160763[4] = 0;
   out_2374776546689160763[5] = 0;
   out_2374776546689160763[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2374776546689160763[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2374776546689160763[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2374776546689160763[9] = 0;
   out_2374776546689160763[10] = 0;
   out_2374776546689160763[11] = 0;
   out_2374776546689160763[12] = 0;
   out_2374776546689160763[13] = 0;
   out_2374776546689160763[14] = 0;
   out_2374776546689160763[15] = 0;
   out_2374776546689160763[16] = 0;
   out_2374776546689160763[17] = 0;
   out_2374776546689160763[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2374776546689160763[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2374776546689160763[20] = 0;
   out_2374776546689160763[21] = 0;
   out_2374776546689160763[22] = 0;
   out_2374776546689160763[23] = 0;
   out_2374776546689160763[24] = 0;
   out_2374776546689160763[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2374776546689160763[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2374776546689160763[27] = 0;
   out_2374776546689160763[28] = 0;
   out_2374776546689160763[29] = 0;
   out_2374776546689160763[30] = 0;
   out_2374776546689160763[31] = 0;
   out_2374776546689160763[32] = 0;
   out_2374776546689160763[33] = 0;
   out_2374776546689160763[34] = 0;
   out_2374776546689160763[35] = 0;
   out_2374776546689160763[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2374776546689160763[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2374776546689160763[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2374776546689160763[39] = 0;
   out_2374776546689160763[40] = 0;
   out_2374776546689160763[41] = 0;
   out_2374776546689160763[42] = 0;
   out_2374776546689160763[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2374776546689160763[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2374776546689160763[45] = 0;
   out_2374776546689160763[46] = 0;
   out_2374776546689160763[47] = 0;
   out_2374776546689160763[48] = 0;
   out_2374776546689160763[49] = 0;
   out_2374776546689160763[50] = 0;
   out_2374776546689160763[51] = 0;
   out_2374776546689160763[52] = 0;
   out_2374776546689160763[53] = 0;
   out_2374776546689160763[54] = 0;
   out_2374776546689160763[55] = 0;
   out_2374776546689160763[56] = 0;
   out_2374776546689160763[57] = 1;
   out_2374776546689160763[58] = 0;
   out_2374776546689160763[59] = 0;
   out_2374776546689160763[60] = 0;
   out_2374776546689160763[61] = 0;
   out_2374776546689160763[62] = 0;
   out_2374776546689160763[63] = 0;
   out_2374776546689160763[64] = 0;
   out_2374776546689160763[65] = 0;
   out_2374776546689160763[66] = dt;
   out_2374776546689160763[67] = 0;
   out_2374776546689160763[68] = 0;
   out_2374776546689160763[69] = 0;
   out_2374776546689160763[70] = 0;
   out_2374776546689160763[71] = 0;
   out_2374776546689160763[72] = 0;
   out_2374776546689160763[73] = 0;
   out_2374776546689160763[74] = 0;
   out_2374776546689160763[75] = 0;
   out_2374776546689160763[76] = 1;
   out_2374776546689160763[77] = 0;
   out_2374776546689160763[78] = 0;
   out_2374776546689160763[79] = 0;
   out_2374776546689160763[80] = 0;
   out_2374776546689160763[81] = 0;
   out_2374776546689160763[82] = 0;
   out_2374776546689160763[83] = 0;
   out_2374776546689160763[84] = 0;
   out_2374776546689160763[85] = dt;
   out_2374776546689160763[86] = 0;
   out_2374776546689160763[87] = 0;
   out_2374776546689160763[88] = 0;
   out_2374776546689160763[89] = 0;
   out_2374776546689160763[90] = 0;
   out_2374776546689160763[91] = 0;
   out_2374776546689160763[92] = 0;
   out_2374776546689160763[93] = 0;
   out_2374776546689160763[94] = 0;
   out_2374776546689160763[95] = 1;
   out_2374776546689160763[96] = 0;
   out_2374776546689160763[97] = 0;
   out_2374776546689160763[98] = 0;
   out_2374776546689160763[99] = 0;
   out_2374776546689160763[100] = 0;
   out_2374776546689160763[101] = 0;
   out_2374776546689160763[102] = 0;
   out_2374776546689160763[103] = 0;
   out_2374776546689160763[104] = dt;
   out_2374776546689160763[105] = 0;
   out_2374776546689160763[106] = 0;
   out_2374776546689160763[107] = 0;
   out_2374776546689160763[108] = 0;
   out_2374776546689160763[109] = 0;
   out_2374776546689160763[110] = 0;
   out_2374776546689160763[111] = 0;
   out_2374776546689160763[112] = 0;
   out_2374776546689160763[113] = 0;
   out_2374776546689160763[114] = 1;
   out_2374776546689160763[115] = 0;
   out_2374776546689160763[116] = 0;
   out_2374776546689160763[117] = 0;
   out_2374776546689160763[118] = 0;
   out_2374776546689160763[119] = 0;
   out_2374776546689160763[120] = 0;
   out_2374776546689160763[121] = 0;
   out_2374776546689160763[122] = 0;
   out_2374776546689160763[123] = 0;
   out_2374776546689160763[124] = 0;
   out_2374776546689160763[125] = 0;
   out_2374776546689160763[126] = 0;
   out_2374776546689160763[127] = 0;
   out_2374776546689160763[128] = 0;
   out_2374776546689160763[129] = 0;
   out_2374776546689160763[130] = 0;
   out_2374776546689160763[131] = 0;
   out_2374776546689160763[132] = 0;
   out_2374776546689160763[133] = 1;
   out_2374776546689160763[134] = 0;
   out_2374776546689160763[135] = 0;
   out_2374776546689160763[136] = 0;
   out_2374776546689160763[137] = 0;
   out_2374776546689160763[138] = 0;
   out_2374776546689160763[139] = 0;
   out_2374776546689160763[140] = 0;
   out_2374776546689160763[141] = 0;
   out_2374776546689160763[142] = 0;
   out_2374776546689160763[143] = 0;
   out_2374776546689160763[144] = 0;
   out_2374776546689160763[145] = 0;
   out_2374776546689160763[146] = 0;
   out_2374776546689160763[147] = 0;
   out_2374776546689160763[148] = 0;
   out_2374776546689160763[149] = 0;
   out_2374776546689160763[150] = 0;
   out_2374776546689160763[151] = 0;
   out_2374776546689160763[152] = 1;
   out_2374776546689160763[153] = 0;
   out_2374776546689160763[154] = 0;
   out_2374776546689160763[155] = 0;
   out_2374776546689160763[156] = 0;
   out_2374776546689160763[157] = 0;
   out_2374776546689160763[158] = 0;
   out_2374776546689160763[159] = 0;
   out_2374776546689160763[160] = 0;
   out_2374776546689160763[161] = 0;
   out_2374776546689160763[162] = 0;
   out_2374776546689160763[163] = 0;
   out_2374776546689160763[164] = 0;
   out_2374776546689160763[165] = 0;
   out_2374776546689160763[166] = 0;
   out_2374776546689160763[167] = 0;
   out_2374776546689160763[168] = 0;
   out_2374776546689160763[169] = 0;
   out_2374776546689160763[170] = 0;
   out_2374776546689160763[171] = 1;
   out_2374776546689160763[172] = 0;
   out_2374776546689160763[173] = 0;
   out_2374776546689160763[174] = 0;
   out_2374776546689160763[175] = 0;
   out_2374776546689160763[176] = 0;
   out_2374776546689160763[177] = 0;
   out_2374776546689160763[178] = 0;
   out_2374776546689160763[179] = 0;
   out_2374776546689160763[180] = 0;
   out_2374776546689160763[181] = 0;
   out_2374776546689160763[182] = 0;
   out_2374776546689160763[183] = 0;
   out_2374776546689160763[184] = 0;
   out_2374776546689160763[185] = 0;
   out_2374776546689160763[186] = 0;
   out_2374776546689160763[187] = 0;
   out_2374776546689160763[188] = 0;
   out_2374776546689160763[189] = 0;
   out_2374776546689160763[190] = 1;
   out_2374776546689160763[191] = 0;
   out_2374776546689160763[192] = 0;
   out_2374776546689160763[193] = 0;
   out_2374776546689160763[194] = 0;
   out_2374776546689160763[195] = 0;
   out_2374776546689160763[196] = 0;
   out_2374776546689160763[197] = 0;
   out_2374776546689160763[198] = 0;
   out_2374776546689160763[199] = 0;
   out_2374776546689160763[200] = 0;
   out_2374776546689160763[201] = 0;
   out_2374776546689160763[202] = 0;
   out_2374776546689160763[203] = 0;
   out_2374776546689160763[204] = 0;
   out_2374776546689160763[205] = 0;
   out_2374776546689160763[206] = 0;
   out_2374776546689160763[207] = 0;
   out_2374776546689160763[208] = 0;
   out_2374776546689160763[209] = 1;
   out_2374776546689160763[210] = 0;
   out_2374776546689160763[211] = 0;
   out_2374776546689160763[212] = 0;
   out_2374776546689160763[213] = 0;
   out_2374776546689160763[214] = 0;
   out_2374776546689160763[215] = 0;
   out_2374776546689160763[216] = 0;
   out_2374776546689160763[217] = 0;
   out_2374776546689160763[218] = 0;
   out_2374776546689160763[219] = 0;
   out_2374776546689160763[220] = 0;
   out_2374776546689160763[221] = 0;
   out_2374776546689160763[222] = 0;
   out_2374776546689160763[223] = 0;
   out_2374776546689160763[224] = 0;
   out_2374776546689160763[225] = 0;
   out_2374776546689160763[226] = 0;
   out_2374776546689160763[227] = 0;
   out_2374776546689160763[228] = 1;
   out_2374776546689160763[229] = 0;
   out_2374776546689160763[230] = 0;
   out_2374776546689160763[231] = 0;
   out_2374776546689160763[232] = 0;
   out_2374776546689160763[233] = 0;
   out_2374776546689160763[234] = 0;
   out_2374776546689160763[235] = 0;
   out_2374776546689160763[236] = 0;
   out_2374776546689160763[237] = 0;
   out_2374776546689160763[238] = 0;
   out_2374776546689160763[239] = 0;
   out_2374776546689160763[240] = 0;
   out_2374776546689160763[241] = 0;
   out_2374776546689160763[242] = 0;
   out_2374776546689160763[243] = 0;
   out_2374776546689160763[244] = 0;
   out_2374776546689160763[245] = 0;
   out_2374776546689160763[246] = 0;
   out_2374776546689160763[247] = 1;
   out_2374776546689160763[248] = 0;
   out_2374776546689160763[249] = 0;
   out_2374776546689160763[250] = 0;
   out_2374776546689160763[251] = 0;
   out_2374776546689160763[252] = 0;
   out_2374776546689160763[253] = 0;
   out_2374776546689160763[254] = 0;
   out_2374776546689160763[255] = 0;
   out_2374776546689160763[256] = 0;
   out_2374776546689160763[257] = 0;
   out_2374776546689160763[258] = 0;
   out_2374776546689160763[259] = 0;
   out_2374776546689160763[260] = 0;
   out_2374776546689160763[261] = 0;
   out_2374776546689160763[262] = 0;
   out_2374776546689160763[263] = 0;
   out_2374776546689160763[264] = 0;
   out_2374776546689160763[265] = 0;
   out_2374776546689160763[266] = 1;
   out_2374776546689160763[267] = 0;
   out_2374776546689160763[268] = 0;
   out_2374776546689160763[269] = 0;
   out_2374776546689160763[270] = 0;
   out_2374776546689160763[271] = 0;
   out_2374776546689160763[272] = 0;
   out_2374776546689160763[273] = 0;
   out_2374776546689160763[274] = 0;
   out_2374776546689160763[275] = 0;
   out_2374776546689160763[276] = 0;
   out_2374776546689160763[277] = 0;
   out_2374776546689160763[278] = 0;
   out_2374776546689160763[279] = 0;
   out_2374776546689160763[280] = 0;
   out_2374776546689160763[281] = 0;
   out_2374776546689160763[282] = 0;
   out_2374776546689160763[283] = 0;
   out_2374776546689160763[284] = 0;
   out_2374776546689160763[285] = 1;
   out_2374776546689160763[286] = 0;
   out_2374776546689160763[287] = 0;
   out_2374776546689160763[288] = 0;
   out_2374776546689160763[289] = 0;
   out_2374776546689160763[290] = 0;
   out_2374776546689160763[291] = 0;
   out_2374776546689160763[292] = 0;
   out_2374776546689160763[293] = 0;
   out_2374776546689160763[294] = 0;
   out_2374776546689160763[295] = 0;
   out_2374776546689160763[296] = 0;
   out_2374776546689160763[297] = 0;
   out_2374776546689160763[298] = 0;
   out_2374776546689160763[299] = 0;
   out_2374776546689160763[300] = 0;
   out_2374776546689160763[301] = 0;
   out_2374776546689160763[302] = 0;
   out_2374776546689160763[303] = 0;
   out_2374776546689160763[304] = 1;
   out_2374776546689160763[305] = 0;
   out_2374776546689160763[306] = 0;
   out_2374776546689160763[307] = 0;
   out_2374776546689160763[308] = 0;
   out_2374776546689160763[309] = 0;
   out_2374776546689160763[310] = 0;
   out_2374776546689160763[311] = 0;
   out_2374776546689160763[312] = 0;
   out_2374776546689160763[313] = 0;
   out_2374776546689160763[314] = 0;
   out_2374776546689160763[315] = 0;
   out_2374776546689160763[316] = 0;
   out_2374776546689160763[317] = 0;
   out_2374776546689160763[318] = 0;
   out_2374776546689160763[319] = 0;
   out_2374776546689160763[320] = 0;
   out_2374776546689160763[321] = 0;
   out_2374776546689160763[322] = 0;
   out_2374776546689160763[323] = 1;
}
void h_4(double *state, double *unused, double *out_3610197400448725788) {
   out_3610197400448725788[0] = state[6] + state[9];
   out_3610197400448725788[1] = state[7] + state[10];
   out_3610197400448725788[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3341399300644519511) {
   out_3341399300644519511[0] = 0;
   out_3341399300644519511[1] = 0;
   out_3341399300644519511[2] = 0;
   out_3341399300644519511[3] = 0;
   out_3341399300644519511[4] = 0;
   out_3341399300644519511[5] = 0;
   out_3341399300644519511[6] = 1;
   out_3341399300644519511[7] = 0;
   out_3341399300644519511[8] = 0;
   out_3341399300644519511[9] = 1;
   out_3341399300644519511[10] = 0;
   out_3341399300644519511[11] = 0;
   out_3341399300644519511[12] = 0;
   out_3341399300644519511[13] = 0;
   out_3341399300644519511[14] = 0;
   out_3341399300644519511[15] = 0;
   out_3341399300644519511[16] = 0;
   out_3341399300644519511[17] = 0;
   out_3341399300644519511[18] = 0;
   out_3341399300644519511[19] = 0;
   out_3341399300644519511[20] = 0;
   out_3341399300644519511[21] = 0;
   out_3341399300644519511[22] = 0;
   out_3341399300644519511[23] = 0;
   out_3341399300644519511[24] = 0;
   out_3341399300644519511[25] = 1;
   out_3341399300644519511[26] = 0;
   out_3341399300644519511[27] = 0;
   out_3341399300644519511[28] = 1;
   out_3341399300644519511[29] = 0;
   out_3341399300644519511[30] = 0;
   out_3341399300644519511[31] = 0;
   out_3341399300644519511[32] = 0;
   out_3341399300644519511[33] = 0;
   out_3341399300644519511[34] = 0;
   out_3341399300644519511[35] = 0;
   out_3341399300644519511[36] = 0;
   out_3341399300644519511[37] = 0;
   out_3341399300644519511[38] = 0;
   out_3341399300644519511[39] = 0;
   out_3341399300644519511[40] = 0;
   out_3341399300644519511[41] = 0;
   out_3341399300644519511[42] = 0;
   out_3341399300644519511[43] = 0;
   out_3341399300644519511[44] = 1;
   out_3341399300644519511[45] = 0;
   out_3341399300644519511[46] = 0;
   out_3341399300644519511[47] = 1;
   out_3341399300644519511[48] = 0;
   out_3341399300644519511[49] = 0;
   out_3341399300644519511[50] = 0;
   out_3341399300644519511[51] = 0;
   out_3341399300644519511[52] = 0;
   out_3341399300644519511[53] = 0;
}
void h_10(double *state, double *unused, double *out_7074632649049224399) {
   out_7074632649049224399[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7074632649049224399[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7074632649049224399[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2352139524921342803) {
   out_2352139524921342803[0] = 0;
   out_2352139524921342803[1] = 9.8100000000000005*cos(state[1]);
   out_2352139524921342803[2] = 0;
   out_2352139524921342803[3] = 0;
   out_2352139524921342803[4] = -state[8];
   out_2352139524921342803[5] = state[7];
   out_2352139524921342803[6] = 0;
   out_2352139524921342803[7] = state[5];
   out_2352139524921342803[8] = -state[4];
   out_2352139524921342803[9] = 0;
   out_2352139524921342803[10] = 0;
   out_2352139524921342803[11] = 0;
   out_2352139524921342803[12] = 1;
   out_2352139524921342803[13] = 0;
   out_2352139524921342803[14] = 0;
   out_2352139524921342803[15] = 1;
   out_2352139524921342803[16] = 0;
   out_2352139524921342803[17] = 0;
   out_2352139524921342803[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2352139524921342803[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2352139524921342803[20] = 0;
   out_2352139524921342803[21] = state[8];
   out_2352139524921342803[22] = 0;
   out_2352139524921342803[23] = -state[6];
   out_2352139524921342803[24] = -state[5];
   out_2352139524921342803[25] = 0;
   out_2352139524921342803[26] = state[3];
   out_2352139524921342803[27] = 0;
   out_2352139524921342803[28] = 0;
   out_2352139524921342803[29] = 0;
   out_2352139524921342803[30] = 0;
   out_2352139524921342803[31] = 1;
   out_2352139524921342803[32] = 0;
   out_2352139524921342803[33] = 0;
   out_2352139524921342803[34] = 1;
   out_2352139524921342803[35] = 0;
   out_2352139524921342803[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2352139524921342803[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2352139524921342803[38] = 0;
   out_2352139524921342803[39] = -state[7];
   out_2352139524921342803[40] = state[6];
   out_2352139524921342803[41] = 0;
   out_2352139524921342803[42] = state[4];
   out_2352139524921342803[43] = -state[3];
   out_2352139524921342803[44] = 0;
   out_2352139524921342803[45] = 0;
   out_2352139524921342803[46] = 0;
   out_2352139524921342803[47] = 0;
   out_2352139524921342803[48] = 0;
   out_2352139524921342803[49] = 0;
   out_2352139524921342803[50] = 1;
   out_2352139524921342803[51] = 0;
   out_2352139524921342803[52] = 0;
   out_2352139524921342803[53] = 1;
}
void h_13(double *state, double *unused, double *out_4134075991249929964) {
   out_4134075991249929964[0] = state[3];
   out_4134075991249929964[1] = state[4];
   out_4134075991249929964[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7494713564748331176) {
   out_7494713564748331176[0] = 0;
   out_7494713564748331176[1] = 0;
   out_7494713564748331176[2] = 0;
   out_7494713564748331176[3] = 1;
   out_7494713564748331176[4] = 0;
   out_7494713564748331176[5] = 0;
   out_7494713564748331176[6] = 0;
   out_7494713564748331176[7] = 0;
   out_7494713564748331176[8] = 0;
   out_7494713564748331176[9] = 0;
   out_7494713564748331176[10] = 0;
   out_7494713564748331176[11] = 0;
   out_7494713564748331176[12] = 0;
   out_7494713564748331176[13] = 0;
   out_7494713564748331176[14] = 0;
   out_7494713564748331176[15] = 0;
   out_7494713564748331176[16] = 0;
   out_7494713564748331176[17] = 0;
   out_7494713564748331176[18] = 0;
   out_7494713564748331176[19] = 0;
   out_7494713564748331176[20] = 0;
   out_7494713564748331176[21] = 0;
   out_7494713564748331176[22] = 1;
   out_7494713564748331176[23] = 0;
   out_7494713564748331176[24] = 0;
   out_7494713564748331176[25] = 0;
   out_7494713564748331176[26] = 0;
   out_7494713564748331176[27] = 0;
   out_7494713564748331176[28] = 0;
   out_7494713564748331176[29] = 0;
   out_7494713564748331176[30] = 0;
   out_7494713564748331176[31] = 0;
   out_7494713564748331176[32] = 0;
   out_7494713564748331176[33] = 0;
   out_7494713564748331176[34] = 0;
   out_7494713564748331176[35] = 0;
   out_7494713564748331176[36] = 0;
   out_7494713564748331176[37] = 0;
   out_7494713564748331176[38] = 0;
   out_7494713564748331176[39] = 0;
   out_7494713564748331176[40] = 0;
   out_7494713564748331176[41] = 1;
   out_7494713564748331176[42] = 0;
   out_7494713564748331176[43] = 0;
   out_7494713564748331176[44] = 0;
   out_7494713564748331176[45] = 0;
   out_7494713564748331176[46] = 0;
   out_7494713564748331176[47] = 0;
   out_7494713564748331176[48] = 0;
   out_7494713564748331176[49] = 0;
   out_7494713564748331176[50] = 0;
   out_7494713564748331176[51] = 0;
   out_7494713564748331176[52] = 0;
   out_7494713564748331176[53] = 0;
}
void h_14(double *state, double *unused, double *out_7088367226319057364) {
   out_7088367226319057364[0] = state[6];
   out_7088367226319057364[1] = state[7];
   out_7088367226319057364[2] = state[8];
}
void H_14(double *state, double *unused, double *out_258610868349147215) {
   out_258610868349147215[0] = 0;
   out_258610868349147215[1] = 0;
   out_258610868349147215[2] = 0;
   out_258610868349147215[3] = 0;
   out_258610868349147215[4] = 0;
   out_258610868349147215[5] = 0;
   out_258610868349147215[6] = 1;
   out_258610868349147215[7] = 0;
   out_258610868349147215[8] = 0;
   out_258610868349147215[9] = 0;
   out_258610868349147215[10] = 0;
   out_258610868349147215[11] = 0;
   out_258610868349147215[12] = 0;
   out_258610868349147215[13] = 0;
   out_258610868349147215[14] = 0;
   out_258610868349147215[15] = 0;
   out_258610868349147215[16] = 0;
   out_258610868349147215[17] = 0;
   out_258610868349147215[18] = 0;
   out_258610868349147215[19] = 0;
   out_258610868349147215[20] = 0;
   out_258610868349147215[21] = 0;
   out_258610868349147215[22] = 0;
   out_258610868349147215[23] = 0;
   out_258610868349147215[24] = 0;
   out_258610868349147215[25] = 1;
   out_258610868349147215[26] = 0;
   out_258610868349147215[27] = 0;
   out_258610868349147215[28] = 0;
   out_258610868349147215[29] = 0;
   out_258610868349147215[30] = 0;
   out_258610868349147215[31] = 0;
   out_258610868349147215[32] = 0;
   out_258610868349147215[33] = 0;
   out_258610868349147215[34] = 0;
   out_258610868349147215[35] = 0;
   out_258610868349147215[36] = 0;
   out_258610868349147215[37] = 0;
   out_258610868349147215[38] = 0;
   out_258610868349147215[39] = 0;
   out_258610868349147215[40] = 0;
   out_258610868349147215[41] = 0;
   out_258610868349147215[42] = 0;
   out_258610868349147215[43] = 0;
   out_258610868349147215[44] = 1;
   out_258610868349147215[45] = 0;
   out_258610868349147215[46] = 0;
   out_258610868349147215[47] = 0;
   out_258610868349147215[48] = 0;
   out_258610868349147215[49] = 0;
   out_258610868349147215[50] = 0;
   out_258610868349147215[51] = 0;
   out_258610868349147215[52] = 0;
   out_258610868349147215[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4890483987619646593) {
  err_fun(nom_x, delta_x, out_4890483987619646593);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8601483282449025419) {
  inv_err_fun(nom_x, true_x, out_8601483282449025419);
}
void pose_H_mod_fun(double *state, double *out_998439548454101499) {
  H_mod_fun(state, out_998439548454101499);
}
void pose_f_fun(double *state, double dt, double *out_8602115666091671706) {
  f_fun(state,  dt, out_8602115666091671706);
}
void pose_F_fun(double *state, double dt, double *out_2374776546689160763) {
  F_fun(state,  dt, out_2374776546689160763);
}
void pose_h_4(double *state, double *unused, double *out_3610197400448725788) {
  h_4(state, unused, out_3610197400448725788);
}
void pose_H_4(double *state, double *unused, double *out_3341399300644519511) {
  H_4(state, unused, out_3341399300644519511);
}
void pose_h_10(double *state, double *unused, double *out_7074632649049224399) {
  h_10(state, unused, out_7074632649049224399);
}
void pose_H_10(double *state, double *unused, double *out_2352139524921342803) {
  H_10(state, unused, out_2352139524921342803);
}
void pose_h_13(double *state, double *unused, double *out_4134075991249929964) {
  h_13(state, unused, out_4134075991249929964);
}
void pose_H_13(double *state, double *unused, double *out_7494713564748331176) {
  H_13(state, unused, out_7494713564748331176);
}
void pose_h_14(double *state, double *unused, double *out_7088367226319057364) {
  h_14(state, unused, out_7088367226319057364);
}
void pose_H_14(double *state, double *unused, double *out_258610868349147215) {
  H_14(state, unused, out_258610868349147215);
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
