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
void err_fun(double *nom_x, double *delta_x, double *out_8250891246740759679) {
   out_8250891246740759679[0] = delta_x[0] + nom_x[0];
   out_8250891246740759679[1] = delta_x[1] + nom_x[1];
   out_8250891246740759679[2] = delta_x[2] + nom_x[2];
   out_8250891246740759679[3] = delta_x[3] + nom_x[3];
   out_8250891246740759679[4] = delta_x[4] + nom_x[4];
   out_8250891246740759679[5] = delta_x[5] + nom_x[5];
   out_8250891246740759679[6] = delta_x[6] + nom_x[6];
   out_8250891246740759679[7] = delta_x[7] + nom_x[7];
   out_8250891246740759679[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6699306425357192023) {
   out_6699306425357192023[0] = -nom_x[0] + true_x[0];
   out_6699306425357192023[1] = -nom_x[1] + true_x[1];
   out_6699306425357192023[2] = -nom_x[2] + true_x[2];
   out_6699306425357192023[3] = -nom_x[3] + true_x[3];
   out_6699306425357192023[4] = -nom_x[4] + true_x[4];
   out_6699306425357192023[5] = -nom_x[5] + true_x[5];
   out_6699306425357192023[6] = -nom_x[6] + true_x[6];
   out_6699306425357192023[7] = -nom_x[7] + true_x[7];
   out_6699306425357192023[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2914898107951165883) {
   out_2914898107951165883[0] = 1.0;
   out_2914898107951165883[1] = 0.0;
   out_2914898107951165883[2] = 0.0;
   out_2914898107951165883[3] = 0.0;
   out_2914898107951165883[4] = 0.0;
   out_2914898107951165883[5] = 0.0;
   out_2914898107951165883[6] = 0.0;
   out_2914898107951165883[7] = 0.0;
   out_2914898107951165883[8] = 0.0;
   out_2914898107951165883[9] = 0.0;
   out_2914898107951165883[10] = 1.0;
   out_2914898107951165883[11] = 0.0;
   out_2914898107951165883[12] = 0.0;
   out_2914898107951165883[13] = 0.0;
   out_2914898107951165883[14] = 0.0;
   out_2914898107951165883[15] = 0.0;
   out_2914898107951165883[16] = 0.0;
   out_2914898107951165883[17] = 0.0;
   out_2914898107951165883[18] = 0.0;
   out_2914898107951165883[19] = 0.0;
   out_2914898107951165883[20] = 1.0;
   out_2914898107951165883[21] = 0.0;
   out_2914898107951165883[22] = 0.0;
   out_2914898107951165883[23] = 0.0;
   out_2914898107951165883[24] = 0.0;
   out_2914898107951165883[25] = 0.0;
   out_2914898107951165883[26] = 0.0;
   out_2914898107951165883[27] = 0.0;
   out_2914898107951165883[28] = 0.0;
   out_2914898107951165883[29] = 0.0;
   out_2914898107951165883[30] = 1.0;
   out_2914898107951165883[31] = 0.0;
   out_2914898107951165883[32] = 0.0;
   out_2914898107951165883[33] = 0.0;
   out_2914898107951165883[34] = 0.0;
   out_2914898107951165883[35] = 0.0;
   out_2914898107951165883[36] = 0.0;
   out_2914898107951165883[37] = 0.0;
   out_2914898107951165883[38] = 0.0;
   out_2914898107951165883[39] = 0.0;
   out_2914898107951165883[40] = 1.0;
   out_2914898107951165883[41] = 0.0;
   out_2914898107951165883[42] = 0.0;
   out_2914898107951165883[43] = 0.0;
   out_2914898107951165883[44] = 0.0;
   out_2914898107951165883[45] = 0.0;
   out_2914898107951165883[46] = 0.0;
   out_2914898107951165883[47] = 0.0;
   out_2914898107951165883[48] = 0.0;
   out_2914898107951165883[49] = 0.0;
   out_2914898107951165883[50] = 1.0;
   out_2914898107951165883[51] = 0.0;
   out_2914898107951165883[52] = 0.0;
   out_2914898107951165883[53] = 0.0;
   out_2914898107951165883[54] = 0.0;
   out_2914898107951165883[55] = 0.0;
   out_2914898107951165883[56] = 0.0;
   out_2914898107951165883[57] = 0.0;
   out_2914898107951165883[58] = 0.0;
   out_2914898107951165883[59] = 0.0;
   out_2914898107951165883[60] = 1.0;
   out_2914898107951165883[61] = 0.0;
   out_2914898107951165883[62] = 0.0;
   out_2914898107951165883[63] = 0.0;
   out_2914898107951165883[64] = 0.0;
   out_2914898107951165883[65] = 0.0;
   out_2914898107951165883[66] = 0.0;
   out_2914898107951165883[67] = 0.0;
   out_2914898107951165883[68] = 0.0;
   out_2914898107951165883[69] = 0.0;
   out_2914898107951165883[70] = 1.0;
   out_2914898107951165883[71] = 0.0;
   out_2914898107951165883[72] = 0.0;
   out_2914898107951165883[73] = 0.0;
   out_2914898107951165883[74] = 0.0;
   out_2914898107951165883[75] = 0.0;
   out_2914898107951165883[76] = 0.0;
   out_2914898107951165883[77] = 0.0;
   out_2914898107951165883[78] = 0.0;
   out_2914898107951165883[79] = 0.0;
   out_2914898107951165883[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2675178968316523152) {
   out_2675178968316523152[0] = state[0];
   out_2675178968316523152[1] = state[1];
   out_2675178968316523152[2] = state[2];
   out_2675178968316523152[3] = state[3];
   out_2675178968316523152[4] = state[4];
   out_2675178968316523152[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2675178968316523152[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2675178968316523152[7] = state[7];
   out_2675178968316523152[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5308189961048980992) {
   out_5308189961048980992[0] = 1;
   out_5308189961048980992[1] = 0;
   out_5308189961048980992[2] = 0;
   out_5308189961048980992[3] = 0;
   out_5308189961048980992[4] = 0;
   out_5308189961048980992[5] = 0;
   out_5308189961048980992[6] = 0;
   out_5308189961048980992[7] = 0;
   out_5308189961048980992[8] = 0;
   out_5308189961048980992[9] = 0;
   out_5308189961048980992[10] = 1;
   out_5308189961048980992[11] = 0;
   out_5308189961048980992[12] = 0;
   out_5308189961048980992[13] = 0;
   out_5308189961048980992[14] = 0;
   out_5308189961048980992[15] = 0;
   out_5308189961048980992[16] = 0;
   out_5308189961048980992[17] = 0;
   out_5308189961048980992[18] = 0;
   out_5308189961048980992[19] = 0;
   out_5308189961048980992[20] = 1;
   out_5308189961048980992[21] = 0;
   out_5308189961048980992[22] = 0;
   out_5308189961048980992[23] = 0;
   out_5308189961048980992[24] = 0;
   out_5308189961048980992[25] = 0;
   out_5308189961048980992[26] = 0;
   out_5308189961048980992[27] = 0;
   out_5308189961048980992[28] = 0;
   out_5308189961048980992[29] = 0;
   out_5308189961048980992[30] = 1;
   out_5308189961048980992[31] = 0;
   out_5308189961048980992[32] = 0;
   out_5308189961048980992[33] = 0;
   out_5308189961048980992[34] = 0;
   out_5308189961048980992[35] = 0;
   out_5308189961048980992[36] = 0;
   out_5308189961048980992[37] = 0;
   out_5308189961048980992[38] = 0;
   out_5308189961048980992[39] = 0;
   out_5308189961048980992[40] = 1;
   out_5308189961048980992[41] = 0;
   out_5308189961048980992[42] = 0;
   out_5308189961048980992[43] = 0;
   out_5308189961048980992[44] = 0;
   out_5308189961048980992[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5308189961048980992[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5308189961048980992[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5308189961048980992[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5308189961048980992[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5308189961048980992[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5308189961048980992[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5308189961048980992[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5308189961048980992[53] = -9.8100000000000005*dt;
   out_5308189961048980992[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5308189961048980992[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5308189961048980992[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5308189961048980992[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5308189961048980992[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5308189961048980992[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5308189961048980992[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5308189961048980992[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5308189961048980992[62] = 0;
   out_5308189961048980992[63] = 0;
   out_5308189961048980992[64] = 0;
   out_5308189961048980992[65] = 0;
   out_5308189961048980992[66] = 0;
   out_5308189961048980992[67] = 0;
   out_5308189961048980992[68] = 0;
   out_5308189961048980992[69] = 0;
   out_5308189961048980992[70] = 1;
   out_5308189961048980992[71] = 0;
   out_5308189961048980992[72] = 0;
   out_5308189961048980992[73] = 0;
   out_5308189961048980992[74] = 0;
   out_5308189961048980992[75] = 0;
   out_5308189961048980992[76] = 0;
   out_5308189961048980992[77] = 0;
   out_5308189961048980992[78] = 0;
   out_5308189961048980992[79] = 0;
   out_5308189961048980992[80] = 1;
}
void h_25(double *state, double *unused, double *out_6353754508244043817) {
   out_6353754508244043817[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6338657739846148496) {
   out_6338657739846148496[0] = 0;
   out_6338657739846148496[1] = 0;
   out_6338657739846148496[2] = 0;
   out_6338657739846148496[3] = 0;
   out_6338657739846148496[4] = 0;
   out_6338657739846148496[5] = 0;
   out_6338657739846148496[6] = 1;
   out_6338657739846148496[7] = 0;
   out_6338657739846148496[8] = 0;
}
void h_24(double *state, double *unused, double *out_2065669686396091997) {
   out_2065669686396091997[0] = state[4];
   out_2065669686396091997[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1518336235190160233) {
   out_1518336235190160233[0] = 0;
   out_1518336235190160233[1] = 0;
   out_1518336235190160233[2] = 0;
   out_1518336235190160233[3] = 0;
   out_1518336235190160233[4] = 1;
   out_1518336235190160233[5] = 0;
   out_1518336235190160233[6] = 0;
   out_1518336235190160233[7] = 0;
   out_1518336235190160233[8] = 0;
   out_1518336235190160233[9] = 0;
   out_1518336235190160233[10] = 0;
   out_1518336235190160233[11] = 0;
   out_1518336235190160233[12] = 0;
   out_1518336235190160233[13] = 0;
   out_1518336235190160233[14] = 1;
   out_1518336235190160233[15] = 0;
   out_1518336235190160233[16] = 0;
   out_1518336235190160233[17] = 0;
}
void h_30(double *state, double *unused, double *out_4759906320160358758) {
   out_4759906320160358758[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6209318792702908426) {
   out_6209318792702908426[0] = 0;
   out_6209318792702908426[1] = 0;
   out_6209318792702908426[2] = 0;
   out_6209318792702908426[3] = 0;
   out_6209318792702908426[4] = 1;
   out_6209318792702908426[5] = 0;
   out_6209318792702908426[6] = 0;
   out_6209318792702908426[7] = 0;
   out_6209318792702908426[8] = 0;
}
void h_26(double *state, double *unused, double *out_163294403103182073) {
   out_163294403103182073[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2597154420972092272) {
   out_2597154420972092272[0] = 0;
   out_2597154420972092272[1] = 0;
   out_2597154420972092272[2] = 0;
   out_2597154420972092272[3] = 0;
   out_2597154420972092272[4] = 0;
   out_2597154420972092272[5] = 0;
   out_2597154420972092272[6] = 0;
   out_2597154420972092272[7] = 1;
   out_2597154420972092272[8] = 0;
}
void h_27(double *state, double *unused, double *out_45287009169805329) {
   out_45287009169805329[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4034555480902483515) {
   out_4034555480902483515[0] = 0;
   out_4034555480902483515[1] = 0;
   out_4034555480902483515[2] = 0;
   out_4034555480902483515[3] = 1;
   out_4034555480902483515[4] = 0;
   out_4034555480902483515[5] = 0;
   out_4034555480902483515[6] = 0;
   out_4034555480902483515[7] = 0;
   out_4034555480902483515[8] = 0;
}
void h_29(double *state, double *unused, double *out_4143590307449177193) {
   out_4143590307449177193[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6719550137017300610) {
   out_6719550137017300610[0] = 0;
   out_6719550137017300610[1] = 1;
   out_6719550137017300610[2] = 0;
   out_6719550137017300610[3] = 0;
   out_6719550137017300610[4] = 0;
   out_6719550137017300610[5] = 0;
   out_6719550137017300610[6] = 0;
   out_6719550137017300610[7] = 0;
   out_6719550137017300610[8] = 0;
}
void h_28(double *state, double *unused, double *out_8542875672635036079) {
   out_8542875672635036079[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1637151119947770036) {
   out_1637151119947770036[0] = 1;
   out_1637151119947770036[1] = 0;
   out_1637151119947770036[2] = 0;
   out_1637151119947770036[3] = 0;
   out_1637151119947770036[4] = 0;
   out_1637151119947770036[5] = 0;
   out_1637151119947770036[6] = 0;
   out_1637151119947770036[7] = 0;
   out_1637151119947770036[8] = 0;
}
void h_31(double *state, double *unused, double *out_5322154339115156863) {
   out_5322154339115156863[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6369303701723108924) {
   out_6369303701723108924[0] = 0;
   out_6369303701723108924[1] = 0;
   out_6369303701723108924[2] = 0;
   out_6369303701723108924[3] = 0;
   out_6369303701723108924[4] = 0;
   out_6369303701723108924[5] = 0;
   out_6369303701723108924[6] = 0;
   out_6369303701723108924[7] = 0;
   out_6369303701723108924[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8250891246740759679) {
  err_fun(nom_x, delta_x, out_8250891246740759679);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6699306425357192023) {
  inv_err_fun(nom_x, true_x, out_6699306425357192023);
}
void car_H_mod_fun(double *state, double *out_2914898107951165883) {
  H_mod_fun(state, out_2914898107951165883);
}
void car_f_fun(double *state, double dt, double *out_2675178968316523152) {
  f_fun(state,  dt, out_2675178968316523152);
}
void car_F_fun(double *state, double dt, double *out_5308189961048980992) {
  F_fun(state,  dt, out_5308189961048980992);
}
void car_h_25(double *state, double *unused, double *out_6353754508244043817) {
  h_25(state, unused, out_6353754508244043817);
}
void car_H_25(double *state, double *unused, double *out_6338657739846148496) {
  H_25(state, unused, out_6338657739846148496);
}
void car_h_24(double *state, double *unused, double *out_2065669686396091997) {
  h_24(state, unused, out_2065669686396091997);
}
void car_H_24(double *state, double *unused, double *out_1518336235190160233) {
  H_24(state, unused, out_1518336235190160233);
}
void car_h_30(double *state, double *unused, double *out_4759906320160358758) {
  h_30(state, unused, out_4759906320160358758);
}
void car_H_30(double *state, double *unused, double *out_6209318792702908426) {
  H_30(state, unused, out_6209318792702908426);
}
void car_h_26(double *state, double *unused, double *out_163294403103182073) {
  h_26(state, unused, out_163294403103182073);
}
void car_H_26(double *state, double *unused, double *out_2597154420972092272) {
  H_26(state, unused, out_2597154420972092272);
}
void car_h_27(double *state, double *unused, double *out_45287009169805329) {
  h_27(state, unused, out_45287009169805329);
}
void car_H_27(double *state, double *unused, double *out_4034555480902483515) {
  H_27(state, unused, out_4034555480902483515);
}
void car_h_29(double *state, double *unused, double *out_4143590307449177193) {
  h_29(state, unused, out_4143590307449177193);
}
void car_H_29(double *state, double *unused, double *out_6719550137017300610) {
  H_29(state, unused, out_6719550137017300610);
}
void car_h_28(double *state, double *unused, double *out_8542875672635036079) {
  h_28(state, unused, out_8542875672635036079);
}
void car_H_28(double *state, double *unused, double *out_1637151119947770036) {
  H_28(state, unused, out_1637151119947770036);
}
void car_h_31(double *state, double *unused, double *out_5322154339115156863) {
  h_31(state, unused, out_5322154339115156863);
}
void car_H_31(double *state, double *unused, double *out_6369303701723108924) {
  H_31(state, unused, out_6369303701723108924);
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
