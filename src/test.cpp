#include <mpc_ipopt/mpc.h>
#include <iostream>

int main() {
    mpc_ipopt::Params p;
    p.forward.steps = 5;
    p.forward.frequency = 1;
    p.limits.vel = {-1, 1};
    p.limits.acc = {-0.1, 0.1};
    p.wheel_dist = 0.65; //meters

    mpc_ipopt::MPC mpc(p);

    mpc_ipopt::Dvector vec{2};
    vec[0] = -0.5;
    vec[1] = 1;
    mpc.global_plan = vec;
    mpc.state.v_r = 0.5;
    mpc.state.v_l = 0.5;

    mpc.solve();
    return 0;

}