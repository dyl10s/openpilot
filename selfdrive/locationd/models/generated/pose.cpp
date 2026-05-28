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
void err_fun(double *nom_x, double *delta_x, double *out_8315489890310503187) {
   out_8315489890310503187[0] = delta_x[0] + nom_x[0];
   out_8315489890310503187[1] = delta_x[1] + nom_x[1];
   out_8315489890310503187[2] = delta_x[2] + nom_x[2];
   out_8315489890310503187[3] = delta_x[3] + nom_x[3];
   out_8315489890310503187[4] = delta_x[4] + nom_x[4];
   out_8315489890310503187[5] = delta_x[5] + nom_x[5];
   out_8315489890310503187[6] = delta_x[6] + nom_x[6];
   out_8315489890310503187[7] = delta_x[7] + nom_x[7];
   out_8315489890310503187[8] = delta_x[8] + nom_x[8];
   out_8315489890310503187[9] = delta_x[9] + nom_x[9];
   out_8315489890310503187[10] = delta_x[10] + nom_x[10];
   out_8315489890310503187[11] = delta_x[11] + nom_x[11];
   out_8315489890310503187[12] = delta_x[12] + nom_x[12];
   out_8315489890310503187[13] = delta_x[13] + nom_x[13];
   out_8315489890310503187[14] = delta_x[14] + nom_x[14];
   out_8315489890310503187[15] = delta_x[15] + nom_x[15];
   out_8315489890310503187[16] = delta_x[16] + nom_x[16];
   out_8315489890310503187[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6008596051390826841) {
   out_6008596051390826841[0] = -nom_x[0] + true_x[0];
   out_6008596051390826841[1] = -nom_x[1] + true_x[1];
   out_6008596051390826841[2] = -nom_x[2] + true_x[2];
   out_6008596051390826841[3] = -nom_x[3] + true_x[3];
   out_6008596051390826841[4] = -nom_x[4] + true_x[4];
   out_6008596051390826841[5] = -nom_x[5] + true_x[5];
   out_6008596051390826841[6] = -nom_x[6] + true_x[6];
   out_6008596051390826841[7] = -nom_x[7] + true_x[7];
   out_6008596051390826841[8] = -nom_x[8] + true_x[8];
   out_6008596051390826841[9] = -nom_x[9] + true_x[9];
   out_6008596051390826841[10] = -nom_x[10] + true_x[10];
   out_6008596051390826841[11] = -nom_x[11] + true_x[11];
   out_6008596051390826841[12] = -nom_x[12] + true_x[12];
   out_6008596051390826841[13] = -nom_x[13] + true_x[13];
   out_6008596051390826841[14] = -nom_x[14] + true_x[14];
   out_6008596051390826841[15] = -nom_x[15] + true_x[15];
   out_6008596051390826841[16] = -nom_x[16] + true_x[16];
   out_6008596051390826841[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5634677350720166788) {
   out_5634677350720166788[0] = 1.0;
   out_5634677350720166788[1] = 0.0;
   out_5634677350720166788[2] = 0.0;
   out_5634677350720166788[3] = 0.0;
   out_5634677350720166788[4] = 0.0;
   out_5634677350720166788[5] = 0.0;
   out_5634677350720166788[6] = 0.0;
   out_5634677350720166788[7] = 0.0;
   out_5634677350720166788[8] = 0.0;
   out_5634677350720166788[9] = 0.0;
   out_5634677350720166788[10] = 0.0;
   out_5634677350720166788[11] = 0.0;
   out_5634677350720166788[12] = 0.0;
   out_5634677350720166788[13] = 0.0;
   out_5634677350720166788[14] = 0.0;
   out_5634677350720166788[15] = 0.0;
   out_5634677350720166788[16] = 0.0;
   out_5634677350720166788[17] = 0.0;
   out_5634677350720166788[18] = 0.0;
   out_5634677350720166788[19] = 1.0;
   out_5634677350720166788[20] = 0.0;
   out_5634677350720166788[21] = 0.0;
   out_5634677350720166788[22] = 0.0;
   out_5634677350720166788[23] = 0.0;
   out_5634677350720166788[24] = 0.0;
   out_5634677350720166788[25] = 0.0;
   out_5634677350720166788[26] = 0.0;
   out_5634677350720166788[27] = 0.0;
   out_5634677350720166788[28] = 0.0;
   out_5634677350720166788[29] = 0.0;
   out_5634677350720166788[30] = 0.0;
   out_5634677350720166788[31] = 0.0;
   out_5634677350720166788[32] = 0.0;
   out_5634677350720166788[33] = 0.0;
   out_5634677350720166788[34] = 0.0;
   out_5634677350720166788[35] = 0.0;
   out_5634677350720166788[36] = 0.0;
   out_5634677350720166788[37] = 0.0;
   out_5634677350720166788[38] = 1.0;
   out_5634677350720166788[39] = 0.0;
   out_5634677350720166788[40] = 0.0;
   out_5634677350720166788[41] = 0.0;
   out_5634677350720166788[42] = 0.0;
   out_5634677350720166788[43] = 0.0;
   out_5634677350720166788[44] = 0.0;
   out_5634677350720166788[45] = 0.0;
   out_5634677350720166788[46] = 0.0;
   out_5634677350720166788[47] = 0.0;
   out_5634677350720166788[48] = 0.0;
   out_5634677350720166788[49] = 0.0;
   out_5634677350720166788[50] = 0.0;
   out_5634677350720166788[51] = 0.0;
   out_5634677350720166788[52] = 0.0;
   out_5634677350720166788[53] = 0.0;
   out_5634677350720166788[54] = 0.0;
   out_5634677350720166788[55] = 0.0;
   out_5634677350720166788[56] = 0.0;
   out_5634677350720166788[57] = 1.0;
   out_5634677350720166788[58] = 0.0;
   out_5634677350720166788[59] = 0.0;
   out_5634677350720166788[60] = 0.0;
   out_5634677350720166788[61] = 0.0;
   out_5634677350720166788[62] = 0.0;
   out_5634677350720166788[63] = 0.0;
   out_5634677350720166788[64] = 0.0;
   out_5634677350720166788[65] = 0.0;
   out_5634677350720166788[66] = 0.0;
   out_5634677350720166788[67] = 0.0;
   out_5634677350720166788[68] = 0.0;
   out_5634677350720166788[69] = 0.0;
   out_5634677350720166788[70] = 0.0;
   out_5634677350720166788[71] = 0.0;
   out_5634677350720166788[72] = 0.0;
   out_5634677350720166788[73] = 0.0;
   out_5634677350720166788[74] = 0.0;
   out_5634677350720166788[75] = 0.0;
   out_5634677350720166788[76] = 1.0;
   out_5634677350720166788[77] = 0.0;
   out_5634677350720166788[78] = 0.0;
   out_5634677350720166788[79] = 0.0;
   out_5634677350720166788[80] = 0.0;
   out_5634677350720166788[81] = 0.0;
   out_5634677350720166788[82] = 0.0;
   out_5634677350720166788[83] = 0.0;
   out_5634677350720166788[84] = 0.0;
   out_5634677350720166788[85] = 0.0;
   out_5634677350720166788[86] = 0.0;
   out_5634677350720166788[87] = 0.0;
   out_5634677350720166788[88] = 0.0;
   out_5634677350720166788[89] = 0.0;
   out_5634677350720166788[90] = 0.0;
   out_5634677350720166788[91] = 0.0;
   out_5634677350720166788[92] = 0.0;
   out_5634677350720166788[93] = 0.0;
   out_5634677350720166788[94] = 0.0;
   out_5634677350720166788[95] = 1.0;
   out_5634677350720166788[96] = 0.0;
   out_5634677350720166788[97] = 0.0;
   out_5634677350720166788[98] = 0.0;
   out_5634677350720166788[99] = 0.0;
   out_5634677350720166788[100] = 0.0;
   out_5634677350720166788[101] = 0.0;
   out_5634677350720166788[102] = 0.0;
   out_5634677350720166788[103] = 0.0;
   out_5634677350720166788[104] = 0.0;
   out_5634677350720166788[105] = 0.0;
   out_5634677350720166788[106] = 0.0;
   out_5634677350720166788[107] = 0.0;
   out_5634677350720166788[108] = 0.0;
   out_5634677350720166788[109] = 0.0;
   out_5634677350720166788[110] = 0.0;
   out_5634677350720166788[111] = 0.0;
   out_5634677350720166788[112] = 0.0;
   out_5634677350720166788[113] = 0.0;
   out_5634677350720166788[114] = 1.0;
   out_5634677350720166788[115] = 0.0;
   out_5634677350720166788[116] = 0.0;
   out_5634677350720166788[117] = 0.0;
   out_5634677350720166788[118] = 0.0;
   out_5634677350720166788[119] = 0.0;
   out_5634677350720166788[120] = 0.0;
   out_5634677350720166788[121] = 0.0;
   out_5634677350720166788[122] = 0.0;
   out_5634677350720166788[123] = 0.0;
   out_5634677350720166788[124] = 0.0;
   out_5634677350720166788[125] = 0.0;
   out_5634677350720166788[126] = 0.0;
   out_5634677350720166788[127] = 0.0;
   out_5634677350720166788[128] = 0.0;
   out_5634677350720166788[129] = 0.0;
   out_5634677350720166788[130] = 0.0;
   out_5634677350720166788[131] = 0.0;
   out_5634677350720166788[132] = 0.0;
   out_5634677350720166788[133] = 1.0;
   out_5634677350720166788[134] = 0.0;
   out_5634677350720166788[135] = 0.0;
   out_5634677350720166788[136] = 0.0;
   out_5634677350720166788[137] = 0.0;
   out_5634677350720166788[138] = 0.0;
   out_5634677350720166788[139] = 0.0;
   out_5634677350720166788[140] = 0.0;
   out_5634677350720166788[141] = 0.0;
   out_5634677350720166788[142] = 0.0;
   out_5634677350720166788[143] = 0.0;
   out_5634677350720166788[144] = 0.0;
   out_5634677350720166788[145] = 0.0;
   out_5634677350720166788[146] = 0.0;
   out_5634677350720166788[147] = 0.0;
   out_5634677350720166788[148] = 0.0;
   out_5634677350720166788[149] = 0.0;
   out_5634677350720166788[150] = 0.0;
   out_5634677350720166788[151] = 0.0;
   out_5634677350720166788[152] = 1.0;
   out_5634677350720166788[153] = 0.0;
   out_5634677350720166788[154] = 0.0;
   out_5634677350720166788[155] = 0.0;
   out_5634677350720166788[156] = 0.0;
   out_5634677350720166788[157] = 0.0;
   out_5634677350720166788[158] = 0.0;
   out_5634677350720166788[159] = 0.0;
   out_5634677350720166788[160] = 0.0;
   out_5634677350720166788[161] = 0.0;
   out_5634677350720166788[162] = 0.0;
   out_5634677350720166788[163] = 0.0;
   out_5634677350720166788[164] = 0.0;
   out_5634677350720166788[165] = 0.0;
   out_5634677350720166788[166] = 0.0;
   out_5634677350720166788[167] = 0.0;
   out_5634677350720166788[168] = 0.0;
   out_5634677350720166788[169] = 0.0;
   out_5634677350720166788[170] = 0.0;
   out_5634677350720166788[171] = 1.0;
   out_5634677350720166788[172] = 0.0;
   out_5634677350720166788[173] = 0.0;
   out_5634677350720166788[174] = 0.0;
   out_5634677350720166788[175] = 0.0;
   out_5634677350720166788[176] = 0.0;
   out_5634677350720166788[177] = 0.0;
   out_5634677350720166788[178] = 0.0;
   out_5634677350720166788[179] = 0.0;
   out_5634677350720166788[180] = 0.0;
   out_5634677350720166788[181] = 0.0;
   out_5634677350720166788[182] = 0.0;
   out_5634677350720166788[183] = 0.0;
   out_5634677350720166788[184] = 0.0;
   out_5634677350720166788[185] = 0.0;
   out_5634677350720166788[186] = 0.0;
   out_5634677350720166788[187] = 0.0;
   out_5634677350720166788[188] = 0.0;
   out_5634677350720166788[189] = 0.0;
   out_5634677350720166788[190] = 1.0;
   out_5634677350720166788[191] = 0.0;
   out_5634677350720166788[192] = 0.0;
   out_5634677350720166788[193] = 0.0;
   out_5634677350720166788[194] = 0.0;
   out_5634677350720166788[195] = 0.0;
   out_5634677350720166788[196] = 0.0;
   out_5634677350720166788[197] = 0.0;
   out_5634677350720166788[198] = 0.0;
   out_5634677350720166788[199] = 0.0;
   out_5634677350720166788[200] = 0.0;
   out_5634677350720166788[201] = 0.0;
   out_5634677350720166788[202] = 0.0;
   out_5634677350720166788[203] = 0.0;
   out_5634677350720166788[204] = 0.0;
   out_5634677350720166788[205] = 0.0;
   out_5634677350720166788[206] = 0.0;
   out_5634677350720166788[207] = 0.0;
   out_5634677350720166788[208] = 0.0;
   out_5634677350720166788[209] = 1.0;
   out_5634677350720166788[210] = 0.0;
   out_5634677350720166788[211] = 0.0;
   out_5634677350720166788[212] = 0.0;
   out_5634677350720166788[213] = 0.0;
   out_5634677350720166788[214] = 0.0;
   out_5634677350720166788[215] = 0.0;
   out_5634677350720166788[216] = 0.0;
   out_5634677350720166788[217] = 0.0;
   out_5634677350720166788[218] = 0.0;
   out_5634677350720166788[219] = 0.0;
   out_5634677350720166788[220] = 0.0;
   out_5634677350720166788[221] = 0.0;
   out_5634677350720166788[222] = 0.0;
   out_5634677350720166788[223] = 0.0;
   out_5634677350720166788[224] = 0.0;
   out_5634677350720166788[225] = 0.0;
   out_5634677350720166788[226] = 0.0;
   out_5634677350720166788[227] = 0.0;
   out_5634677350720166788[228] = 1.0;
   out_5634677350720166788[229] = 0.0;
   out_5634677350720166788[230] = 0.0;
   out_5634677350720166788[231] = 0.0;
   out_5634677350720166788[232] = 0.0;
   out_5634677350720166788[233] = 0.0;
   out_5634677350720166788[234] = 0.0;
   out_5634677350720166788[235] = 0.0;
   out_5634677350720166788[236] = 0.0;
   out_5634677350720166788[237] = 0.0;
   out_5634677350720166788[238] = 0.0;
   out_5634677350720166788[239] = 0.0;
   out_5634677350720166788[240] = 0.0;
   out_5634677350720166788[241] = 0.0;
   out_5634677350720166788[242] = 0.0;
   out_5634677350720166788[243] = 0.0;
   out_5634677350720166788[244] = 0.0;
   out_5634677350720166788[245] = 0.0;
   out_5634677350720166788[246] = 0.0;
   out_5634677350720166788[247] = 1.0;
   out_5634677350720166788[248] = 0.0;
   out_5634677350720166788[249] = 0.0;
   out_5634677350720166788[250] = 0.0;
   out_5634677350720166788[251] = 0.0;
   out_5634677350720166788[252] = 0.0;
   out_5634677350720166788[253] = 0.0;
   out_5634677350720166788[254] = 0.0;
   out_5634677350720166788[255] = 0.0;
   out_5634677350720166788[256] = 0.0;
   out_5634677350720166788[257] = 0.0;
   out_5634677350720166788[258] = 0.0;
   out_5634677350720166788[259] = 0.0;
   out_5634677350720166788[260] = 0.0;
   out_5634677350720166788[261] = 0.0;
   out_5634677350720166788[262] = 0.0;
   out_5634677350720166788[263] = 0.0;
   out_5634677350720166788[264] = 0.0;
   out_5634677350720166788[265] = 0.0;
   out_5634677350720166788[266] = 1.0;
   out_5634677350720166788[267] = 0.0;
   out_5634677350720166788[268] = 0.0;
   out_5634677350720166788[269] = 0.0;
   out_5634677350720166788[270] = 0.0;
   out_5634677350720166788[271] = 0.0;
   out_5634677350720166788[272] = 0.0;
   out_5634677350720166788[273] = 0.0;
   out_5634677350720166788[274] = 0.0;
   out_5634677350720166788[275] = 0.0;
   out_5634677350720166788[276] = 0.0;
   out_5634677350720166788[277] = 0.0;
   out_5634677350720166788[278] = 0.0;
   out_5634677350720166788[279] = 0.0;
   out_5634677350720166788[280] = 0.0;
   out_5634677350720166788[281] = 0.0;
   out_5634677350720166788[282] = 0.0;
   out_5634677350720166788[283] = 0.0;
   out_5634677350720166788[284] = 0.0;
   out_5634677350720166788[285] = 1.0;
   out_5634677350720166788[286] = 0.0;
   out_5634677350720166788[287] = 0.0;
   out_5634677350720166788[288] = 0.0;
   out_5634677350720166788[289] = 0.0;
   out_5634677350720166788[290] = 0.0;
   out_5634677350720166788[291] = 0.0;
   out_5634677350720166788[292] = 0.0;
   out_5634677350720166788[293] = 0.0;
   out_5634677350720166788[294] = 0.0;
   out_5634677350720166788[295] = 0.0;
   out_5634677350720166788[296] = 0.0;
   out_5634677350720166788[297] = 0.0;
   out_5634677350720166788[298] = 0.0;
   out_5634677350720166788[299] = 0.0;
   out_5634677350720166788[300] = 0.0;
   out_5634677350720166788[301] = 0.0;
   out_5634677350720166788[302] = 0.0;
   out_5634677350720166788[303] = 0.0;
   out_5634677350720166788[304] = 1.0;
   out_5634677350720166788[305] = 0.0;
   out_5634677350720166788[306] = 0.0;
   out_5634677350720166788[307] = 0.0;
   out_5634677350720166788[308] = 0.0;
   out_5634677350720166788[309] = 0.0;
   out_5634677350720166788[310] = 0.0;
   out_5634677350720166788[311] = 0.0;
   out_5634677350720166788[312] = 0.0;
   out_5634677350720166788[313] = 0.0;
   out_5634677350720166788[314] = 0.0;
   out_5634677350720166788[315] = 0.0;
   out_5634677350720166788[316] = 0.0;
   out_5634677350720166788[317] = 0.0;
   out_5634677350720166788[318] = 0.0;
   out_5634677350720166788[319] = 0.0;
   out_5634677350720166788[320] = 0.0;
   out_5634677350720166788[321] = 0.0;
   out_5634677350720166788[322] = 0.0;
   out_5634677350720166788[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5401222257802876036) {
   out_5401222257802876036[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5401222257802876036[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5401222257802876036[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5401222257802876036[3] = dt*state[12] + state[3];
   out_5401222257802876036[4] = dt*state[13] + state[4];
   out_5401222257802876036[5] = dt*state[14] + state[5];
   out_5401222257802876036[6] = state[6];
   out_5401222257802876036[7] = state[7];
   out_5401222257802876036[8] = state[8];
   out_5401222257802876036[9] = state[9];
   out_5401222257802876036[10] = state[10];
   out_5401222257802876036[11] = state[11];
   out_5401222257802876036[12] = state[12];
   out_5401222257802876036[13] = state[13];
   out_5401222257802876036[14] = state[14];
   out_5401222257802876036[15] = state[15];
   out_5401222257802876036[16] = state[16];
   out_5401222257802876036[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1313183186567530475) {
   out_1313183186567530475[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1313183186567530475[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1313183186567530475[2] = 0;
   out_1313183186567530475[3] = 0;
   out_1313183186567530475[4] = 0;
   out_1313183186567530475[5] = 0;
   out_1313183186567530475[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1313183186567530475[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1313183186567530475[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1313183186567530475[9] = 0;
   out_1313183186567530475[10] = 0;
   out_1313183186567530475[11] = 0;
   out_1313183186567530475[12] = 0;
   out_1313183186567530475[13] = 0;
   out_1313183186567530475[14] = 0;
   out_1313183186567530475[15] = 0;
   out_1313183186567530475[16] = 0;
   out_1313183186567530475[17] = 0;
   out_1313183186567530475[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1313183186567530475[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1313183186567530475[20] = 0;
   out_1313183186567530475[21] = 0;
   out_1313183186567530475[22] = 0;
   out_1313183186567530475[23] = 0;
   out_1313183186567530475[24] = 0;
   out_1313183186567530475[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1313183186567530475[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1313183186567530475[27] = 0;
   out_1313183186567530475[28] = 0;
   out_1313183186567530475[29] = 0;
   out_1313183186567530475[30] = 0;
   out_1313183186567530475[31] = 0;
   out_1313183186567530475[32] = 0;
   out_1313183186567530475[33] = 0;
   out_1313183186567530475[34] = 0;
   out_1313183186567530475[35] = 0;
   out_1313183186567530475[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1313183186567530475[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1313183186567530475[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1313183186567530475[39] = 0;
   out_1313183186567530475[40] = 0;
   out_1313183186567530475[41] = 0;
   out_1313183186567530475[42] = 0;
   out_1313183186567530475[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1313183186567530475[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1313183186567530475[45] = 0;
   out_1313183186567530475[46] = 0;
   out_1313183186567530475[47] = 0;
   out_1313183186567530475[48] = 0;
   out_1313183186567530475[49] = 0;
   out_1313183186567530475[50] = 0;
   out_1313183186567530475[51] = 0;
   out_1313183186567530475[52] = 0;
   out_1313183186567530475[53] = 0;
   out_1313183186567530475[54] = 0;
   out_1313183186567530475[55] = 0;
   out_1313183186567530475[56] = 0;
   out_1313183186567530475[57] = 1;
   out_1313183186567530475[58] = 0;
   out_1313183186567530475[59] = 0;
   out_1313183186567530475[60] = 0;
   out_1313183186567530475[61] = 0;
   out_1313183186567530475[62] = 0;
   out_1313183186567530475[63] = 0;
   out_1313183186567530475[64] = 0;
   out_1313183186567530475[65] = 0;
   out_1313183186567530475[66] = dt;
   out_1313183186567530475[67] = 0;
   out_1313183186567530475[68] = 0;
   out_1313183186567530475[69] = 0;
   out_1313183186567530475[70] = 0;
   out_1313183186567530475[71] = 0;
   out_1313183186567530475[72] = 0;
   out_1313183186567530475[73] = 0;
   out_1313183186567530475[74] = 0;
   out_1313183186567530475[75] = 0;
   out_1313183186567530475[76] = 1;
   out_1313183186567530475[77] = 0;
   out_1313183186567530475[78] = 0;
   out_1313183186567530475[79] = 0;
   out_1313183186567530475[80] = 0;
   out_1313183186567530475[81] = 0;
   out_1313183186567530475[82] = 0;
   out_1313183186567530475[83] = 0;
   out_1313183186567530475[84] = 0;
   out_1313183186567530475[85] = dt;
   out_1313183186567530475[86] = 0;
   out_1313183186567530475[87] = 0;
   out_1313183186567530475[88] = 0;
   out_1313183186567530475[89] = 0;
   out_1313183186567530475[90] = 0;
   out_1313183186567530475[91] = 0;
   out_1313183186567530475[92] = 0;
   out_1313183186567530475[93] = 0;
   out_1313183186567530475[94] = 0;
   out_1313183186567530475[95] = 1;
   out_1313183186567530475[96] = 0;
   out_1313183186567530475[97] = 0;
   out_1313183186567530475[98] = 0;
   out_1313183186567530475[99] = 0;
   out_1313183186567530475[100] = 0;
   out_1313183186567530475[101] = 0;
   out_1313183186567530475[102] = 0;
   out_1313183186567530475[103] = 0;
   out_1313183186567530475[104] = dt;
   out_1313183186567530475[105] = 0;
   out_1313183186567530475[106] = 0;
   out_1313183186567530475[107] = 0;
   out_1313183186567530475[108] = 0;
   out_1313183186567530475[109] = 0;
   out_1313183186567530475[110] = 0;
   out_1313183186567530475[111] = 0;
   out_1313183186567530475[112] = 0;
   out_1313183186567530475[113] = 0;
   out_1313183186567530475[114] = 1;
   out_1313183186567530475[115] = 0;
   out_1313183186567530475[116] = 0;
   out_1313183186567530475[117] = 0;
   out_1313183186567530475[118] = 0;
   out_1313183186567530475[119] = 0;
   out_1313183186567530475[120] = 0;
   out_1313183186567530475[121] = 0;
   out_1313183186567530475[122] = 0;
   out_1313183186567530475[123] = 0;
   out_1313183186567530475[124] = 0;
   out_1313183186567530475[125] = 0;
   out_1313183186567530475[126] = 0;
   out_1313183186567530475[127] = 0;
   out_1313183186567530475[128] = 0;
   out_1313183186567530475[129] = 0;
   out_1313183186567530475[130] = 0;
   out_1313183186567530475[131] = 0;
   out_1313183186567530475[132] = 0;
   out_1313183186567530475[133] = 1;
   out_1313183186567530475[134] = 0;
   out_1313183186567530475[135] = 0;
   out_1313183186567530475[136] = 0;
   out_1313183186567530475[137] = 0;
   out_1313183186567530475[138] = 0;
   out_1313183186567530475[139] = 0;
   out_1313183186567530475[140] = 0;
   out_1313183186567530475[141] = 0;
   out_1313183186567530475[142] = 0;
   out_1313183186567530475[143] = 0;
   out_1313183186567530475[144] = 0;
   out_1313183186567530475[145] = 0;
   out_1313183186567530475[146] = 0;
   out_1313183186567530475[147] = 0;
   out_1313183186567530475[148] = 0;
   out_1313183186567530475[149] = 0;
   out_1313183186567530475[150] = 0;
   out_1313183186567530475[151] = 0;
   out_1313183186567530475[152] = 1;
   out_1313183186567530475[153] = 0;
   out_1313183186567530475[154] = 0;
   out_1313183186567530475[155] = 0;
   out_1313183186567530475[156] = 0;
   out_1313183186567530475[157] = 0;
   out_1313183186567530475[158] = 0;
   out_1313183186567530475[159] = 0;
   out_1313183186567530475[160] = 0;
   out_1313183186567530475[161] = 0;
   out_1313183186567530475[162] = 0;
   out_1313183186567530475[163] = 0;
   out_1313183186567530475[164] = 0;
   out_1313183186567530475[165] = 0;
   out_1313183186567530475[166] = 0;
   out_1313183186567530475[167] = 0;
   out_1313183186567530475[168] = 0;
   out_1313183186567530475[169] = 0;
   out_1313183186567530475[170] = 0;
   out_1313183186567530475[171] = 1;
   out_1313183186567530475[172] = 0;
   out_1313183186567530475[173] = 0;
   out_1313183186567530475[174] = 0;
   out_1313183186567530475[175] = 0;
   out_1313183186567530475[176] = 0;
   out_1313183186567530475[177] = 0;
   out_1313183186567530475[178] = 0;
   out_1313183186567530475[179] = 0;
   out_1313183186567530475[180] = 0;
   out_1313183186567530475[181] = 0;
   out_1313183186567530475[182] = 0;
   out_1313183186567530475[183] = 0;
   out_1313183186567530475[184] = 0;
   out_1313183186567530475[185] = 0;
   out_1313183186567530475[186] = 0;
   out_1313183186567530475[187] = 0;
   out_1313183186567530475[188] = 0;
   out_1313183186567530475[189] = 0;
   out_1313183186567530475[190] = 1;
   out_1313183186567530475[191] = 0;
   out_1313183186567530475[192] = 0;
   out_1313183186567530475[193] = 0;
   out_1313183186567530475[194] = 0;
   out_1313183186567530475[195] = 0;
   out_1313183186567530475[196] = 0;
   out_1313183186567530475[197] = 0;
   out_1313183186567530475[198] = 0;
   out_1313183186567530475[199] = 0;
   out_1313183186567530475[200] = 0;
   out_1313183186567530475[201] = 0;
   out_1313183186567530475[202] = 0;
   out_1313183186567530475[203] = 0;
   out_1313183186567530475[204] = 0;
   out_1313183186567530475[205] = 0;
   out_1313183186567530475[206] = 0;
   out_1313183186567530475[207] = 0;
   out_1313183186567530475[208] = 0;
   out_1313183186567530475[209] = 1;
   out_1313183186567530475[210] = 0;
   out_1313183186567530475[211] = 0;
   out_1313183186567530475[212] = 0;
   out_1313183186567530475[213] = 0;
   out_1313183186567530475[214] = 0;
   out_1313183186567530475[215] = 0;
   out_1313183186567530475[216] = 0;
   out_1313183186567530475[217] = 0;
   out_1313183186567530475[218] = 0;
   out_1313183186567530475[219] = 0;
   out_1313183186567530475[220] = 0;
   out_1313183186567530475[221] = 0;
   out_1313183186567530475[222] = 0;
   out_1313183186567530475[223] = 0;
   out_1313183186567530475[224] = 0;
   out_1313183186567530475[225] = 0;
   out_1313183186567530475[226] = 0;
   out_1313183186567530475[227] = 0;
   out_1313183186567530475[228] = 1;
   out_1313183186567530475[229] = 0;
   out_1313183186567530475[230] = 0;
   out_1313183186567530475[231] = 0;
   out_1313183186567530475[232] = 0;
   out_1313183186567530475[233] = 0;
   out_1313183186567530475[234] = 0;
   out_1313183186567530475[235] = 0;
   out_1313183186567530475[236] = 0;
   out_1313183186567530475[237] = 0;
   out_1313183186567530475[238] = 0;
   out_1313183186567530475[239] = 0;
   out_1313183186567530475[240] = 0;
   out_1313183186567530475[241] = 0;
   out_1313183186567530475[242] = 0;
   out_1313183186567530475[243] = 0;
   out_1313183186567530475[244] = 0;
   out_1313183186567530475[245] = 0;
   out_1313183186567530475[246] = 0;
   out_1313183186567530475[247] = 1;
   out_1313183186567530475[248] = 0;
   out_1313183186567530475[249] = 0;
   out_1313183186567530475[250] = 0;
   out_1313183186567530475[251] = 0;
   out_1313183186567530475[252] = 0;
   out_1313183186567530475[253] = 0;
   out_1313183186567530475[254] = 0;
   out_1313183186567530475[255] = 0;
   out_1313183186567530475[256] = 0;
   out_1313183186567530475[257] = 0;
   out_1313183186567530475[258] = 0;
   out_1313183186567530475[259] = 0;
   out_1313183186567530475[260] = 0;
   out_1313183186567530475[261] = 0;
   out_1313183186567530475[262] = 0;
   out_1313183186567530475[263] = 0;
   out_1313183186567530475[264] = 0;
   out_1313183186567530475[265] = 0;
   out_1313183186567530475[266] = 1;
   out_1313183186567530475[267] = 0;
   out_1313183186567530475[268] = 0;
   out_1313183186567530475[269] = 0;
   out_1313183186567530475[270] = 0;
   out_1313183186567530475[271] = 0;
   out_1313183186567530475[272] = 0;
   out_1313183186567530475[273] = 0;
   out_1313183186567530475[274] = 0;
   out_1313183186567530475[275] = 0;
   out_1313183186567530475[276] = 0;
   out_1313183186567530475[277] = 0;
   out_1313183186567530475[278] = 0;
   out_1313183186567530475[279] = 0;
   out_1313183186567530475[280] = 0;
   out_1313183186567530475[281] = 0;
   out_1313183186567530475[282] = 0;
   out_1313183186567530475[283] = 0;
   out_1313183186567530475[284] = 0;
   out_1313183186567530475[285] = 1;
   out_1313183186567530475[286] = 0;
   out_1313183186567530475[287] = 0;
   out_1313183186567530475[288] = 0;
   out_1313183186567530475[289] = 0;
   out_1313183186567530475[290] = 0;
   out_1313183186567530475[291] = 0;
   out_1313183186567530475[292] = 0;
   out_1313183186567530475[293] = 0;
   out_1313183186567530475[294] = 0;
   out_1313183186567530475[295] = 0;
   out_1313183186567530475[296] = 0;
   out_1313183186567530475[297] = 0;
   out_1313183186567530475[298] = 0;
   out_1313183186567530475[299] = 0;
   out_1313183186567530475[300] = 0;
   out_1313183186567530475[301] = 0;
   out_1313183186567530475[302] = 0;
   out_1313183186567530475[303] = 0;
   out_1313183186567530475[304] = 1;
   out_1313183186567530475[305] = 0;
   out_1313183186567530475[306] = 0;
   out_1313183186567530475[307] = 0;
   out_1313183186567530475[308] = 0;
   out_1313183186567530475[309] = 0;
   out_1313183186567530475[310] = 0;
   out_1313183186567530475[311] = 0;
   out_1313183186567530475[312] = 0;
   out_1313183186567530475[313] = 0;
   out_1313183186567530475[314] = 0;
   out_1313183186567530475[315] = 0;
   out_1313183186567530475[316] = 0;
   out_1313183186567530475[317] = 0;
   out_1313183186567530475[318] = 0;
   out_1313183186567530475[319] = 0;
   out_1313183186567530475[320] = 0;
   out_1313183186567530475[321] = 0;
   out_1313183186567530475[322] = 0;
   out_1313183186567530475[323] = 1;
}
void h_4(double *state, double *unused, double *out_717943751669182438) {
   out_717943751669182438[0] = state[6] + state[9];
   out_717943751669182438[1] = state[7] + state[10];
   out_717943751669182438[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7659548337950304093) {
   out_7659548337950304093[0] = 0;
   out_7659548337950304093[1] = 0;
   out_7659548337950304093[2] = 0;
   out_7659548337950304093[3] = 0;
   out_7659548337950304093[4] = 0;
   out_7659548337950304093[5] = 0;
   out_7659548337950304093[6] = 1;
   out_7659548337950304093[7] = 0;
   out_7659548337950304093[8] = 0;
   out_7659548337950304093[9] = 1;
   out_7659548337950304093[10] = 0;
   out_7659548337950304093[11] = 0;
   out_7659548337950304093[12] = 0;
   out_7659548337950304093[13] = 0;
   out_7659548337950304093[14] = 0;
   out_7659548337950304093[15] = 0;
   out_7659548337950304093[16] = 0;
   out_7659548337950304093[17] = 0;
   out_7659548337950304093[18] = 0;
   out_7659548337950304093[19] = 0;
   out_7659548337950304093[20] = 0;
   out_7659548337950304093[21] = 0;
   out_7659548337950304093[22] = 0;
   out_7659548337950304093[23] = 0;
   out_7659548337950304093[24] = 0;
   out_7659548337950304093[25] = 1;
   out_7659548337950304093[26] = 0;
   out_7659548337950304093[27] = 0;
   out_7659548337950304093[28] = 1;
   out_7659548337950304093[29] = 0;
   out_7659548337950304093[30] = 0;
   out_7659548337950304093[31] = 0;
   out_7659548337950304093[32] = 0;
   out_7659548337950304093[33] = 0;
   out_7659548337950304093[34] = 0;
   out_7659548337950304093[35] = 0;
   out_7659548337950304093[36] = 0;
   out_7659548337950304093[37] = 0;
   out_7659548337950304093[38] = 0;
   out_7659548337950304093[39] = 0;
   out_7659548337950304093[40] = 0;
   out_7659548337950304093[41] = 0;
   out_7659548337950304093[42] = 0;
   out_7659548337950304093[43] = 0;
   out_7659548337950304093[44] = 1;
   out_7659548337950304093[45] = 0;
   out_7659548337950304093[46] = 0;
   out_7659548337950304093[47] = 1;
   out_7659548337950304093[48] = 0;
   out_7659548337950304093[49] = 0;
   out_7659548337950304093[50] = 0;
   out_7659548337950304093[51] = 0;
   out_7659548337950304093[52] = 0;
   out_7659548337950304093[53] = 0;
}
void h_10(double *state, double *unused, double *out_5351201218378086589) {
   out_5351201218378086589[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5351201218378086589[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5351201218378086589[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5063285185285945841) {
   out_5063285185285945841[0] = 0;
   out_5063285185285945841[1] = 9.8100000000000005*cos(state[1]);
   out_5063285185285945841[2] = 0;
   out_5063285185285945841[3] = 0;
   out_5063285185285945841[4] = -state[8];
   out_5063285185285945841[5] = state[7];
   out_5063285185285945841[6] = 0;
   out_5063285185285945841[7] = state[5];
   out_5063285185285945841[8] = -state[4];
   out_5063285185285945841[9] = 0;
   out_5063285185285945841[10] = 0;
   out_5063285185285945841[11] = 0;
   out_5063285185285945841[12] = 1;
   out_5063285185285945841[13] = 0;
   out_5063285185285945841[14] = 0;
   out_5063285185285945841[15] = 1;
   out_5063285185285945841[16] = 0;
   out_5063285185285945841[17] = 0;
   out_5063285185285945841[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5063285185285945841[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5063285185285945841[20] = 0;
   out_5063285185285945841[21] = state[8];
   out_5063285185285945841[22] = 0;
   out_5063285185285945841[23] = -state[6];
   out_5063285185285945841[24] = -state[5];
   out_5063285185285945841[25] = 0;
   out_5063285185285945841[26] = state[3];
   out_5063285185285945841[27] = 0;
   out_5063285185285945841[28] = 0;
   out_5063285185285945841[29] = 0;
   out_5063285185285945841[30] = 0;
   out_5063285185285945841[31] = 1;
   out_5063285185285945841[32] = 0;
   out_5063285185285945841[33] = 0;
   out_5063285185285945841[34] = 1;
   out_5063285185285945841[35] = 0;
   out_5063285185285945841[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5063285185285945841[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5063285185285945841[38] = 0;
   out_5063285185285945841[39] = -state[7];
   out_5063285185285945841[40] = state[6];
   out_5063285185285945841[41] = 0;
   out_5063285185285945841[42] = state[4];
   out_5063285185285945841[43] = -state[3];
   out_5063285185285945841[44] = 0;
   out_5063285185285945841[45] = 0;
   out_5063285185285945841[46] = 0;
   out_5063285185285945841[47] = 0;
   out_5063285185285945841[48] = 0;
   out_5063285185285945841[49] = 0;
   out_5063285185285945841[50] = 1;
   out_5063285185285945841[51] = 0;
   out_5063285185285945841[52] = 0;
   out_5063285185285945841[53] = 1;
}
void h_13(double *state, double *unused, double *out_8511287818621351769) {
   out_8511287818621351769[0] = state[3];
   out_8511287818621351769[1] = state[4];
   out_8511287818621351769[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4447274512617971292) {
   out_4447274512617971292[0] = 0;
   out_4447274512617971292[1] = 0;
   out_4447274512617971292[2] = 0;
   out_4447274512617971292[3] = 1;
   out_4447274512617971292[4] = 0;
   out_4447274512617971292[5] = 0;
   out_4447274512617971292[6] = 0;
   out_4447274512617971292[7] = 0;
   out_4447274512617971292[8] = 0;
   out_4447274512617971292[9] = 0;
   out_4447274512617971292[10] = 0;
   out_4447274512617971292[11] = 0;
   out_4447274512617971292[12] = 0;
   out_4447274512617971292[13] = 0;
   out_4447274512617971292[14] = 0;
   out_4447274512617971292[15] = 0;
   out_4447274512617971292[16] = 0;
   out_4447274512617971292[17] = 0;
   out_4447274512617971292[18] = 0;
   out_4447274512617971292[19] = 0;
   out_4447274512617971292[20] = 0;
   out_4447274512617971292[21] = 0;
   out_4447274512617971292[22] = 1;
   out_4447274512617971292[23] = 0;
   out_4447274512617971292[24] = 0;
   out_4447274512617971292[25] = 0;
   out_4447274512617971292[26] = 0;
   out_4447274512617971292[27] = 0;
   out_4447274512617971292[28] = 0;
   out_4447274512617971292[29] = 0;
   out_4447274512617971292[30] = 0;
   out_4447274512617971292[31] = 0;
   out_4447274512617971292[32] = 0;
   out_4447274512617971292[33] = 0;
   out_4447274512617971292[34] = 0;
   out_4447274512617971292[35] = 0;
   out_4447274512617971292[36] = 0;
   out_4447274512617971292[37] = 0;
   out_4447274512617971292[38] = 0;
   out_4447274512617971292[39] = 0;
   out_4447274512617971292[40] = 0;
   out_4447274512617971292[41] = 1;
   out_4447274512617971292[42] = 0;
   out_4447274512617971292[43] = 0;
   out_4447274512617971292[44] = 0;
   out_4447274512617971292[45] = 0;
   out_4447274512617971292[46] = 0;
   out_4447274512617971292[47] = 0;
   out_4447274512617971292[48] = 0;
   out_4447274512617971292[49] = 0;
   out_4447274512617971292[50] = 0;
   out_4447274512617971292[51] = 0;
   out_4447274512617971292[52] = 0;
   out_4447274512617971292[53] = 0;
}
void h_14(double *state, double *unused, double *out_7796170631529448638) {
   out_7796170631529448638[0] = state[6];
   out_7796170631529448638[1] = state[7];
   out_7796170631529448638[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3696307481610819564) {
   out_3696307481610819564[0] = 0;
   out_3696307481610819564[1] = 0;
   out_3696307481610819564[2] = 0;
   out_3696307481610819564[3] = 0;
   out_3696307481610819564[4] = 0;
   out_3696307481610819564[5] = 0;
   out_3696307481610819564[6] = 1;
   out_3696307481610819564[7] = 0;
   out_3696307481610819564[8] = 0;
   out_3696307481610819564[9] = 0;
   out_3696307481610819564[10] = 0;
   out_3696307481610819564[11] = 0;
   out_3696307481610819564[12] = 0;
   out_3696307481610819564[13] = 0;
   out_3696307481610819564[14] = 0;
   out_3696307481610819564[15] = 0;
   out_3696307481610819564[16] = 0;
   out_3696307481610819564[17] = 0;
   out_3696307481610819564[18] = 0;
   out_3696307481610819564[19] = 0;
   out_3696307481610819564[20] = 0;
   out_3696307481610819564[21] = 0;
   out_3696307481610819564[22] = 0;
   out_3696307481610819564[23] = 0;
   out_3696307481610819564[24] = 0;
   out_3696307481610819564[25] = 1;
   out_3696307481610819564[26] = 0;
   out_3696307481610819564[27] = 0;
   out_3696307481610819564[28] = 0;
   out_3696307481610819564[29] = 0;
   out_3696307481610819564[30] = 0;
   out_3696307481610819564[31] = 0;
   out_3696307481610819564[32] = 0;
   out_3696307481610819564[33] = 0;
   out_3696307481610819564[34] = 0;
   out_3696307481610819564[35] = 0;
   out_3696307481610819564[36] = 0;
   out_3696307481610819564[37] = 0;
   out_3696307481610819564[38] = 0;
   out_3696307481610819564[39] = 0;
   out_3696307481610819564[40] = 0;
   out_3696307481610819564[41] = 0;
   out_3696307481610819564[42] = 0;
   out_3696307481610819564[43] = 0;
   out_3696307481610819564[44] = 1;
   out_3696307481610819564[45] = 0;
   out_3696307481610819564[46] = 0;
   out_3696307481610819564[47] = 0;
   out_3696307481610819564[48] = 0;
   out_3696307481610819564[49] = 0;
   out_3696307481610819564[50] = 0;
   out_3696307481610819564[51] = 0;
   out_3696307481610819564[52] = 0;
   out_3696307481610819564[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8315489890310503187) {
  err_fun(nom_x, delta_x, out_8315489890310503187);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6008596051390826841) {
  inv_err_fun(nom_x, true_x, out_6008596051390826841);
}
void pose_H_mod_fun(double *state, double *out_5634677350720166788) {
  H_mod_fun(state, out_5634677350720166788);
}
void pose_f_fun(double *state, double dt, double *out_5401222257802876036) {
  f_fun(state,  dt, out_5401222257802876036);
}
void pose_F_fun(double *state, double dt, double *out_1313183186567530475) {
  F_fun(state,  dt, out_1313183186567530475);
}
void pose_h_4(double *state, double *unused, double *out_717943751669182438) {
  h_4(state, unused, out_717943751669182438);
}
void pose_H_4(double *state, double *unused, double *out_7659548337950304093) {
  H_4(state, unused, out_7659548337950304093);
}
void pose_h_10(double *state, double *unused, double *out_5351201218378086589) {
  h_10(state, unused, out_5351201218378086589);
}
void pose_H_10(double *state, double *unused, double *out_5063285185285945841) {
  H_10(state, unused, out_5063285185285945841);
}
void pose_h_13(double *state, double *unused, double *out_8511287818621351769) {
  h_13(state, unused, out_8511287818621351769);
}
void pose_H_13(double *state, double *unused, double *out_4447274512617971292) {
  H_13(state, unused, out_4447274512617971292);
}
void pose_h_14(double *state, double *unused, double *out_7796170631529448638) {
  h_14(state, unused, out_7796170631529448638);
}
void pose_H_14(double *state, double *unused, double *out_3696307481610819564) {
  H_14(state, unused, out_3696307481610819564);
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
