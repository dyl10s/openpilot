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
void err_fun(double *nom_x, double *delta_x, double *out_9044617002367965712) {
   out_9044617002367965712[0] = delta_x[0] + nom_x[0];
   out_9044617002367965712[1] = delta_x[1] + nom_x[1];
   out_9044617002367965712[2] = delta_x[2] + nom_x[2];
   out_9044617002367965712[3] = delta_x[3] + nom_x[3];
   out_9044617002367965712[4] = delta_x[4] + nom_x[4];
   out_9044617002367965712[5] = delta_x[5] + nom_x[5];
   out_9044617002367965712[6] = delta_x[6] + nom_x[6];
   out_9044617002367965712[7] = delta_x[7] + nom_x[7];
   out_9044617002367965712[8] = delta_x[8] + nom_x[8];
   out_9044617002367965712[9] = delta_x[9] + nom_x[9];
   out_9044617002367965712[10] = delta_x[10] + nom_x[10];
   out_9044617002367965712[11] = delta_x[11] + nom_x[11];
   out_9044617002367965712[12] = delta_x[12] + nom_x[12];
   out_9044617002367965712[13] = delta_x[13] + nom_x[13];
   out_9044617002367965712[14] = delta_x[14] + nom_x[14];
   out_9044617002367965712[15] = delta_x[15] + nom_x[15];
   out_9044617002367965712[16] = delta_x[16] + nom_x[16];
   out_9044617002367965712[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2986388781113821274) {
   out_2986388781113821274[0] = -nom_x[0] + true_x[0];
   out_2986388781113821274[1] = -nom_x[1] + true_x[1];
   out_2986388781113821274[2] = -nom_x[2] + true_x[2];
   out_2986388781113821274[3] = -nom_x[3] + true_x[3];
   out_2986388781113821274[4] = -nom_x[4] + true_x[4];
   out_2986388781113821274[5] = -nom_x[5] + true_x[5];
   out_2986388781113821274[6] = -nom_x[6] + true_x[6];
   out_2986388781113821274[7] = -nom_x[7] + true_x[7];
   out_2986388781113821274[8] = -nom_x[8] + true_x[8];
   out_2986388781113821274[9] = -nom_x[9] + true_x[9];
   out_2986388781113821274[10] = -nom_x[10] + true_x[10];
   out_2986388781113821274[11] = -nom_x[11] + true_x[11];
   out_2986388781113821274[12] = -nom_x[12] + true_x[12];
   out_2986388781113821274[13] = -nom_x[13] + true_x[13];
   out_2986388781113821274[14] = -nom_x[14] + true_x[14];
   out_2986388781113821274[15] = -nom_x[15] + true_x[15];
   out_2986388781113821274[16] = -nom_x[16] + true_x[16];
   out_2986388781113821274[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5449976102936300367) {
   out_5449976102936300367[0] = 1.0;
   out_5449976102936300367[1] = 0.0;
   out_5449976102936300367[2] = 0.0;
   out_5449976102936300367[3] = 0.0;
   out_5449976102936300367[4] = 0.0;
   out_5449976102936300367[5] = 0.0;
   out_5449976102936300367[6] = 0.0;
   out_5449976102936300367[7] = 0.0;
   out_5449976102936300367[8] = 0.0;
   out_5449976102936300367[9] = 0.0;
   out_5449976102936300367[10] = 0.0;
   out_5449976102936300367[11] = 0.0;
   out_5449976102936300367[12] = 0.0;
   out_5449976102936300367[13] = 0.0;
   out_5449976102936300367[14] = 0.0;
   out_5449976102936300367[15] = 0.0;
   out_5449976102936300367[16] = 0.0;
   out_5449976102936300367[17] = 0.0;
   out_5449976102936300367[18] = 0.0;
   out_5449976102936300367[19] = 1.0;
   out_5449976102936300367[20] = 0.0;
   out_5449976102936300367[21] = 0.0;
   out_5449976102936300367[22] = 0.0;
   out_5449976102936300367[23] = 0.0;
   out_5449976102936300367[24] = 0.0;
   out_5449976102936300367[25] = 0.0;
   out_5449976102936300367[26] = 0.0;
   out_5449976102936300367[27] = 0.0;
   out_5449976102936300367[28] = 0.0;
   out_5449976102936300367[29] = 0.0;
   out_5449976102936300367[30] = 0.0;
   out_5449976102936300367[31] = 0.0;
   out_5449976102936300367[32] = 0.0;
   out_5449976102936300367[33] = 0.0;
   out_5449976102936300367[34] = 0.0;
   out_5449976102936300367[35] = 0.0;
   out_5449976102936300367[36] = 0.0;
   out_5449976102936300367[37] = 0.0;
   out_5449976102936300367[38] = 1.0;
   out_5449976102936300367[39] = 0.0;
   out_5449976102936300367[40] = 0.0;
   out_5449976102936300367[41] = 0.0;
   out_5449976102936300367[42] = 0.0;
   out_5449976102936300367[43] = 0.0;
   out_5449976102936300367[44] = 0.0;
   out_5449976102936300367[45] = 0.0;
   out_5449976102936300367[46] = 0.0;
   out_5449976102936300367[47] = 0.0;
   out_5449976102936300367[48] = 0.0;
   out_5449976102936300367[49] = 0.0;
   out_5449976102936300367[50] = 0.0;
   out_5449976102936300367[51] = 0.0;
   out_5449976102936300367[52] = 0.0;
   out_5449976102936300367[53] = 0.0;
   out_5449976102936300367[54] = 0.0;
   out_5449976102936300367[55] = 0.0;
   out_5449976102936300367[56] = 0.0;
   out_5449976102936300367[57] = 1.0;
   out_5449976102936300367[58] = 0.0;
   out_5449976102936300367[59] = 0.0;
   out_5449976102936300367[60] = 0.0;
   out_5449976102936300367[61] = 0.0;
   out_5449976102936300367[62] = 0.0;
   out_5449976102936300367[63] = 0.0;
   out_5449976102936300367[64] = 0.0;
   out_5449976102936300367[65] = 0.0;
   out_5449976102936300367[66] = 0.0;
   out_5449976102936300367[67] = 0.0;
   out_5449976102936300367[68] = 0.0;
   out_5449976102936300367[69] = 0.0;
   out_5449976102936300367[70] = 0.0;
   out_5449976102936300367[71] = 0.0;
   out_5449976102936300367[72] = 0.0;
   out_5449976102936300367[73] = 0.0;
   out_5449976102936300367[74] = 0.0;
   out_5449976102936300367[75] = 0.0;
   out_5449976102936300367[76] = 1.0;
   out_5449976102936300367[77] = 0.0;
   out_5449976102936300367[78] = 0.0;
   out_5449976102936300367[79] = 0.0;
   out_5449976102936300367[80] = 0.0;
   out_5449976102936300367[81] = 0.0;
   out_5449976102936300367[82] = 0.0;
   out_5449976102936300367[83] = 0.0;
   out_5449976102936300367[84] = 0.0;
   out_5449976102936300367[85] = 0.0;
   out_5449976102936300367[86] = 0.0;
   out_5449976102936300367[87] = 0.0;
   out_5449976102936300367[88] = 0.0;
   out_5449976102936300367[89] = 0.0;
   out_5449976102936300367[90] = 0.0;
   out_5449976102936300367[91] = 0.0;
   out_5449976102936300367[92] = 0.0;
   out_5449976102936300367[93] = 0.0;
   out_5449976102936300367[94] = 0.0;
   out_5449976102936300367[95] = 1.0;
   out_5449976102936300367[96] = 0.0;
   out_5449976102936300367[97] = 0.0;
   out_5449976102936300367[98] = 0.0;
   out_5449976102936300367[99] = 0.0;
   out_5449976102936300367[100] = 0.0;
   out_5449976102936300367[101] = 0.0;
   out_5449976102936300367[102] = 0.0;
   out_5449976102936300367[103] = 0.0;
   out_5449976102936300367[104] = 0.0;
   out_5449976102936300367[105] = 0.0;
   out_5449976102936300367[106] = 0.0;
   out_5449976102936300367[107] = 0.0;
   out_5449976102936300367[108] = 0.0;
   out_5449976102936300367[109] = 0.0;
   out_5449976102936300367[110] = 0.0;
   out_5449976102936300367[111] = 0.0;
   out_5449976102936300367[112] = 0.0;
   out_5449976102936300367[113] = 0.0;
   out_5449976102936300367[114] = 1.0;
   out_5449976102936300367[115] = 0.0;
   out_5449976102936300367[116] = 0.0;
   out_5449976102936300367[117] = 0.0;
   out_5449976102936300367[118] = 0.0;
   out_5449976102936300367[119] = 0.0;
   out_5449976102936300367[120] = 0.0;
   out_5449976102936300367[121] = 0.0;
   out_5449976102936300367[122] = 0.0;
   out_5449976102936300367[123] = 0.0;
   out_5449976102936300367[124] = 0.0;
   out_5449976102936300367[125] = 0.0;
   out_5449976102936300367[126] = 0.0;
   out_5449976102936300367[127] = 0.0;
   out_5449976102936300367[128] = 0.0;
   out_5449976102936300367[129] = 0.0;
   out_5449976102936300367[130] = 0.0;
   out_5449976102936300367[131] = 0.0;
   out_5449976102936300367[132] = 0.0;
   out_5449976102936300367[133] = 1.0;
   out_5449976102936300367[134] = 0.0;
   out_5449976102936300367[135] = 0.0;
   out_5449976102936300367[136] = 0.0;
   out_5449976102936300367[137] = 0.0;
   out_5449976102936300367[138] = 0.0;
   out_5449976102936300367[139] = 0.0;
   out_5449976102936300367[140] = 0.0;
   out_5449976102936300367[141] = 0.0;
   out_5449976102936300367[142] = 0.0;
   out_5449976102936300367[143] = 0.0;
   out_5449976102936300367[144] = 0.0;
   out_5449976102936300367[145] = 0.0;
   out_5449976102936300367[146] = 0.0;
   out_5449976102936300367[147] = 0.0;
   out_5449976102936300367[148] = 0.0;
   out_5449976102936300367[149] = 0.0;
   out_5449976102936300367[150] = 0.0;
   out_5449976102936300367[151] = 0.0;
   out_5449976102936300367[152] = 1.0;
   out_5449976102936300367[153] = 0.0;
   out_5449976102936300367[154] = 0.0;
   out_5449976102936300367[155] = 0.0;
   out_5449976102936300367[156] = 0.0;
   out_5449976102936300367[157] = 0.0;
   out_5449976102936300367[158] = 0.0;
   out_5449976102936300367[159] = 0.0;
   out_5449976102936300367[160] = 0.0;
   out_5449976102936300367[161] = 0.0;
   out_5449976102936300367[162] = 0.0;
   out_5449976102936300367[163] = 0.0;
   out_5449976102936300367[164] = 0.0;
   out_5449976102936300367[165] = 0.0;
   out_5449976102936300367[166] = 0.0;
   out_5449976102936300367[167] = 0.0;
   out_5449976102936300367[168] = 0.0;
   out_5449976102936300367[169] = 0.0;
   out_5449976102936300367[170] = 0.0;
   out_5449976102936300367[171] = 1.0;
   out_5449976102936300367[172] = 0.0;
   out_5449976102936300367[173] = 0.0;
   out_5449976102936300367[174] = 0.0;
   out_5449976102936300367[175] = 0.0;
   out_5449976102936300367[176] = 0.0;
   out_5449976102936300367[177] = 0.0;
   out_5449976102936300367[178] = 0.0;
   out_5449976102936300367[179] = 0.0;
   out_5449976102936300367[180] = 0.0;
   out_5449976102936300367[181] = 0.0;
   out_5449976102936300367[182] = 0.0;
   out_5449976102936300367[183] = 0.0;
   out_5449976102936300367[184] = 0.0;
   out_5449976102936300367[185] = 0.0;
   out_5449976102936300367[186] = 0.0;
   out_5449976102936300367[187] = 0.0;
   out_5449976102936300367[188] = 0.0;
   out_5449976102936300367[189] = 0.0;
   out_5449976102936300367[190] = 1.0;
   out_5449976102936300367[191] = 0.0;
   out_5449976102936300367[192] = 0.0;
   out_5449976102936300367[193] = 0.0;
   out_5449976102936300367[194] = 0.0;
   out_5449976102936300367[195] = 0.0;
   out_5449976102936300367[196] = 0.0;
   out_5449976102936300367[197] = 0.0;
   out_5449976102936300367[198] = 0.0;
   out_5449976102936300367[199] = 0.0;
   out_5449976102936300367[200] = 0.0;
   out_5449976102936300367[201] = 0.0;
   out_5449976102936300367[202] = 0.0;
   out_5449976102936300367[203] = 0.0;
   out_5449976102936300367[204] = 0.0;
   out_5449976102936300367[205] = 0.0;
   out_5449976102936300367[206] = 0.0;
   out_5449976102936300367[207] = 0.0;
   out_5449976102936300367[208] = 0.0;
   out_5449976102936300367[209] = 1.0;
   out_5449976102936300367[210] = 0.0;
   out_5449976102936300367[211] = 0.0;
   out_5449976102936300367[212] = 0.0;
   out_5449976102936300367[213] = 0.0;
   out_5449976102936300367[214] = 0.0;
   out_5449976102936300367[215] = 0.0;
   out_5449976102936300367[216] = 0.0;
   out_5449976102936300367[217] = 0.0;
   out_5449976102936300367[218] = 0.0;
   out_5449976102936300367[219] = 0.0;
   out_5449976102936300367[220] = 0.0;
   out_5449976102936300367[221] = 0.0;
   out_5449976102936300367[222] = 0.0;
   out_5449976102936300367[223] = 0.0;
   out_5449976102936300367[224] = 0.0;
   out_5449976102936300367[225] = 0.0;
   out_5449976102936300367[226] = 0.0;
   out_5449976102936300367[227] = 0.0;
   out_5449976102936300367[228] = 1.0;
   out_5449976102936300367[229] = 0.0;
   out_5449976102936300367[230] = 0.0;
   out_5449976102936300367[231] = 0.0;
   out_5449976102936300367[232] = 0.0;
   out_5449976102936300367[233] = 0.0;
   out_5449976102936300367[234] = 0.0;
   out_5449976102936300367[235] = 0.0;
   out_5449976102936300367[236] = 0.0;
   out_5449976102936300367[237] = 0.0;
   out_5449976102936300367[238] = 0.0;
   out_5449976102936300367[239] = 0.0;
   out_5449976102936300367[240] = 0.0;
   out_5449976102936300367[241] = 0.0;
   out_5449976102936300367[242] = 0.0;
   out_5449976102936300367[243] = 0.0;
   out_5449976102936300367[244] = 0.0;
   out_5449976102936300367[245] = 0.0;
   out_5449976102936300367[246] = 0.0;
   out_5449976102936300367[247] = 1.0;
   out_5449976102936300367[248] = 0.0;
   out_5449976102936300367[249] = 0.0;
   out_5449976102936300367[250] = 0.0;
   out_5449976102936300367[251] = 0.0;
   out_5449976102936300367[252] = 0.0;
   out_5449976102936300367[253] = 0.0;
   out_5449976102936300367[254] = 0.0;
   out_5449976102936300367[255] = 0.0;
   out_5449976102936300367[256] = 0.0;
   out_5449976102936300367[257] = 0.0;
   out_5449976102936300367[258] = 0.0;
   out_5449976102936300367[259] = 0.0;
   out_5449976102936300367[260] = 0.0;
   out_5449976102936300367[261] = 0.0;
   out_5449976102936300367[262] = 0.0;
   out_5449976102936300367[263] = 0.0;
   out_5449976102936300367[264] = 0.0;
   out_5449976102936300367[265] = 0.0;
   out_5449976102936300367[266] = 1.0;
   out_5449976102936300367[267] = 0.0;
   out_5449976102936300367[268] = 0.0;
   out_5449976102936300367[269] = 0.0;
   out_5449976102936300367[270] = 0.0;
   out_5449976102936300367[271] = 0.0;
   out_5449976102936300367[272] = 0.0;
   out_5449976102936300367[273] = 0.0;
   out_5449976102936300367[274] = 0.0;
   out_5449976102936300367[275] = 0.0;
   out_5449976102936300367[276] = 0.0;
   out_5449976102936300367[277] = 0.0;
   out_5449976102936300367[278] = 0.0;
   out_5449976102936300367[279] = 0.0;
   out_5449976102936300367[280] = 0.0;
   out_5449976102936300367[281] = 0.0;
   out_5449976102936300367[282] = 0.0;
   out_5449976102936300367[283] = 0.0;
   out_5449976102936300367[284] = 0.0;
   out_5449976102936300367[285] = 1.0;
   out_5449976102936300367[286] = 0.0;
   out_5449976102936300367[287] = 0.0;
   out_5449976102936300367[288] = 0.0;
   out_5449976102936300367[289] = 0.0;
   out_5449976102936300367[290] = 0.0;
   out_5449976102936300367[291] = 0.0;
   out_5449976102936300367[292] = 0.0;
   out_5449976102936300367[293] = 0.0;
   out_5449976102936300367[294] = 0.0;
   out_5449976102936300367[295] = 0.0;
   out_5449976102936300367[296] = 0.0;
   out_5449976102936300367[297] = 0.0;
   out_5449976102936300367[298] = 0.0;
   out_5449976102936300367[299] = 0.0;
   out_5449976102936300367[300] = 0.0;
   out_5449976102936300367[301] = 0.0;
   out_5449976102936300367[302] = 0.0;
   out_5449976102936300367[303] = 0.0;
   out_5449976102936300367[304] = 1.0;
   out_5449976102936300367[305] = 0.0;
   out_5449976102936300367[306] = 0.0;
   out_5449976102936300367[307] = 0.0;
   out_5449976102936300367[308] = 0.0;
   out_5449976102936300367[309] = 0.0;
   out_5449976102936300367[310] = 0.0;
   out_5449976102936300367[311] = 0.0;
   out_5449976102936300367[312] = 0.0;
   out_5449976102936300367[313] = 0.0;
   out_5449976102936300367[314] = 0.0;
   out_5449976102936300367[315] = 0.0;
   out_5449976102936300367[316] = 0.0;
   out_5449976102936300367[317] = 0.0;
   out_5449976102936300367[318] = 0.0;
   out_5449976102936300367[319] = 0.0;
   out_5449976102936300367[320] = 0.0;
   out_5449976102936300367[321] = 0.0;
   out_5449976102936300367[322] = 0.0;
   out_5449976102936300367[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2001314774583974236) {
   out_2001314774583974236[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2001314774583974236[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2001314774583974236[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2001314774583974236[3] = dt*state[12] + state[3];
   out_2001314774583974236[4] = dt*state[13] + state[4];
   out_2001314774583974236[5] = dt*state[14] + state[5];
   out_2001314774583974236[6] = state[6];
   out_2001314774583974236[7] = state[7];
   out_2001314774583974236[8] = state[8];
   out_2001314774583974236[9] = state[9];
   out_2001314774583974236[10] = state[10];
   out_2001314774583974236[11] = state[11];
   out_2001314774583974236[12] = state[12];
   out_2001314774583974236[13] = state[13];
   out_2001314774583974236[14] = state[14];
   out_2001314774583974236[15] = state[15];
   out_2001314774583974236[16] = state[16];
   out_2001314774583974236[17] = state[17];
}
void F_fun(double *state, double dt, double *out_173210708380746968) {
   out_173210708380746968[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_173210708380746968[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_173210708380746968[2] = 0;
   out_173210708380746968[3] = 0;
   out_173210708380746968[4] = 0;
   out_173210708380746968[5] = 0;
   out_173210708380746968[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_173210708380746968[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_173210708380746968[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_173210708380746968[9] = 0;
   out_173210708380746968[10] = 0;
   out_173210708380746968[11] = 0;
   out_173210708380746968[12] = 0;
   out_173210708380746968[13] = 0;
   out_173210708380746968[14] = 0;
   out_173210708380746968[15] = 0;
   out_173210708380746968[16] = 0;
   out_173210708380746968[17] = 0;
   out_173210708380746968[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_173210708380746968[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_173210708380746968[20] = 0;
   out_173210708380746968[21] = 0;
   out_173210708380746968[22] = 0;
   out_173210708380746968[23] = 0;
   out_173210708380746968[24] = 0;
   out_173210708380746968[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_173210708380746968[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_173210708380746968[27] = 0;
   out_173210708380746968[28] = 0;
   out_173210708380746968[29] = 0;
   out_173210708380746968[30] = 0;
   out_173210708380746968[31] = 0;
   out_173210708380746968[32] = 0;
   out_173210708380746968[33] = 0;
   out_173210708380746968[34] = 0;
   out_173210708380746968[35] = 0;
   out_173210708380746968[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_173210708380746968[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_173210708380746968[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_173210708380746968[39] = 0;
   out_173210708380746968[40] = 0;
   out_173210708380746968[41] = 0;
   out_173210708380746968[42] = 0;
   out_173210708380746968[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_173210708380746968[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_173210708380746968[45] = 0;
   out_173210708380746968[46] = 0;
   out_173210708380746968[47] = 0;
   out_173210708380746968[48] = 0;
   out_173210708380746968[49] = 0;
   out_173210708380746968[50] = 0;
   out_173210708380746968[51] = 0;
   out_173210708380746968[52] = 0;
   out_173210708380746968[53] = 0;
   out_173210708380746968[54] = 0;
   out_173210708380746968[55] = 0;
   out_173210708380746968[56] = 0;
   out_173210708380746968[57] = 1;
   out_173210708380746968[58] = 0;
   out_173210708380746968[59] = 0;
   out_173210708380746968[60] = 0;
   out_173210708380746968[61] = 0;
   out_173210708380746968[62] = 0;
   out_173210708380746968[63] = 0;
   out_173210708380746968[64] = 0;
   out_173210708380746968[65] = 0;
   out_173210708380746968[66] = dt;
   out_173210708380746968[67] = 0;
   out_173210708380746968[68] = 0;
   out_173210708380746968[69] = 0;
   out_173210708380746968[70] = 0;
   out_173210708380746968[71] = 0;
   out_173210708380746968[72] = 0;
   out_173210708380746968[73] = 0;
   out_173210708380746968[74] = 0;
   out_173210708380746968[75] = 0;
   out_173210708380746968[76] = 1;
   out_173210708380746968[77] = 0;
   out_173210708380746968[78] = 0;
   out_173210708380746968[79] = 0;
   out_173210708380746968[80] = 0;
   out_173210708380746968[81] = 0;
   out_173210708380746968[82] = 0;
   out_173210708380746968[83] = 0;
   out_173210708380746968[84] = 0;
   out_173210708380746968[85] = dt;
   out_173210708380746968[86] = 0;
   out_173210708380746968[87] = 0;
   out_173210708380746968[88] = 0;
   out_173210708380746968[89] = 0;
   out_173210708380746968[90] = 0;
   out_173210708380746968[91] = 0;
   out_173210708380746968[92] = 0;
   out_173210708380746968[93] = 0;
   out_173210708380746968[94] = 0;
   out_173210708380746968[95] = 1;
   out_173210708380746968[96] = 0;
   out_173210708380746968[97] = 0;
   out_173210708380746968[98] = 0;
   out_173210708380746968[99] = 0;
   out_173210708380746968[100] = 0;
   out_173210708380746968[101] = 0;
   out_173210708380746968[102] = 0;
   out_173210708380746968[103] = 0;
   out_173210708380746968[104] = dt;
   out_173210708380746968[105] = 0;
   out_173210708380746968[106] = 0;
   out_173210708380746968[107] = 0;
   out_173210708380746968[108] = 0;
   out_173210708380746968[109] = 0;
   out_173210708380746968[110] = 0;
   out_173210708380746968[111] = 0;
   out_173210708380746968[112] = 0;
   out_173210708380746968[113] = 0;
   out_173210708380746968[114] = 1;
   out_173210708380746968[115] = 0;
   out_173210708380746968[116] = 0;
   out_173210708380746968[117] = 0;
   out_173210708380746968[118] = 0;
   out_173210708380746968[119] = 0;
   out_173210708380746968[120] = 0;
   out_173210708380746968[121] = 0;
   out_173210708380746968[122] = 0;
   out_173210708380746968[123] = 0;
   out_173210708380746968[124] = 0;
   out_173210708380746968[125] = 0;
   out_173210708380746968[126] = 0;
   out_173210708380746968[127] = 0;
   out_173210708380746968[128] = 0;
   out_173210708380746968[129] = 0;
   out_173210708380746968[130] = 0;
   out_173210708380746968[131] = 0;
   out_173210708380746968[132] = 0;
   out_173210708380746968[133] = 1;
   out_173210708380746968[134] = 0;
   out_173210708380746968[135] = 0;
   out_173210708380746968[136] = 0;
   out_173210708380746968[137] = 0;
   out_173210708380746968[138] = 0;
   out_173210708380746968[139] = 0;
   out_173210708380746968[140] = 0;
   out_173210708380746968[141] = 0;
   out_173210708380746968[142] = 0;
   out_173210708380746968[143] = 0;
   out_173210708380746968[144] = 0;
   out_173210708380746968[145] = 0;
   out_173210708380746968[146] = 0;
   out_173210708380746968[147] = 0;
   out_173210708380746968[148] = 0;
   out_173210708380746968[149] = 0;
   out_173210708380746968[150] = 0;
   out_173210708380746968[151] = 0;
   out_173210708380746968[152] = 1;
   out_173210708380746968[153] = 0;
   out_173210708380746968[154] = 0;
   out_173210708380746968[155] = 0;
   out_173210708380746968[156] = 0;
   out_173210708380746968[157] = 0;
   out_173210708380746968[158] = 0;
   out_173210708380746968[159] = 0;
   out_173210708380746968[160] = 0;
   out_173210708380746968[161] = 0;
   out_173210708380746968[162] = 0;
   out_173210708380746968[163] = 0;
   out_173210708380746968[164] = 0;
   out_173210708380746968[165] = 0;
   out_173210708380746968[166] = 0;
   out_173210708380746968[167] = 0;
   out_173210708380746968[168] = 0;
   out_173210708380746968[169] = 0;
   out_173210708380746968[170] = 0;
   out_173210708380746968[171] = 1;
   out_173210708380746968[172] = 0;
   out_173210708380746968[173] = 0;
   out_173210708380746968[174] = 0;
   out_173210708380746968[175] = 0;
   out_173210708380746968[176] = 0;
   out_173210708380746968[177] = 0;
   out_173210708380746968[178] = 0;
   out_173210708380746968[179] = 0;
   out_173210708380746968[180] = 0;
   out_173210708380746968[181] = 0;
   out_173210708380746968[182] = 0;
   out_173210708380746968[183] = 0;
   out_173210708380746968[184] = 0;
   out_173210708380746968[185] = 0;
   out_173210708380746968[186] = 0;
   out_173210708380746968[187] = 0;
   out_173210708380746968[188] = 0;
   out_173210708380746968[189] = 0;
   out_173210708380746968[190] = 1;
   out_173210708380746968[191] = 0;
   out_173210708380746968[192] = 0;
   out_173210708380746968[193] = 0;
   out_173210708380746968[194] = 0;
   out_173210708380746968[195] = 0;
   out_173210708380746968[196] = 0;
   out_173210708380746968[197] = 0;
   out_173210708380746968[198] = 0;
   out_173210708380746968[199] = 0;
   out_173210708380746968[200] = 0;
   out_173210708380746968[201] = 0;
   out_173210708380746968[202] = 0;
   out_173210708380746968[203] = 0;
   out_173210708380746968[204] = 0;
   out_173210708380746968[205] = 0;
   out_173210708380746968[206] = 0;
   out_173210708380746968[207] = 0;
   out_173210708380746968[208] = 0;
   out_173210708380746968[209] = 1;
   out_173210708380746968[210] = 0;
   out_173210708380746968[211] = 0;
   out_173210708380746968[212] = 0;
   out_173210708380746968[213] = 0;
   out_173210708380746968[214] = 0;
   out_173210708380746968[215] = 0;
   out_173210708380746968[216] = 0;
   out_173210708380746968[217] = 0;
   out_173210708380746968[218] = 0;
   out_173210708380746968[219] = 0;
   out_173210708380746968[220] = 0;
   out_173210708380746968[221] = 0;
   out_173210708380746968[222] = 0;
   out_173210708380746968[223] = 0;
   out_173210708380746968[224] = 0;
   out_173210708380746968[225] = 0;
   out_173210708380746968[226] = 0;
   out_173210708380746968[227] = 0;
   out_173210708380746968[228] = 1;
   out_173210708380746968[229] = 0;
   out_173210708380746968[230] = 0;
   out_173210708380746968[231] = 0;
   out_173210708380746968[232] = 0;
   out_173210708380746968[233] = 0;
   out_173210708380746968[234] = 0;
   out_173210708380746968[235] = 0;
   out_173210708380746968[236] = 0;
   out_173210708380746968[237] = 0;
   out_173210708380746968[238] = 0;
   out_173210708380746968[239] = 0;
   out_173210708380746968[240] = 0;
   out_173210708380746968[241] = 0;
   out_173210708380746968[242] = 0;
   out_173210708380746968[243] = 0;
   out_173210708380746968[244] = 0;
   out_173210708380746968[245] = 0;
   out_173210708380746968[246] = 0;
   out_173210708380746968[247] = 1;
   out_173210708380746968[248] = 0;
   out_173210708380746968[249] = 0;
   out_173210708380746968[250] = 0;
   out_173210708380746968[251] = 0;
   out_173210708380746968[252] = 0;
   out_173210708380746968[253] = 0;
   out_173210708380746968[254] = 0;
   out_173210708380746968[255] = 0;
   out_173210708380746968[256] = 0;
   out_173210708380746968[257] = 0;
   out_173210708380746968[258] = 0;
   out_173210708380746968[259] = 0;
   out_173210708380746968[260] = 0;
   out_173210708380746968[261] = 0;
   out_173210708380746968[262] = 0;
   out_173210708380746968[263] = 0;
   out_173210708380746968[264] = 0;
   out_173210708380746968[265] = 0;
   out_173210708380746968[266] = 1;
   out_173210708380746968[267] = 0;
   out_173210708380746968[268] = 0;
   out_173210708380746968[269] = 0;
   out_173210708380746968[270] = 0;
   out_173210708380746968[271] = 0;
   out_173210708380746968[272] = 0;
   out_173210708380746968[273] = 0;
   out_173210708380746968[274] = 0;
   out_173210708380746968[275] = 0;
   out_173210708380746968[276] = 0;
   out_173210708380746968[277] = 0;
   out_173210708380746968[278] = 0;
   out_173210708380746968[279] = 0;
   out_173210708380746968[280] = 0;
   out_173210708380746968[281] = 0;
   out_173210708380746968[282] = 0;
   out_173210708380746968[283] = 0;
   out_173210708380746968[284] = 0;
   out_173210708380746968[285] = 1;
   out_173210708380746968[286] = 0;
   out_173210708380746968[287] = 0;
   out_173210708380746968[288] = 0;
   out_173210708380746968[289] = 0;
   out_173210708380746968[290] = 0;
   out_173210708380746968[291] = 0;
   out_173210708380746968[292] = 0;
   out_173210708380746968[293] = 0;
   out_173210708380746968[294] = 0;
   out_173210708380746968[295] = 0;
   out_173210708380746968[296] = 0;
   out_173210708380746968[297] = 0;
   out_173210708380746968[298] = 0;
   out_173210708380746968[299] = 0;
   out_173210708380746968[300] = 0;
   out_173210708380746968[301] = 0;
   out_173210708380746968[302] = 0;
   out_173210708380746968[303] = 0;
   out_173210708380746968[304] = 1;
   out_173210708380746968[305] = 0;
   out_173210708380746968[306] = 0;
   out_173210708380746968[307] = 0;
   out_173210708380746968[308] = 0;
   out_173210708380746968[309] = 0;
   out_173210708380746968[310] = 0;
   out_173210708380746968[311] = 0;
   out_173210708380746968[312] = 0;
   out_173210708380746968[313] = 0;
   out_173210708380746968[314] = 0;
   out_173210708380746968[315] = 0;
   out_173210708380746968[316] = 0;
   out_173210708380746968[317] = 0;
   out_173210708380746968[318] = 0;
   out_173210708380746968[319] = 0;
   out_173210708380746968[320] = 0;
   out_173210708380746968[321] = 0;
   out_173210708380746968[322] = 0;
   out_173210708380746968[323] = 1;
}
void h_4(double *state, double *unused, double *out_4290451809527946304) {
   out_4290451809527946304[0] = state[6] + state[9];
   out_4290451809527946304[1] = state[7] + state[10];
   out_4290451809527946304[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4695815100881587760) {
   out_4695815100881587760[0] = 0;
   out_4695815100881587760[1] = 0;
   out_4695815100881587760[2] = 0;
   out_4695815100881587760[3] = 0;
   out_4695815100881587760[4] = 0;
   out_4695815100881587760[5] = 0;
   out_4695815100881587760[6] = 1;
   out_4695815100881587760[7] = 0;
   out_4695815100881587760[8] = 0;
   out_4695815100881587760[9] = 1;
   out_4695815100881587760[10] = 0;
   out_4695815100881587760[11] = 0;
   out_4695815100881587760[12] = 0;
   out_4695815100881587760[13] = 0;
   out_4695815100881587760[14] = 0;
   out_4695815100881587760[15] = 0;
   out_4695815100881587760[16] = 0;
   out_4695815100881587760[17] = 0;
   out_4695815100881587760[18] = 0;
   out_4695815100881587760[19] = 0;
   out_4695815100881587760[20] = 0;
   out_4695815100881587760[21] = 0;
   out_4695815100881587760[22] = 0;
   out_4695815100881587760[23] = 0;
   out_4695815100881587760[24] = 0;
   out_4695815100881587760[25] = 1;
   out_4695815100881587760[26] = 0;
   out_4695815100881587760[27] = 0;
   out_4695815100881587760[28] = 1;
   out_4695815100881587760[29] = 0;
   out_4695815100881587760[30] = 0;
   out_4695815100881587760[31] = 0;
   out_4695815100881587760[32] = 0;
   out_4695815100881587760[33] = 0;
   out_4695815100881587760[34] = 0;
   out_4695815100881587760[35] = 0;
   out_4695815100881587760[36] = 0;
   out_4695815100881587760[37] = 0;
   out_4695815100881587760[38] = 0;
   out_4695815100881587760[39] = 0;
   out_4695815100881587760[40] = 0;
   out_4695815100881587760[41] = 0;
   out_4695815100881587760[42] = 0;
   out_4695815100881587760[43] = 0;
   out_4695815100881587760[44] = 1;
   out_4695815100881587760[45] = 0;
   out_4695815100881587760[46] = 0;
   out_4695815100881587760[47] = 1;
   out_4695815100881587760[48] = 0;
   out_4695815100881587760[49] = 0;
   out_4695815100881587760[50] = 0;
   out_4695815100881587760[51] = 0;
   out_4695815100881587760[52] = 0;
   out_4695815100881587760[53] = 0;
}
void h_10(double *state, double *unused, double *out_6723857678965398132) {
   out_6723857678965398132[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6723857678965398132[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6723857678965398132[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_984080189925557249) {
   out_984080189925557249[0] = 0;
   out_984080189925557249[1] = 9.8100000000000005*cos(state[1]);
   out_984080189925557249[2] = 0;
   out_984080189925557249[3] = 0;
   out_984080189925557249[4] = -state[8];
   out_984080189925557249[5] = state[7];
   out_984080189925557249[6] = 0;
   out_984080189925557249[7] = state[5];
   out_984080189925557249[8] = -state[4];
   out_984080189925557249[9] = 0;
   out_984080189925557249[10] = 0;
   out_984080189925557249[11] = 0;
   out_984080189925557249[12] = 1;
   out_984080189925557249[13] = 0;
   out_984080189925557249[14] = 0;
   out_984080189925557249[15] = 1;
   out_984080189925557249[16] = 0;
   out_984080189925557249[17] = 0;
   out_984080189925557249[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_984080189925557249[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_984080189925557249[20] = 0;
   out_984080189925557249[21] = state[8];
   out_984080189925557249[22] = 0;
   out_984080189925557249[23] = -state[6];
   out_984080189925557249[24] = -state[5];
   out_984080189925557249[25] = 0;
   out_984080189925557249[26] = state[3];
   out_984080189925557249[27] = 0;
   out_984080189925557249[28] = 0;
   out_984080189925557249[29] = 0;
   out_984080189925557249[30] = 0;
   out_984080189925557249[31] = 1;
   out_984080189925557249[32] = 0;
   out_984080189925557249[33] = 0;
   out_984080189925557249[34] = 1;
   out_984080189925557249[35] = 0;
   out_984080189925557249[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_984080189925557249[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_984080189925557249[38] = 0;
   out_984080189925557249[39] = -state[7];
   out_984080189925557249[40] = state[6];
   out_984080189925557249[41] = 0;
   out_984080189925557249[42] = state[4];
   out_984080189925557249[43] = -state[3];
   out_984080189925557249[44] = 0;
   out_984080189925557249[45] = 0;
   out_984080189925557249[46] = 0;
   out_984080189925557249[47] = 0;
   out_984080189925557249[48] = 0;
   out_984080189925557249[49] = 0;
   out_984080189925557249[50] = 1;
   out_984080189925557249[51] = 0;
   out_984080189925557249[52] = 0;
   out_984080189925557249[53] = 1;
}
void h_13(double *state, double *unused, double *out_1838091537859337419) {
   out_1838091537859337419[0] = state[3];
   out_1838091537859337419[1] = state[4];
   out_1838091537859337419[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1483541275549254959) {
   out_1483541275549254959[0] = 0;
   out_1483541275549254959[1] = 0;
   out_1483541275549254959[2] = 0;
   out_1483541275549254959[3] = 1;
   out_1483541275549254959[4] = 0;
   out_1483541275549254959[5] = 0;
   out_1483541275549254959[6] = 0;
   out_1483541275549254959[7] = 0;
   out_1483541275549254959[8] = 0;
   out_1483541275549254959[9] = 0;
   out_1483541275549254959[10] = 0;
   out_1483541275549254959[11] = 0;
   out_1483541275549254959[12] = 0;
   out_1483541275549254959[13] = 0;
   out_1483541275549254959[14] = 0;
   out_1483541275549254959[15] = 0;
   out_1483541275549254959[16] = 0;
   out_1483541275549254959[17] = 0;
   out_1483541275549254959[18] = 0;
   out_1483541275549254959[19] = 0;
   out_1483541275549254959[20] = 0;
   out_1483541275549254959[21] = 0;
   out_1483541275549254959[22] = 1;
   out_1483541275549254959[23] = 0;
   out_1483541275549254959[24] = 0;
   out_1483541275549254959[25] = 0;
   out_1483541275549254959[26] = 0;
   out_1483541275549254959[27] = 0;
   out_1483541275549254959[28] = 0;
   out_1483541275549254959[29] = 0;
   out_1483541275549254959[30] = 0;
   out_1483541275549254959[31] = 0;
   out_1483541275549254959[32] = 0;
   out_1483541275549254959[33] = 0;
   out_1483541275549254959[34] = 0;
   out_1483541275549254959[35] = 0;
   out_1483541275549254959[36] = 0;
   out_1483541275549254959[37] = 0;
   out_1483541275549254959[38] = 0;
   out_1483541275549254959[39] = 0;
   out_1483541275549254959[40] = 0;
   out_1483541275549254959[41] = 1;
   out_1483541275549254959[42] = 0;
   out_1483541275549254959[43] = 0;
   out_1483541275549254959[44] = 0;
   out_1483541275549254959[45] = 0;
   out_1483541275549254959[46] = 0;
   out_1483541275549254959[47] = 0;
   out_1483541275549254959[48] = 0;
   out_1483541275549254959[49] = 0;
   out_1483541275549254959[50] = 0;
   out_1483541275549254959[51] = 0;
   out_1483541275549254959[52] = 0;
   out_1483541275549254959[53] = 0;
}
void h_14(double *state, double *unused, double *out_849503921054780572) {
   out_849503921054780572[0] = state[6];
   out_849503921054780572[1] = state[7];
   out_849503921054780572[2] = state[8];
}
void H_14(double *state, double *unused, double *out_732574244542103231) {
   out_732574244542103231[0] = 0;
   out_732574244542103231[1] = 0;
   out_732574244542103231[2] = 0;
   out_732574244542103231[3] = 0;
   out_732574244542103231[4] = 0;
   out_732574244542103231[5] = 0;
   out_732574244542103231[6] = 1;
   out_732574244542103231[7] = 0;
   out_732574244542103231[8] = 0;
   out_732574244542103231[9] = 0;
   out_732574244542103231[10] = 0;
   out_732574244542103231[11] = 0;
   out_732574244542103231[12] = 0;
   out_732574244542103231[13] = 0;
   out_732574244542103231[14] = 0;
   out_732574244542103231[15] = 0;
   out_732574244542103231[16] = 0;
   out_732574244542103231[17] = 0;
   out_732574244542103231[18] = 0;
   out_732574244542103231[19] = 0;
   out_732574244542103231[20] = 0;
   out_732574244542103231[21] = 0;
   out_732574244542103231[22] = 0;
   out_732574244542103231[23] = 0;
   out_732574244542103231[24] = 0;
   out_732574244542103231[25] = 1;
   out_732574244542103231[26] = 0;
   out_732574244542103231[27] = 0;
   out_732574244542103231[28] = 0;
   out_732574244542103231[29] = 0;
   out_732574244542103231[30] = 0;
   out_732574244542103231[31] = 0;
   out_732574244542103231[32] = 0;
   out_732574244542103231[33] = 0;
   out_732574244542103231[34] = 0;
   out_732574244542103231[35] = 0;
   out_732574244542103231[36] = 0;
   out_732574244542103231[37] = 0;
   out_732574244542103231[38] = 0;
   out_732574244542103231[39] = 0;
   out_732574244542103231[40] = 0;
   out_732574244542103231[41] = 0;
   out_732574244542103231[42] = 0;
   out_732574244542103231[43] = 0;
   out_732574244542103231[44] = 1;
   out_732574244542103231[45] = 0;
   out_732574244542103231[46] = 0;
   out_732574244542103231[47] = 0;
   out_732574244542103231[48] = 0;
   out_732574244542103231[49] = 0;
   out_732574244542103231[50] = 0;
   out_732574244542103231[51] = 0;
   out_732574244542103231[52] = 0;
   out_732574244542103231[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_9044617002367965712) {
  err_fun(nom_x, delta_x, out_9044617002367965712);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2986388781113821274) {
  inv_err_fun(nom_x, true_x, out_2986388781113821274);
}
void pose_H_mod_fun(double *state, double *out_5449976102936300367) {
  H_mod_fun(state, out_5449976102936300367);
}
void pose_f_fun(double *state, double dt, double *out_2001314774583974236) {
  f_fun(state,  dt, out_2001314774583974236);
}
void pose_F_fun(double *state, double dt, double *out_173210708380746968) {
  F_fun(state,  dt, out_173210708380746968);
}
void pose_h_4(double *state, double *unused, double *out_4290451809527946304) {
  h_4(state, unused, out_4290451809527946304);
}
void pose_H_4(double *state, double *unused, double *out_4695815100881587760) {
  H_4(state, unused, out_4695815100881587760);
}
void pose_h_10(double *state, double *unused, double *out_6723857678965398132) {
  h_10(state, unused, out_6723857678965398132);
}
void pose_H_10(double *state, double *unused, double *out_984080189925557249) {
  H_10(state, unused, out_984080189925557249);
}
void pose_h_13(double *state, double *unused, double *out_1838091537859337419) {
  h_13(state, unused, out_1838091537859337419);
}
void pose_H_13(double *state, double *unused, double *out_1483541275549254959) {
  H_13(state, unused, out_1483541275549254959);
}
void pose_h_14(double *state, double *unused, double *out_849503921054780572) {
  h_14(state, unused, out_849503921054780572);
}
void pose_H_14(double *state, double *unused, double *out_732574244542103231) {
  H_14(state, unused, out_732574244542103231);
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
