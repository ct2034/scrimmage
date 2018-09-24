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

#include <scrimmage/common/ParameterServer.h>

#include <string>
#include <algorithm>

namespace scrimmage {
void ParameterServer::unregister_params(PluginPtr owner) {
    // For all parameters, remove all parameters owned by this plugin
    for (auto &kv1 : params_) {
        for (auto &kv2 : kv1.second) {
            kv2.second.erase(std::remove_if(kv2.second.begin(), kv2.second.end(),
                                            [&](ParameterBasePtr ptr) {
                                                return ptr->owner() == owner; }),
                             kv2.second.end());
        }
    }
}
} // namespace scrimmage
