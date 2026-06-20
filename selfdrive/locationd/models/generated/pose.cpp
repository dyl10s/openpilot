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
void err_fun(double *nom_x, double *delta_x, double *out_2495962770948129313) {
   out_2495962770948129313[0] = delta_x[0] + nom_x[0];
   out_2495962770948129313[1] = delta_x[1] + nom_x[1];
   out_2495962770948129313[2] = delta_x[2] + nom_x[2];
   out_2495962770948129313[3] = delta_x[3] + nom_x[3];
   out_2495962770948129313[4] = delta_x[4] + nom_x[4];
   out_2495962770948129313[5] = delta_x[5] + nom_x[5];
   out_2495962770948129313[6] = delta_x[6] + nom_x[6];
   out_2495962770948129313[7] = delta_x[7] + nom_x[7];
   out_2495962770948129313[8] = delta_x[8] + nom_x[8];
   out_2495962770948129313[9] = delta_x[9] + nom_x[9];
   out_2495962770948129313[10] = delta_x[10] + nom_x[10];
   out_2495962770948129313[11] = delta_x[11] + nom_x[11];
   out_2495962770948129313[12] = delta_x[12] + nom_x[12];
   out_2495962770948129313[13] = delta_x[13] + nom_x[13];
   out_2495962770948129313[14] = delta_x[14] + nom_x[14];
   out_2495962770948129313[15] = delta_x[15] + nom_x[15];
   out_2495962770948129313[16] = delta_x[16] + nom_x[16];
   out_2495962770948129313[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_17617025005773203) {
   out_17617025005773203[0] = -nom_x[0] + true_x[0];
   out_17617025005773203[1] = -nom_x[1] + true_x[1];
   out_17617025005773203[2] = -nom_x[2] + true_x[2];
   out_17617025005773203[3] = -nom_x[3] + true_x[3];
   out_17617025005773203[4] = -nom_x[4] + true_x[4];
   out_17617025005773203[5] = -nom_x[5] + true_x[5];
   out_17617025005773203[6] = -nom_x[6] + true_x[6];
   out_17617025005773203[7] = -nom_x[7] + true_x[7];
   out_17617025005773203[8] = -nom_x[8] + true_x[8];
   out_17617025005773203[9] = -nom_x[9] + true_x[9];
   out_17617025005773203[10] = -nom_x[10] + true_x[10];
   out_17617025005773203[11] = -nom_x[11] + true_x[11];
   out_17617025005773203[12] = -nom_x[12] + true_x[12];
   out_17617025005773203[13] = -nom_x[13] + true_x[13];
   out_17617025005773203[14] = -nom_x[14] + true_x[14];
   out_17617025005773203[15] = -nom_x[15] + true_x[15];
   out_17617025005773203[16] = -nom_x[16] + true_x[16];
   out_17617025005773203[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8533106360868564993) {
   out_8533106360868564993[0] = 1.0;
   out_8533106360868564993[1] = 0.0;
   out_8533106360868564993[2] = 0.0;
   out_8533106360868564993[3] = 0.0;
   out_8533106360868564993[4] = 0.0;
   out_8533106360868564993[5] = 0.0;
   out_8533106360868564993[6] = 0.0;
   out_8533106360868564993[7] = 0.0;
   out_8533106360868564993[8] = 0.0;
   out_8533106360868564993[9] = 0.0;
   out_8533106360868564993[10] = 0.0;
   out_8533106360868564993[11] = 0.0;
   out_8533106360868564993[12] = 0.0;
   out_8533106360868564993[13] = 0.0;
   out_8533106360868564993[14] = 0.0;
   out_8533106360868564993[15] = 0.0;
   out_8533106360868564993[16] = 0.0;
   out_8533106360868564993[17] = 0.0;
   out_8533106360868564993[18] = 0.0;
   out_8533106360868564993[19] = 1.0;
   out_8533106360868564993[20] = 0.0;
   out_8533106360868564993[21] = 0.0;
   out_8533106360868564993[22] = 0.0;
   out_8533106360868564993[23] = 0.0;
   out_8533106360868564993[24] = 0.0;
   out_8533106360868564993[25] = 0.0;
   out_8533106360868564993[26] = 0.0;
   out_8533106360868564993[27] = 0.0;
   out_8533106360868564993[28] = 0.0;
   out_8533106360868564993[29] = 0.0;
   out_8533106360868564993[30] = 0.0;
   out_8533106360868564993[31] = 0.0;
   out_8533106360868564993[32] = 0.0;
   out_8533106360868564993[33] = 0.0;
   out_8533106360868564993[34] = 0.0;
   out_8533106360868564993[35] = 0.0;
   out_8533106360868564993[36] = 0.0;
   out_8533106360868564993[37] = 0.0;
   out_8533106360868564993[38] = 1.0;
   out_8533106360868564993[39] = 0.0;
   out_8533106360868564993[40] = 0.0;
   out_8533106360868564993[41] = 0.0;
   out_8533106360868564993[42] = 0.0;
   out_8533106360868564993[43] = 0.0;
   out_8533106360868564993[44] = 0.0;
   out_8533106360868564993[45] = 0.0;
   out_8533106360868564993[46] = 0.0;
   out_8533106360868564993[47] = 0.0;
   out_8533106360868564993[48] = 0.0;
   out_8533106360868564993[49] = 0.0;
   out_8533106360868564993[50] = 0.0;
   out_8533106360868564993[51] = 0.0;
   out_8533106360868564993[52] = 0.0;
   out_8533106360868564993[53] = 0.0;
   out_8533106360868564993[54] = 0.0;
   out_8533106360868564993[55] = 0.0;
   out_8533106360868564993[56] = 0.0;
   out_8533106360868564993[57] = 1.0;
   out_8533106360868564993[58] = 0.0;
   out_8533106360868564993[59] = 0.0;
   out_8533106360868564993[60] = 0.0;
   out_8533106360868564993[61] = 0.0;
   out_8533106360868564993[62] = 0.0;
   out_8533106360868564993[63] = 0.0;
   out_8533106360868564993[64] = 0.0;
   out_8533106360868564993[65] = 0.0;
   out_8533106360868564993[66] = 0.0;
   out_8533106360868564993[67] = 0.0;
   out_8533106360868564993[68] = 0.0;
   out_8533106360868564993[69] = 0.0;
   out_8533106360868564993[70] = 0.0;
   out_8533106360868564993[71] = 0.0;
   out_8533106360868564993[72] = 0.0;
   out_8533106360868564993[73] = 0.0;
   out_8533106360868564993[74] = 0.0;
   out_8533106360868564993[75] = 0.0;
   out_8533106360868564993[76] = 1.0;
   out_8533106360868564993[77] = 0.0;
   out_8533106360868564993[78] = 0.0;
   out_8533106360868564993[79] = 0.0;
   out_8533106360868564993[80] = 0.0;
   out_8533106360868564993[81] = 0.0;
   out_8533106360868564993[82] = 0.0;
   out_8533106360868564993[83] = 0.0;
   out_8533106360868564993[84] = 0.0;
   out_8533106360868564993[85] = 0.0;
   out_8533106360868564993[86] = 0.0;
   out_8533106360868564993[87] = 0.0;
   out_8533106360868564993[88] = 0.0;
   out_8533106360868564993[89] = 0.0;
   out_8533106360868564993[90] = 0.0;
   out_8533106360868564993[91] = 0.0;
   out_8533106360868564993[92] = 0.0;
   out_8533106360868564993[93] = 0.0;
   out_8533106360868564993[94] = 0.0;
   out_8533106360868564993[95] = 1.0;
   out_8533106360868564993[96] = 0.0;
   out_8533106360868564993[97] = 0.0;
   out_8533106360868564993[98] = 0.0;
   out_8533106360868564993[99] = 0.0;
   out_8533106360868564993[100] = 0.0;
   out_8533106360868564993[101] = 0.0;
   out_8533106360868564993[102] = 0.0;
   out_8533106360868564993[103] = 0.0;
   out_8533106360868564993[104] = 0.0;
   out_8533106360868564993[105] = 0.0;
   out_8533106360868564993[106] = 0.0;
   out_8533106360868564993[107] = 0.0;
   out_8533106360868564993[108] = 0.0;
   out_8533106360868564993[109] = 0.0;
   out_8533106360868564993[110] = 0.0;
   out_8533106360868564993[111] = 0.0;
   out_8533106360868564993[112] = 0.0;
   out_8533106360868564993[113] = 0.0;
   out_8533106360868564993[114] = 1.0;
   out_8533106360868564993[115] = 0.0;
   out_8533106360868564993[116] = 0.0;
   out_8533106360868564993[117] = 0.0;
   out_8533106360868564993[118] = 0.0;
   out_8533106360868564993[119] = 0.0;
   out_8533106360868564993[120] = 0.0;
   out_8533106360868564993[121] = 0.0;
   out_8533106360868564993[122] = 0.0;
   out_8533106360868564993[123] = 0.0;
   out_8533106360868564993[124] = 0.0;
   out_8533106360868564993[125] = 0.0;
   out_8533106360868564993[126] = 0.0;
   out_8533106360868564993[127] = 0.0;
   out_8533106360868564993[128] = 0.0;
   out_8533106360868564993[129] = 0.0;
   out_8533106360868564993[130] = 0.0;
   out_8533106360868564993[131] = 0.0;
   out_8533106360868564993[132] = 0.0;
   out_8533106360868564993[133] = 1.0;
   out_8533106360868564993[134] = 0.0;
   out_8533106360868564993[135] = 0.0;
   out_8533106360868564993[136] = 0.0;
   out_8533106360868564993[137] = 0.0;
   out_8533106360868564993[138] = 0.0;
   out_8533106360868564993[139] = 0.0;
   out_8533106360868564993[140] = 0.0;
   out_8533106360868564993[141] = 0.0;
   out_8533106360868564993[142] = 0.0;
   out_8533106360868564993[143] = 0.0;
   out_8533106360868564993[144] = 0.0;
   out_8533106360868564993[145] = 0.0;
   out_8533106360868564993[146] = 0.0;
   out_8533106360868564993[147] = 0.0;
   out_8533106360868564993[148] = 0.0;
   out_8533106360868564993[149] = 0.0;
   out_8533106360868564993[150] = 0.0;
   out_8533106360868564993[151] = 0.0;
   out_8533106360868564993[152] = 1.0;
   out_8533106360868564993[153] = 0.0;
   out_8533106360868564993[154] = 0.0;
   out_8533106360868564993[155] = 0.0;
   out_8533106360868564993[156] = 0.0;
   out_8533106360868564993[157] = 0.0;
   out_8533106360868564993[158] = 0.0;
   out_8533106360868564993[159] = 0.0;
   out_8533106360868564993[160] = 0.0;
   out_8533106360868564993[161] = 0.0;
   out_8533106360868564993[162] = 0.0;
   out_8533106360868564993[163] = 0.0;
   out_8533106360868564993[164] = 0.0;
   out_8533106360868564993[165] = 0.0;
   out_8533106360868564993[166] = 0.0;
   out_8533106360868564993[167] = 0.0;
   out_8533106360868564993[168] = 0.0;
   out_8533106360868564993[169] = 0.0;
   out_8533106360868564993[170] = 0.0;
   out_8533106360868564993[171] = 1.0;
   out_8533106360868564993[172] = 0.0;
   out_8533106360868564993[173] = 0.0;
   out_8533106360868564993[174] = 0.0;
   out_8533106360868564993[175] = 0.0;
   out_8533106360868564993[176] = 0.0;
   out_8533106360868564993[177] = 0.0;
   out_8533106360868564993[178] = 0.0;
   out_8533106360868564993[179] = 0.0;
   out_8533106360868564993[180] = 0.0;
   out_8533106360868564993[181] = 0.0;
   out_8533106360868564993[182] = 0.0;
   out_8533106360868564993[183] = 0.0;
   out_8533106360868564993[184] = 0.0;
   out_8533106360868564993[185] = 0.0;
   out_8533106360868564993[186] = 0.0;
   out_8533106360868564993[187] = 0.0;
   out_8533106360868564993[188] = 0.0;
   out_8533106360868564993[189] = 0.0;
   out_8533106360868564993[190] = 1.0;
   out_8533106360868564993[191] = 0.0;
   out_8533106360868564993[192] = 0.0;
   out_8533106360868564993[193] = 0.0;
   out_8533106360868564993[194] = 0.0;
   out_8533106360868564993[195] = 0.0;
   out_8533106360868564993[196] = 0.0;
   out_8533106360868564993[197] = 0.0;
   out_8533106360868564993[198] = 0.0;
   out_8533106360868564993[199] = 0.0;
   out_8533106360868564993[200] = 0.0;
   out_8533106360868564993[201] = 0.0;
   out_8533106360868564993[202] = 0.0;
   out_8533106360868564993[203] = 0.0;
   out_8533106360868564993[204] = 0.0;
   out_8533106360868564993[205] = 0.0;
   out_8533106360868564993[206] = 0.0;
   out_8533106360868564993[207] = 0.0;
   out_8533106360868564993[208] = 0.0;
   out_8533106360868564993[209] = 1.0;
   out_8533106360868564993[210] = 0.0;
   out_8533106360868564993[211] = 0.0;
   out_8533106360868564993[212] = 0.0;
   out_8533106360868564993[213] = 0.0;
   out_8533106360868564993[214] = 0.0;
   out_8533106360868564993[215] = 0.0;
   out_8533106360868564993[216] = 0.0;
   out_8533106360868564993[217] = 0.0;
   out_8533106360868564993[218] = 0.0;
   out_8533106360868564993[219] = 0.0;
   out_8533106360868564993[220] = 0.0;
   out_8533106360868564993[221] = 0.0;
   out_8533106360868564993[222] = 0.0;
   out_8533106360868564993[223] = 0.0;
   out_8533106360868564993[224] = 0.0;
   out_8533106360868564993[225] = 0.0;
   out_8533106360868564993[226] = 0.0;
   out_8533106360868564993[227] = 0.0;
   out_8533106360868564993[228] = 1.0;
   out_8533106360868564993[229] = 0.0;
   out_8533106360868564993[230] = 0.0;
   out_8533106360868564993[231] = 0.0;
   out_8533106360868564993[232] = 0.0;
   out_8533106360868564993[233] = 0.0;
   out_8533106360868564993[234] = 0.0;
   out_8533106360868564993[235] = 0.0;
   out_8533106360868564993[236] = 0.0;
   out_8533106360868564993[237] = 0.0;
   out_8533106360868564993[238] = 0.0;
   out_8533106360868564993[239] = 0.0;
   out_8533106360868564993[240] = 0.0;
   out_8533106360868564993[241] = 0.0;
   out_8533106360868564993[242] = 0.0;
   out_8533106360868564993[243] = 0.0;
   out_8533106360868564993[244] = 0.0;
   out_8533106360868564993[245] = 0.0;
   out_8533106360868564993[246] = 0.0;
   out_8533106360868564993[247] = 1.0;
   out_8533106360868564993[248] = 0.0;
   out_8533106360868564993[249] = 0.0;
   out_8533106360868564993[250] = 0.0;
   out_8533106360868564993[251] = 0.0;
   out_8533106360868564993[252] = 0.0;
   out_8533106360868564993[253] = 0.0;
   out_8533106360868564993[254] = 0.0;
   out_8533106360868564993[255] = 0.0;
   out_8533106360868564993[256] = 0.0;
   out_8533106360868564993[257] = 0.0;
   out_8533106360868564993[258] = 0.0;
   out_8533106360868564993[259] = 0.0;
   out_8533106360868564993[260] = 0.0;
   out_8533106360868564993[261] = 0.0;
   out_8533106360868564993[262] = 0.0;
   out_8533106360868564993[263] = 0.0;
   out_8533106360868564993[264] = 0.0;
   out_8533106360868564993[265] = 0.0;
   out_8533106360868564993[266] = 1.0;
   out_8533106360868564993[267] = 0.0;
   out_8533106360868564993[268] = 0.0;
   out_8533106360868564993[269] = 0.0;
   out_8533106360868564993[270] = 0.0;
   out_8533106360868564993[271] = 0.0;
   out_8533106360868564993[272] = 0.0;
   out_8533106360868564993[273] = 0.0;
   out_8533106360868564993[274] = 0.0;
   out_8533106360868564993[275] = 0.0;
   out_8533106360868564993[276] = 0.0;
   out_8533106360868564993[277] = 0.0;
   out_8533106360868564993[278] = 0.0;
   out_8533106360868564993[279] = 0.0;
   out_8533106360868564993[280] = 0.0;
   out_8533106360868564993[281] = 0.0;
   out_8533106360868564993[282] = 0.0;
   out_8533106360868564993[283] = 0.0;
   out_8533106360868564993[284] = 0.0;
   out_8533106360868564993[285] = 1.0;
   out_8533106360868564993[286] = 0.0;
   out_8533106360868564993[287] = 0.0;
   out_8533106360868564993[288] = 0.0;
   out_8533106360868564993[289] = 0.0;
   out_8533106360868564993[290] = 0.0;
   out_8533106360868564993[291] = 0.0;
   out_8533106360868564993[292] = 0.0;
   out_8533106360868564993[293] = 0.0;
   out_8533106360868564993[294] = 0.0;
   out_8533106360868564993[295] = 0.0;
   out_8533106360868564993[296] = 0.0;
   out_8533106360868564993[297] = 0.0;
   out_8533106360868564993[298] = 0.0;
   out_8533106360868564993[299] = 0.0;
   out_8533106360868564993[300] = 0.0;
   out_8533106360868564993[301] = 0.0;
   out_8533106360868564993[302] = 0.0;
   out_8533106360868564993[303] = 0.0;
   out_8533106360868564993[304] = 1.0;
   out_8533106360868564993[305] = 0.0;
   out_8533106360868564993[306] = 0.0;
   out_8533106360868564993[307] = 0.0;
   out_8533106360868564993[308] = 0.0;
   out_8533106360868564993[309] = 0.0;
   out_8533106360868564993[310] = 0.0;
   out_8533106360868564993[311] = 0.0;
   out_8533106360868564993[312] = 0.0;
   out_8533106360868564993[313] = 0.0;
   out_8533106360868564993[314] = 0.0;
   out_8533106360868564993[315] = 0.0;
   out_8533106360868564993[316] = 0.0;
   out_8533106360868564993[317] = 0.0;
   out_8533106360868564993[318] = 0.0;
   out_8533106360868564993[319] = 0.0;
   out_8533106360868564993[320] = 0.0;
   out_8533106360868564993[321] = 0.0;
   out_8533106360868564993[322] = 0.0;
   out_8533106360868564993[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5731605766251141681) {
   out_5731605766251141681[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5731605766251141681[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5731605766251141681[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5731605766251141681[3] = dt*state[12] + state[3];
   out_5731605766251141681[4] = dt*state[13] + state[4];
   out_5731605766251141681[5] = dt*state[14] + state[5];
   out_5731605766251141681[6] = state[6];
   out_5731605766251141681[7] = state[7];
   out_5731605766251141681[8] = state[8];
   out_5731605766251141681[9] = state[9];
   out_5731605766251141681[10] = state[10];
   out_5731605766251141681[11] = state[11];
   out_5731605766251141681[12] = state[12];
   out_5731605766251141681[13] = state[13];
   out_5731605766251141681[14] = state[14];
   out_5731605766251141681[15] = state[15];
   out_5731605766251141681[16] = state[16];
   out_5731605766251141681[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3989820231164300868) {
   out_3989820231164300868[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3989820231164300868[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3989820231164300868[2] = 0;
   out_3989820231164300868[3] = 0;
   out_3989820231164300868[4] = 0;
   out_3989820231164300868[5] = 0;
   out_3989820231164300868[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3989820231164300868[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3989820231164300868[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3989820231164300868[9] = 0;
   out_3989820231164300868[10] = 0;
   out_3989820231164300868[11] = 0;
   out_3989820231164300868[12] = 0;
   out_3989820231164300868[13] = 0;
   out_3989820231164300868[14] = 0;
   out_3989820231164300868[15] = 0;
   out_3989820231164300868[16] = 0;
   out_3989820231164300868[17] = 0;
   out_3989820231164300868[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3989820231164300868[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3989820231164300868[20] = 0;
   out_3989820231164300868[21] = 0;
   out_3989820231164300868[22] = 0;
   out_3989820231164300868[23] = 0;
   out_3989820231164300868[24] = 0;
   out_3989820231164300868[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3989820231164300868[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3989820231164300868[27] = 0;
   out_3989820231164300868[28] = 0;
   out_3989820231164300868[29] = 0;
   out_3989820231164300868[30] = 0;
   out_3989820231164300868[31] = 0;
   out_3989820231164300868[32] = 0;
   out_3989820231164300868[33] = 0;
   out_3989820231164300868[34] = 0;
   out_3989820231164300868[35] = 0;
   out_3989820231164300868[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3989820231164300868[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3989820231164300868[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3989820231164300868[39] = 0;
   out_3989820231164300868[40] = 0;
   out_3989820231164300868[41] = 0;
   out_3989820231164300868[42] = 0;
   out_3989820231164300868[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3989820231164300868[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3989820231164300868[45] = 0;
   out_3989820231164300868[46] = 0;
   out_3989820231164300868[47] = 0;
   out_3989820231164300868[48] = 0;
   out_3989820231164300868[49] = 0;
   out_3989820231164300868[50] = 0;
   out_3989820231164300868[51] = 0;
   out_3989820231164300868[52] = 0;
   out_3989820231164300868[53] = 0;
   out_3989820231164300868[54] = 0;
   out_3989820231164300868[55] = 0;
   out_3989820231164300868[56] = 0;
   out_3989820231164300868[57] = 1;
   out_3989820231164300868[58] = 0;
   out_3989820231164300868[59] = 0;
   out_3989820231164300868[60] = 0;
   out_3989820231164300868[61] = 0;
   out_3989820231164300868[62] = 0;
   out_3989820231164300868[63] = 0;
   out_3989820231164300868[64] = 0;
   out_3989820231164300868[65] = 0;
   out_3989820231164300868[66] = dt;
   out_3989820231164300868[67] = 0;
   out_3989820231164300868[68] = 0;
   out_3989820231164300868[69] = 0;
   out_3989820231164300868[70] = 0;
   out_3989820231164300868[71] = 0;
   out_3989820231164300868[72] = 0;
   out_3989820231164300868[73] = 0;
   out_3989820231164300868[74] = 0;
   out_3989820231164300868[75] = 0;
   out_3989820231164300868[76] = 1;
   out_3989820231164300868[77] = 0;
   out_3989820231164300868[78] = 0;
   out_3989820231164300868[79] = 0;
   out_3989820231164300868[80] = 0;
   out_3989820231164300868[81] = 0;
   out_3989820231164300868[82] = 0;
   out_3989820231164300868[83] = 0;
   out_3989820231164300868[84] = 0;
   out_3989820231164300868[85] = dt;
   out_3989820231164300868[86] = 0;
   out_3989820231164300868[87] = 0;
   out_3989820231164300868[88] = 0;
   out_3989820231164300868[89] = 0;
   out_3989820231164300868[90] = 0;
   out_3989820231164300868[91] = 0;
   out_3989820231164300868[92] = 0;
   out_3989820231164300868[93] = 0;
   out_3989820231164300868[94] = 0;
   out_3989820231164300868[95] = 1;
   out_3989820231164300868[96] = 0;
   out_3989820231164300868[97] = 0;
   out_3989820231164300868[98] = 0;
   out_3989820231164300868[99] = 0;
   out_3989820231164300868[100] = 0;
   out_3989820231164300868[101] = 0;
   out_3989820231164300868[102] = 0;
   out_3989820231164300868[103] = 0;
   out_3989820231164300868[104] = dt;
   out_3989820231164300868[105] = 0;
   out_3989820231164300868[106] = 0;
   out_3989820231164300868[107] = 0;
   out_3989820231164300868[108] = 0;
   out_3989820231164300868[109] = 0;
   out_3989820231164300868[110] = 0;
   out_3989820231164300868[111] = 0;
   out_3989820231164300868[112] = 0;
   out_3989820231164300868[113] = 0;
   out_3989820231164300868[114] = 1;
   out_3989820231164300868[115] = 0;
   out_3989820231164300868[116] = 0;
   out_3989820231164300868[117] = 0;
   out_3989820231164300868[118] = 0;
   out_3989820231164300868[119] = 0;
   out_3989820231164300868[120] = 0;
   out_3989820231164300868[121] = 0;
   out_3989820231164300868[122] = 0;
   out_3989820231164300868[123] = 0;
   out_3989820231164300868[124] = 0;
   out_3989820231164300868[125] = 0;
   out_3989820231164300868[126] = 0;
   out_3989820231164300868[127] = 0;
   out_3989820231164300868[128] = 0;
   out_3989820231164300868[129] = 0;
   out_3989820231164300868[130] = 0;
   out_3989820231164300868[131] = 0;
   out_3989820231164300868[132] = 0;
   out_3989820231164300868[133] = 1;
   out_3989820231164300868[134] = 0;
   out_3989820231164300868[135] = 0;
   out_3989820231164300868[136] = 0;
   out_3989820231164300868[137] = 0;
   out_3989820231164300868[138] = 0;
   out_3989820231164300868[139] = 0;
   out_3989820231164300868[140] = 0;
   out_3989820231164300868[141] = 0;
   out_3989820231164300868[142] = 0;
   out_3989820231164300868[143] = 0;
   out_3989820231164300868[144] = 0;
   out_3989820231164300868[145] = 0;
   out_3989820231164300868[146] = 0;
   out_3989820231164300868[147] = 0;
   out_3989820231164300868[148] = 0;
   out_3989820231164300868[149] = 0;
   out_3989820231164300868[150] = 0;
   out_3989820231164300868[151] = 0;
   out_3989820231164300868[152] = 1;
   out_3989820231164300868[153] = 0;
   out_3989820231164300868[154] = 0;
   out_3989820231164300868[155] = 0;
   out_3989820231164300868[156] = 0;
   out_3989820231164300868[157] = 0;
   out_3989820231164300868[158] = 0;
   out_3989820231164300868[159] = 0;
   out_3989820231164300868[160] = 0;
   out_3989820231164300868[161] = 0;
   out_3989820231164300868[162] = 0;
   out_3989820231164300868[163] = 0;
   out_3989820231164300868[164] = 0;
   out_3989820231164300868[165] = 0;
   out_3989820231164300868[166] = 0;
   out_3989820231164300868[167] = 0;
   out_3989820231164300868[168] = 0;
   out_3989820231164300868[169] = 0;
   out_3989820231164300868[170] = 0;
   out_3989820231164300868[171] = 1;
   out_3989820231164300868[172] = 0;
   out_3989820231164300868[173] = 0;
   out_3989820231164300868[174] = 0;
   out_3989820231164300868[175] = 0;
   out_3989820231164300868[176] = 0;
   out_3989820231164300868[177] = 0;
   out_3989820231164300868[178] = 0;
   out_3989820231164300868[179] = 0;
   out_3989820231164300868[180] = 0;
   out_3989820231164300868[181] = 0;
   out_3989820231164300868[182] = 0;
   out_3989820231164300868[183] = 0;
   out_3989820231164300868[184] = 0;
   out_3989820231164300868[185] = 0;
   out_3989820231164300868[186] = 0;
   out_3989820231164300868[187] = 0;
   out_3989820231164300868[188] = 0;
   out_3989820231164300868[189] = 0;
   out_3989820231164300868[190] = 1;
   out_3989820231164300868[191] = 0;
   out_3989820231164300868[192] = 0;
   out_3989820231164300868[193] = 0;
   out_3989820231164300868[194] = 0;
   out_3989820231164300868[195] = 0;
   out_3989820231164300868[196] = 0;
   out_3989820231164300868[197] = 0;
   out_3989820231164300868[198] = 0;
   out_3989820231164300868[199] = 0;
   out_3989820231164300868[200] = 0;
   out_3989820231164300868[201] = 0;
   out_3989820231164300868[202] = 0;
   out_3989820231164300868[203] = 0;
   out_3989820231164300868[204] = 0;
   out_3989820231164300868[205] = 0;
   out_3989820231164300868[206] = 0;
   out_3989820231164300868[207] = 0;
   out_3989820231164300868[208] = 0;
   out_3989820231164300868[209] = 1;
   out_3989820231164300868[210] = 0;
   out_3989820231164300868[211] = 0;
   out_3989820231164300868[212] = 0;
   out_3989820231164300868[213] = 0;
   out_3989820231164300868[214] = 0;
   out_3989820231164300868[215] = 0;
   out_3989820231164300868[216] = 0;
   out_3989820231164300868[217] = 0;
   out_3989820231164300868[218] = 0;
   out_3989820231164300868[219] = 0;
   out_3989820231164300868[220] = 0;
   out_3989820231164300868[221] = 0;
   out_3989820231164300868[222] = 0;
   out_3989820231164300868[223] = 0;
   out_3989820231164300868[224] = 0;
   out_3989820231164300868[225] = 0;
   out_3989820231164300868[226] = 0;
   out_3989820231164300868[227] = 0;
   out_3989820231164300868[228] = 1;
   out_3989820231164300868[229] = 0;
   out_3989820231164300868[230] = 0;
   out_3989820231164300868[231] = 0;
   out_3989820231164300868[232] = 0;
   out_3989820231164300868[233] = 0;
   out_3989820231164300868[234] = 0;
   out_3989820231164300868[235] = 0;
   out_3989820231164300868[236] = 0;
   out_3989820231164300868[237] = 0;
   out_3989820231164300868[238] = 0;
   out_3989820231164300868[239] = 0;
   out_3989820231164300868[240] = 0;
   out_3989820231164300868[241] = 0;
   out_3989820231164300868[242] = 0;
   out_3989820231164300868[243] = 0;
   out_3989820231164300868[244] = 0;
   out_3989820231164300868[245] = 0;
   out_3989820231164300868[246] = 0;
   out_3989820231164300868[247] = 1;
   out_3989820231164300868[248] = 0;
   out_3989820231164300868[249] = 0;
   out_3989820231164300868[250] = 0;
   out_3989820231164300868[251] = 0;
   out_3989820231164300868[252] = 0;
   out_3989820231164300868[253] = 0;
   out_3989820231164300868[254] = 0;
   out_3989820231164300868[255] = 0;
   out_3989820231164300868[256] = 0;
   out_3989820231164300868[257] = 0;
   out_3989820231164300868[258] = 0;
   out_3989820231164300868[259] = 0;
   out_3989820231164300868[260] = 0;
   out_3989820231164300868[261] = 0;
   out_3989820231164300868[262] = 0;
   out_3989820231164300868[263] = 0;
   out_3989820231164300868[264] = 0;
   out_3989820231164300868[265] = 0;
   out_3989820231164300868[266] = 1;
   out_3989820231164300868[267] = 0;
   out_3989820231164300868[268] = 0;
   out_3989820231164300868[269] = 0;
   out_3989820231164300868[270] = 0;
   out_3989820231164300868[271] = 0;
   out_3989820231164300868[272] = 0;
   out_3989820231164300868[273] = 0;
   out_3989820231164300868[274] = 0;
   out_3989820231164300868[275] = 0;
   out_3989820231164300868[276] = 0;
   out_3989820231164300868[277] = 0;
   out_3989820231164300868[278] = 0;
   out_3989820231164300868[279] = 0;
   out_3989820231164300868[280] = 0;
   out_3989820231164300868[281] = 0;
   out_3989820231164300868[282] = 0;
   out_3989820231164300868[283] = 0;
   out_3989820231164300868[284] = 0;
   out_3989820231164300868[285] = 1;
   out_3989820231164300868[286] = 0;
   out_3989820231164300868[287] = 0;
   out_3989820231164300868[288] = 0;
   out_3989820231164300868[289] = 0;
   out_3989820231164300868[290] = 0;
   out_3989820231164300868[291] = 0;
   out_3989820231164300868[292] = 0;
   out_3989820231164300868[293] = 0;
   out_3989820231164300868[294] = 0;
   out_3989820231164300868[295] = 0;
   out_3989820231164300868[296] = 0;
   out_3989820231164300868[297] = 0;
   out_3989820231164300868[298] = 0;
   out_3989820231164300868[299] = 0;
   out_3989820231164300868[300] = 0;
   out_3989820231164300868[301] = 0;
   out_3989820231164300868[302] = 0;
   out_3989820231164300868[303] = 0;
   out_3989820231164300868[304] = 1;
   out_3989820231164300868[305] = 0;
   out_3989820231164300868[306] = 0;
   out_3989820231164300868[307] = 0;
   out_3989820231164300868[308] = 0;
   out_3989820231164300868[309] = 0;
   out_3989820231164300868[310] = 0;
   out_3989820231164300868[311] = 0;
   out_3989820231164300868[312] = 0;
   out_3989820231164300868[313] = 0;
   out_3989820231164300868[314] = 0;
   out_3989820231164300868[315] = 0;
   out_3989820231164300868[316] = 0;
   out_3989820231164300868[317] = 0;
   out_3989820231164300868[318] = 0;
   out_3989820231164300868[319] = 0;
   out_3989820231164300868[320] = 0;
   out_3989820231164300868[321] = 0;
   out_3989820231164300868[322] = 0;
   out_3989820231164300868[323] = 1;
}
void h_4(double *state, double *unused, double *out_4946255089901338531) {
   out_4946255089901338531[0] = state[6] + state[9];
   out_4946255089901338531[1] = state[7] + state[10];
   out_4946255089901338531[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8715690230958088519) {
   out_8715690230958088519[0] = 0;
   out_8715690230958088519[1] = 0;
   out_8715690230958088519[2] = 0;
   out_8715690230958088519[3] = 0;
   out_8715690230958088519[4] = 0;
   out_8715690230958088519[5] = 0;
   out_8715690230958088519[6] = 1;
   out_8715690230958088519[7] = 0;
   out_8715690230958088519[8] = 0;
   out_8715690230958088519[9] = 1;
   out_8715690230958088519[10] = 0;
   out_8715690230958088519[11] = 0;
   out_8715690230958088519[12] = 0;
   out_8715690230958088519[13] = 0;
   out_8715690230958088519[14] = 0;
   out_8715690230958088519[15] = 0;
   out_8715690230958088519[16] = 0;
   out_8715690230958088519[17] = 0;
   out_8715690230958088519[18] = 0;
   out_8715690230958088519[19] = 0;
   out_8715690230958088519[20] = 0;
   out_8715690230958088519[21] = 0;
   out_8715690230958088519[22] = 0;
   out_8715690230958088519[23] = 0;
   out_8715690230958088519[24] = 0;
   out_8715690230958088519[25] = 1;
   out_8715690230958088519[26] = 0;
   out_8715690230958088519[27] = 0;
   out_8715690230958088519[28] = 1;
   out_8715690230958088519[29] = 0;
   out_8715690230958088519[30] = 0;
   out_8715690230958088519[31] = 0;
   out_8715690230958088519[32] = 0;
   out_8715690230958088519[33] = 0;
   out_8715690230958088519[34] = 0;
   out_8715690230958088519[35] = 0;
   out_8715690230958088519[36] = 0;
   out_8715690230958088519[37] = 0;
   out_8715690230958088519[38] = 0;
   out_8715690230958088519[39] = 0;
   out_8715690230958088519[40] = 0;
   out_8715690230958088519[41] = 0;
   out_8715690230958088519[42] = 0;
   out_8715690230958088519[43] = 0;
   out_8715690230958088519[44] = 1;
   out_8715690230958088519[45] = 0;
   out_8715690230958088519[46] = 0;
   out_8715690230958088519[47] = 1;
   out_8715690230958088519[48] = 0;
   out_8715690230958088519[49] = 0;
   out_8715690230958088519[50] = 0;
   out_8715690230958088519[51] = 0;
   out_8715690230958088519[52] = 0;
   out_8715690230958088519[53] = 0;
}
void h_10(double *state, double *unused, double *out_1122773854384552196) {
   out_1122773854384552196[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1122773854384552196[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1122773854384552196[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5712996006774124697) {
   out_5712996006774124697[0] = 0;
   out_5712996006774124697[1] = 9.8100000000000005*cos(state[1]);
   out_5712996006774124697[2] = 0;
   out_5712996006774124697[3] = 0;
   out_5712996006774124697[4] = -state[8];
   out_5712996006774124697[5] = state[7];
   out_5712996006774124697[6] = 0;
   out_5712996006774124697[7] = state[5];
   out_5712996006774124697[8] = -state[4];
   out_5712996006774124697[9] = 0;
   out_5712996006774124697[10] = 0;
   out_5712996006774124697[11] = 0;
   out_5712996006774124697[12] = 1;
   out_5712996006774124697[13] = 0;
   out_5712996006774124697[14] = 0;
   out_5712996006774124697[15] = 1;
   out_5712996006774124697[16] = 0;
   out_5712996006774124697[17] = 0;
   out_5712996006774124697[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5712996006774124697[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5712996006774124697[20] = 0;
   out_5712996006774124697[21] = state[8];
   out_5712996006774124697[22] = 0;
   out_5712996006774124697[23] = -state[6];
   out_5712996006774124697[24] = -state[5];
   out_5712996006774124697[25] = 0;
   out_5712996006774124697[26] = state[3];
   out_5712996006774124697[27] = 0;
   out_5712996006774124697[28] = 0;
   out_5712996006774124697[29] = 0;
   out_5712996006774124697[30] = 0;
   out_5712996006774124697[31] = 1;
   out_5712996006774124697[32] = 0;
   out_5712996006774124697[33] = 0;
   out_5712996006774124697[34] = 1;
   out_5712996006774124697[35] = 0;
   out_5712996006774124697[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5712996006774124697[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5712996006774124697[38] = 0;
   out_5712996006774124697[39] = -state[7];
   out_5712996006774124697[40] = state[6];
   out_5712996006774124697[41] = 0;
   out_5712996006774124697[42] = state[4];
   out_5712996006774124697[43] = -state[3];
   out_5712996006774124697[44] = 0;
   out_5712996006774124697[45] = 0;
   out_5712996006774124697[46] = 0;
   out_5712996006774124697[47] = 0;
   out_5712996006774124697[48] = 0;
   out_5712996006774124697[49] = 0;
   out_5712996006774124697[50] = 1;
   out_5712996006774124697[51] = 0;
   out_5712996006774124697[52] = 0;
   out_5712996006774124697[53] = 1;
}
void h_13(double *state, double *unused, double *out_1411072044725156723) {
   out_1411072044725156723[0] = state[3];
   out_1411072044725156723[1] = state[4];
   out_1411072044725156723[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5503416405625755718) {
   out_5503416405625755718[0] = 0;
   out_5503416405625755718[1] = 0;
   out_5503416405625755718[2] = 0;
   out_5503416405625755718[3] = 1;
   out_5503416405625755718[4] = 0;
   out_5503416405625755718[5] = 0;
   out_5503416405625755718[6] = 0;
   out_5503416405625755718[7] = 0;
   out_5503416405625755718[8] = 0;
   out_5503416405625755718[9] = 0;
   out_5503416405625755718[10] = 0;
   out_5503416405625755718[11] = 0;
   out_5503416405625755718[12] = 0;
   out_5503416405625755718[13] = 0;
   out_5503416405625755718[14] = 0;
   out_5503416405625755718[15] = 0;
   out_5503416405625755718[16] = 0;
   out_5503416405625755718[17] = 0;
   out_5503416405625755718[18] = 0;
   out_5503416405625755718[19] = 0;
   out_5503416405625755718[20] = 0;
   out_5503416405625755718[21] = 0;
   out_5503416405625755718[22] = 1;
   out_5503416405625755718[23] = 0;
   out_5503416405625755718[24] = 0;
   out_5503416405625755718[25] = 0;
   out_5503416405625755718[26] = 0;
   out_5503416405625755718[27] = 0;
   out_5503416405625755718[28] = 0;
   out_5503416405625755718[29] = 0;
   out_5503416405625755718[30] = 0;
   out_5503416405625755718[31] = 0;
   out_5503416405625755718[32] = 0;
   out_5503416405625755718[33] = 0;
   out_5503416405625755718[34] = 0;
   out_5503416405625755718[35] = 0;
   out_5503416405625755718[36] = 0;
   out_5503416405625755718[37] = 0;
   out_5503416405625755718[38] = 0;
   out_5503416405625755718[39] = 0;
   out_5503416405625755718[40] = 0;
   out_5503416405625755718[41] = 1;
   out_5503416405625755718[42] = 0;
   out_5503416405625755718[43] = 0;
   out_5503416405625755718[44] = 0;
   out_5503416405625755718[45] = 0;
   out_5503416405625755718[46] = 0;
   out_5503416405625755718[47] = 0;
   out_5503416405625755718[48] = 0;
   out_5503416405625755718[49] = 0;
   out_5503416405625755718[50] = 0;
   out_5503416405625755718[51] = 0;
   out_5503416405625755718[52] = 0;
   out_5503416405625755718[53] = 0;
}
void h_14(double *state, double *unused, double *out_2642104827226322779) {
   out_2642104827226322779[0] = state[6];
   out_2642104827226322779[1] = state[7];
   out_2642104827226322779[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2249908027471722673) {
   out_2249908027471722673[0] = 0;
   out_2249908027471722673[1] = 0;
   out_2249908027471722673[2] = 0;
   out_2249908027471722673[3] = 0;
   out_2249908027471722673[4] = 0;
   out_2249908027471722673[5] = 0;
   out_2249908027471722673[6] = 1;
   out_2249908027471722673[7] = 0;
   out_2249908027471722673[8] = 0;
   out_2249908027471722673[9] = 0;
   out_2249908027471722673[10] = 0;
   out_2249908027471722673[11] = 0;
   out_2249908027471722673[12] = 0;
   out_2249908027471722673[13] = 0;
   out_2249908027471722673[14] = 0;
   out_2249908027471722673[15] = 0;
   out_2249908027471722673[16] = 0;
   out_2249908027471722673[17] = 0;
   out_2249908027471722673[18] = 0;
   out_2249908027471722673[19] = 0;
   out_2249908027471722673[20] = 0;
   out_2249908027471722673[21] = 0;
   out_2249908027471722673[22] = 0;
   out_2249908027471722673[23] = 0;
   out_2249908027471722673[24] = 0;
   out_2249908027471722673[25] = 1;
   out_2249908027471722673[26] = 0;
   out_2249908027471722673[27] = 0;
   out_2249908027471722673[28] = 0;
   out_2249908027471722673[29] = 0;
   out_2249908027471722673[30] = 0;
   out_2249908027471722673[31] = 0;
   out_2249908027471722673[32] = 0;
   out_2249908027471722673[33] = 0;
   out_2249908027471722673[34] = 0;
   out_2249908027471722673[35] = 0;
   out_2249908027471722673[36] = 0;
   out_2249908027471722673[37] = 0;
   out_2249908027471722673[38] = 0;
   out_2249908027471722673[39] = 0;
   out_2249908027471722673[40] = 0;
   out_2249908027471722673[41] = 0;
   out_2249908027471722673[42] = 0;
   out_2249908027471722673[43] = 0;
   out_2249908027471722673[44] = 1;
   out_2249908027471722673[45] = 0;
   out_2249908027471722673[46] = 0;
   out_2249908027471722673[47] = 0;
   out_2249908027471722673[48] = 0;
   out_2249908027471722673[49] = 0;
   out_2249908027471722673[50] = 0;
   out_2249908027471722673[51] = 0;
   out_2249908027471722673[52] = 0;
   out_2249908027471722673[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2495962770948129313) {
  err_fun(nom_x, delta_x, out_2495962770948129313);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_17617025005773203) {
  inv_err_fun(nom_x, true_x, out_17617025005773203);
}
void pose_H_mod_fun(double *state, double *out_8533106360868564993) {
  H_mod_fun(state, out_8533106360868564993);
}
void pose_f_fun(double *state, double dt, double *out_5731605766251141681) {
  f_fun(state,  dt, out_5731605766251141681);
}
void pose_F_fun(double *state, double dt, double *out_3989820231164300868) {
  F_fun(state,  dt, out_3989820231164300868);
}
void pose_h_4(double *state, double *unused, double *out_4946255089901338531) {
  h_4(state, unused, out_4946255089901338531);
}
void pose_H_4(double *state, double *unused, double *out_8715690230958088519) {
  H_4(state, unused, out_8715690230958088519);
}
void pose_h_10(double *state, double *unused, double *out_1122773854384552196) {
  h_10(state, unused, out_1122773854384552196);
}
void pose_H_10(double *state, double *unused, double *out_5712996006774124697) {
  H_10(state, unused, out_5712996006774124697);
}
void pose_h_13(double *state, double *unused, double *out_1411072044725156723) {
  h_13(state, unused, out_1411072044725156723);
}
void pose_H_13(double *state, double *unused, double *out_5503416405625755718) {
  H_13(state, unused, out_5503416405625755718);
}
void pose_h_14(double *state, double *unused, double *out_2642104827226322779) {
  h_14(state, unused, out_2642104827226322779);
}
void pose_H_14(double *state, double *unused, double *out_2249908027471722673) {
  H_14(state, unused, out_2249908027471722673);
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
