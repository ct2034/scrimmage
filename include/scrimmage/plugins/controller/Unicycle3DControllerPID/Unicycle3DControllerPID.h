/*!
 * @file
 *
 * @section LICENSE
 *
 * Copyright (C) 2017 by the Georgia Tech Research Institute (GTRI)
 *
 * This file is part of SCRIMMAGE.
 *
 *   SCRIMMAGE is free software: you can redistribute it and/or modify it under
 *   the terms of the GNU Lesser General Public License as published by the
 *   Free Software Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   SCRIMMAGE is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 *   License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with SCRIMMAGE.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Kevin DeMarco <kevin.demarco@gtri.gatech.edu>
 * @author Eric Squires <eric.squires@gtri.gatech.edu>
 * @date 31 July 2017
 * @version 0.1.0
 * @brief Brief file description.
 * @section DESCRIPTION
 * A Long description goes here.
 *
 */

#ifndef INCLUDE_SCRIMMAGE_PLUGINS_CONTROLLER_UNICYCLE3DCONTROLLERPID_UNICYCLE3DCONTROLLERPID_H_
#define INCLUDE_SCRIMMAGE_PLUGINS_CONTROLLER_UNICYCLE3DCONTROLLERPID_UNICYCLE3DCONTROLLERPID_H_

#include <scrimmage/plugins/motion/SimpleAircraft/SimpleAircraft.h>

#include <map>
#include <string>

namespace scrimmage {
namespace controller {
class Unicycle3DControllerPID : public motion::SimpleAircraft::Controller {
 public:
    virtual void init(std::map<std::string, std::string> &params);
    virtual bool step(double t, double dt);
    virtual std::shared_ptr<Eigen::Vector3d> u() {return u_;}

 protected:
    std::shared_ptr<Eigen::Vector3d> u_;
    scrimmage::PID heading_pid_;
    scrimmage::PID alt_pid_;
    scrimmage::PID vel_pid_;
    bool use_roll_ = false;

    int desired_alt_idx_ = 0;
    int desired_speed_idx_ = 0;
    int desired_heading_idx_ = 0;

    int velocity_idx_ = 0;
    int accel_idx_ = 0;
    int turn_rate_idx_ = 0;
    int pitch_rate_idx_ = 0;
};
} // namespace controller
} // namespace scrimmage
#endif // INCLUDE_SCRIMMAGE_PLUGINS_CONTROLLER_UNICYCLE3DCONTROLLERPID_UNICYCLE3DCONTROLLERPID_H_