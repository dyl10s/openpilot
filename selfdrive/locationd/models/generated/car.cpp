#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7715085255157723284) {
   out_7715085255157723284[0] = delta_x[0] + nom_x[0];
   out_7715085255157723284[1] = delta_x[1] + nom_x[1];
   out_7715085255157723284[2] = delta_x[2] + nom_x[2];
   out_7715085255157723284[3] = delta_x[3] + nom_x[3];
   out_7715085255157723284[4] = delta_x[4] + nom_x[4];
   out_7715085255157723284[5] = delta_x[5] + nom_x[5];
   out_7715085255157723284[6] = delta_x[6] + nom_x[6];
   out_7715085255157723284[7] = delta_x[7] + nom_x[7];
   out_7715085255157723284[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3139976914443091875) {
   out_3139976914443091875[0] = -nom_x[0] + true_x[0];
   out_3139976914443091875[1] = -nom_x[1] + true_x[1];
   out_3139976914443091875[2] = -nom_x[2] + true_x[2];
   out_3139976914443091875[3] = -nom_x[3] + true_x[3];
   out_3139976914443091875[4] = -nom_x[4] + true_x[4];
   out_3139976914443091875[5] = -nom_x[5] + true_x[5];
   out_3139976914443091875[6] = -nom_x[6] + true_x[6];
   out_3139976914443091875[7] = -nom_x[7] + true_x[7];
   out_3139976914443091875[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3564524246730987791) {
   out_3564524246730987791[0] = 1.0;
   out_3564524246730987791[1] = 0.0;
   out_3564524246730987791[2] = 0.0;
   out_3564524246730987791[3] = 0.0;
   out_3564524246730987791[4] = 0.0;
   out_3564524246730987791[5] = 0.0;
   out_3564524246730987791[6] = 0.0;
   out_3564524246730987791[7] = 0.0;
   out_3564524246730987791[8] = 0.0;
   out_3564524246730987791[9] = 0.0;
   out_3564524246730987791[10] = 1.0;
   out_3564524246730987791[11] = 0.0;
   out_3564524246730987791[12] = 0.0;
   out_3564524246730987791[13] = 0.0;
   out_3564524246730987791[14] = 0.0;
   out_3564524246730987791[15] = 0.0;
   out_3564524246730987791[16] = 0.0;
   out_3564524246730987791[17] = 0.0;
   out_3564524246730987791[18] = 0.0;
   out_3564524246730987791[19] = 0.0;
   out_3564524246730987791[20] = 1.0;
   out_3564524246730987791[21] = 0.0;
   out_3564524246730987791[22] = 0.0;
   out_3564524246730987791[23] = 0.0;
   out_3564524246730987791[24] = 0.0;
   out_3564524246730987791[25] = 0.0;
   out_3564524246730987791[26] = 0.0;
   out_3564524246730987791[27] = 0.0;
   out_3564524246730987791[28] = 0.0;
   out_3564524246730987791[29] = 0.0;
   out_3564524246730987791[30] = 1.0;
   out_3564524246730987791[31] = 0.0;
   out_3564524246730987791[32] = 0.0;
   out_3564524246730987791[33] = 0.0;
   out_3564524246730987791[34] = 0.0;
   out_3564524246730987791[35] = 0.0;
   out_3564524246730987791[36] = 0.0;
   out_3564524246730987791[37] = 0.0;
   out_3564524246730987791[38] = 0.0;
   out_3564524246730987791[39] = 0.0;
   out_3564524246730987791[40] = 1.0;
   out_3564524246730987791[41] = 0.0;
   out_3564524246730987791[42] = 0.0;
   out_3564524246730987791[43] = 0.0;
   out_3564524246730987791[44] = 0.0;
   out_3564524246730987791[45] = 0.0;
   out_3564524246730987791[46] = 0.0;
   out_3564524246730987791[47] = 0.0;
   out_3564524246730987791[48] = 0.0;
   out_3564524246730987791[49] = 0.0;
   out_3564524246730987791[50] = 1.0;
   out_3564524246730987791[51] = 0.0;
   out_3564524246730987791[52] = 0.0;
   out_3564524246730987791[53] = 0.0;
   out_3564524246730987791[54] = 0.0;
   out_3564524246730987791[55] = 0.0;
   out_3564524246730987791[56] = 0.0;
   out_3564524246730987791[57] = 0.0;
   out_3564524246730987791[58] = 0.0;
   out_3564524246730987791[59] = 0.0;
   out_3564524246730987791[60] = 1.0;
   out_3564524246730987791[61] = 0.0;
   out_3564524246730987791[62] = 0.0;
   out_3564524246730987791[63] = 0.0;
   out_3564524246730987791[64] = 0.0;
   out_3564524246730987791[65] = 0.0;
   out_3564524246730987791[66] = 0.0;
   out_3564524246730987791[67] = 0.0;
   out_3564524246730987791[68] = 0.0;
   out_3564524246730987791[69] = 0.0;
   out_3564524246730987791[70] = 1.0;
   out_3564524246730987791[71] = 0.0;
   out_3564524246730987791[72] = 0.0;
   out_3564524246730987791[73] = 0.0;
   out_3564524246730987791[74] = 0.0;
   out_3564524246730987791[75] = 0.0;
   out_3564524246730987791[76] = 0.0;
   out_3564524246730987791[77] = 0.0;
   out_3564524246730987791[78] = 0.0;
   out_3564524246730987791[79] = 0.0;
   out_3564524246730987791[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_9199042254253526234) {
   out_9199042254253526234[0] = state[0];
   out_9199042254253526234[1] = state[1];
   out_9199042254253526234[2] = state[2];
   out_9199042254253526234[3] = state[3];
   out_9199042254253526234[4] = state[4];
   out_9199042254253526234[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_9199042254253526234[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_9199042254253526234[7] = state[7];
   out_9199042254253526234[8] = state[8];
}
void F_fun(double *state, double dt, double *out_606899119426091544) {
   out_606899119426091544[0] = 1;
   out_606899119426091544[1] = 0;
   out_606899119426091544[2] = 0;
   out_606899119426091544[3] = 0;
   out_606899119426091544[4] = 0;
   out_606899119426091544[5] = 0;
   out_606899119426091544[6] = 0;
   out_606899119426091544[7] = 0;
   out_606899119426091544[8] = 0;
   out_606899119426091544[9] = 0;
   out_606899119426091544[10] = 1;
   out_606899119426091544[11] = 0;
   out_606899119426091544[12] = 0;
   out_606899119426091544[13] = 0;
   out_606899119426091544[14] = 0;
   out_606899119426091544[15] = 0;
   out_606899119426091544[16] = 0;
   out_606899119426091544[17] = 0;
   out_606899119426091544[18] = 0;
   out_606899119426091544[19] = 0;
   out_606899119426091544[20] = 1;
   out_606899119426091544[21] = 0;
   out_606899119426091544[22] = 0;
   out_606899119426091544[23] = 0;
   out_606899119426091544[24] = 0;
   out_606899119426091544[25] = 0;
   out_606899119426091544[26] = 0;
   out_606899119426091544[27] = 0;
   out_606899119426091544[28] = 0;
   out_606899119426091544[29] = 0;
   out_606899119426091544[30] = 1;
   out_606899119426091544[31] = 0;
   out_606899119426091544[32] = 0;
   out_606899119426091544[33] = 0;
   out_606899119426091544[34] = 0;
   out_606899119426091544[35] = 0;
   out_606899119426091544[36] = 0;
   out_606899119426091544[37] = 0;
   out_606899119426091544[38] = 0;
   out_606899119426091544[39] = 0;
   out_606899119426091544[40] = 1;
   out_606899119426091544[41] = 0;
   out_606899119426091544[42] = 0;
   out_606899119426091544[43] = 0;
   out_606899119426091544[44] = 0;
   out_606899119426091544[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_606899119426091544[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_606899119426091544[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_606899119426091544[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_606899119426091544[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_606899119426091544[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_606899119426091544[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_606899119426091544[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_606899119426091544[53] = -9.8100000000000005*dt;
   out_606899119426091544[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_606899119426091544[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_606899119426091544[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_606899119426091544[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_606899119426091544[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_606899119426091544[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_606899119426091544[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_606899119426091544[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_606899119426091544[62] = 0;
   out_606899119426091544[63] = 0;
   out_606899119426091544[64] = 0;
   out_606899119426091544[65] = 0;
   out_606899119426091544[66] = 0;
   out_606899119426091544[67] = 0;
   out_606899119426091544[68] = 0;
   out_606899119426091544[69] = 0;
   out_606899119426091544[70] = 1;
   out_606899119426091544[71] = 0;
   out_606899119426091544[72] = 0;
   out_606899119426091544[73] = 0;
   out_606899119426091544[74] = 0;
   out_606899119426091544[75] = 0;
   out_606899119426091544[76] = 0;
   out_606899119426091544[77] = 0;
   out_606899119426091544[78] = 0;
   out_606899119426091544[79] = 0;
   out_606899119426091544[80] = 1;
}
void h_25(double *state, double *unused, double *out_2249341248542141975) {
   out_2249341248542141975[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7498705153458594920) {
   out_7498705153458594920[0] = 0;
   out_7498705153458594920[1] = 0;
   out_7498705153458594920[2] = 0;
   out_7498705153458594920[3] = 0;
   out_7498705153458594920[4] = 0;
   out_7498705153458594920[5] = 0;
   out_7498705153458594920[6] = 1;
   out_7498705153458594920[7] = 0;
   out_7498705153458594920[8] = 0;
}
void h_24(double *state, double *unused, double *out_5042487363538811890) {
   out_5042487363538811890[0] = state[4];
   out_5042487363538811890[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3529647286574029803) {
   out_3529647286574029803[0] = 0;
   out_3529647286574029803[1] = 0;
   out_3529647286574029803[2] = 0;
   out_3529647286574029803[3] = 0;
   out_3529647286574029803[4] = 1;
   out_3529647286574029803[5] = 0;
   out_3529647286574029803[6] = 0;
   out_3529647286574029803[7] = 0;
   out_3529647286574029803[8] = 0;
   out_3529647286574029803[9] = 0;
   out_3529647286574029803[10] = 0;
   out_3529647286574029803[11] = 0;
   out_3529647286574029803[12] = 0;
   out_3529647286574029803[13] = 0;
   out_3529647286574029803[14] = 1;
   out_3529647286574029803[15] = 0;
   out_3529647286574029803[16] = 0;
   out_3529647286574029803[17] = 0;
}
void h_30(double *state, double *unused, double *out_1974147186257636086) {
   out_1974147186257636086[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4031348578759339941) {
   out_4031348578759339941[0] = 0;
   out_4031348578759339941[1] = 0;
   out_4031348578759339941[2] = 0;
   out_4031348578759339941[3] = 0;
   out_4031348578759339941[4] = 1;
   out_4031348578759339941[5] = 0;
   out_4031348578759339941[6] = 0;
   out_4031348578759339941[7] = 0;
   out_4031348578759339941[8] = 0;
}
void h_26(double *state, double *unused, double *out_7452053475011439088) {
   out_7452053475011439088[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3757201834584538696) {
   out_3757201834584538696[0] = 0;
   out_3757201834584538696[1] = 0;
   out_3757201834584538696[2] = 0;
   out_3757201834584538696[3] = 0;
   out_3757201834584538696[4] = 0;
   out_3757201834584538696[5] = 0;
   out_3757201834584538696[6] = 0;
   out_3757201834584538696[7] = 1;
   out_3757201834584538696[8] = 0;
}
void h_27(double *state, double *unused, double *out_8648382765955991121) {
   out_8648382765955991121[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6206111890559764852) {
   out_6206111890559764852[0] = 0;
   out_6206111890559764852[1] = 0;
   out_6206111890559764852[2] = 0;
   out_6206111890559764852[3] = 1;
   out_6206111890559764852[4] = 0;
   out_6206111890559764852[5] = 0;
   out_6206111890559764852[6] = 0;
   out_6206111890559764852[7] = 0;
   out_6206111890559764852[8] = 0;
}
void h_29(double *state, double *unused, double *out_3027526081403209559) {
   out_3027526081403209559[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7919474617429315885) {
   out_7919474617429315885[0] = 0;
   out_7919474617429315885[1] = 1;
   out_7919474617429315885[2] = 0;
   out_7919474617429315885[3] = 0;
   out_7919474617429315885[4] = 0;
   out_7919474617429315885[5] = 0;
   out_7919474617429315885[6] = 0;
   out_7919474617429315885[7] = 0;
   out_7919474617429315885[8] = 0;
}
void h_28(double *state, double *unused, double *out_8854851454851898060) {
   out_8854851454851898060[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5444870439210705157) {
   out_5444870439210705157[0] = 1;
   out_5444870439210705157[1] = 0;
   out_5444870439210705157[2] = 0;
   out_5444870439210705157[3] = 0;
   out_5444870439210705157[4] = 0;
   out_5444870439210705157[5] = 0;
   out_5444870439210705157[6] = 0;
   out_5444870439210705157[7] = 0;
   out_5444870439210705157[8] = 0;
}
void h_31(double *state, double *unused, double *out_6247319432721598017) {
   out_6247319432721598017[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7529351115335555348) {
   out_7529351115335555348[0] = 0;
   out_7529351115335555348[1] = 0;
   out_7529351115335555348[2] = 0;
   out_7529351115335555348[3] = 0;
   out_7529351115335555348[4] = 0;
   out_7529351115335555348[5] = 0;
   out_7529351115335555348[6] = 0;
   out_7529351115335555348[7] = 0;
   out_7529351115335555348[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7715085255157723284) {
  err_fun(nom_x, delta_x, out_7715085255157723284);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3139976914443091875) {
  inv_err_fun(nom_x, true_x, out_3139976914443091875);
}
void car_H_mod_fun(double *state, double *out_3564524246730987791) {
  H_mod_fun(state, out_3564524246730987791);
}
void car_f_fun(double *state, double dt, double *out_9199042254253526234) {
  f_fun(state,  dt, out_9199042254253526234);
}
void car_F_fun(double *state, double dt, double *out_606899119426091544) {
  F_fun(state,  dt, out_606899119426091544);
}
void car_h_25(double *state, double *unused, double *out_2249341248542141975) {
  h_25(state, unused, out_2249341248542141975);
}
void car_H_25(double *state, double *unused, double *out_7498705153458594920) {
  H_25(state, unused, out_7498705153458594920);
}
void car_h_24(double *state, double *unused, double *out_5042487363538811890) {
  h_24(state, unused, out_5042487363538811890);
}
void car_H_24(double *state, double *unused, double *out_3529647286574029803) {
  H_24(state, unused, out_3529647286574029803);
}
void car_h_30(double *state, double *unused, double *out_1974147186257636086) {
  h_30(state, unused, out_1974147186257636086);
}
void car_H_30(double *state, double *unused, double *out_4031348578759339941) {
  H_30(state, unused, out_4031348578759339941);
}
void car_h_26(double *state, double *unused, double *out_7452053475011439088) {
  h_26(state, unused, out_7452053475011439088);
}
void car_H_26(double *state, double *unused, double *out_3757201834584538696) {
  H_26(state, unused, out_3757201834584538696);
}
void car_h_27(double *state, double *unused, double *out_8648382765955991121) {
  h_27(state, unused, out_8648382765955991121);
}
void car_H_27(double *state, double *unused, double *out_6206111890559764852) {
  H_27(state, unused, out_6206111890559764852);
}
void car_h_29(double *state, double *unused, double *out_3027526081403209559) {
  h_29(state, unused, out_3027526081403209559);
}
void car_H_29(double *state, double *unused, double *out_7919474617429315885) {
  H_29(state, unused, out_7919474617429315885);
}
void car_h_28(double *state, double *unused, double *out_8854851454851898060) {
  h_28(state, unused, out_8854851454851898060);
}
void car_H_28(double *state, double *unused, double *out_5444870439210705157) {
  H_28(state, unused, out_5444870439210705157);
}
void car_h_31(double *state, double *unused, double *out_6247319432721598017) {
  h_31(state, unused, out_6247319432721598017);
}
void car_H_31(double *state, double *unused, double *out_7529351115335555348) {
  H_31(state, unused, out_7529351115335555348);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
