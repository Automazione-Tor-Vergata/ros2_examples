#!/usr/bin/env bash

# Shell functions and commands for ROS 2 management.
#
# Roberto Masocco <r.masocco@dotxautomation.com>
#
# June 13, 2024

# Copyright 2024 dotX Automation s.r.l.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# shellcheck disable=SC1090,SC2086

# Initialize ROS 2 environment according to the current shell.
ros2init() {
  if [[ $# -ne 0 ]]; then
    export ROS_DOMAIN_ID=$1
  fi
  export ROS_VERSION=2
  export ROS_PYTHON_VERSION=3
  export ROS_DISTRO=humble

  CURR_SHELL=$(ps -p $$ | awk 'NR==2 {print $4}')

  # Check that the ROS 2 installation is present, and source it
  if [[ -f /opt/ros/$ROS_DISTRO/setup.$CURR_SHELL ]]; then
    source /opt/ros/$ROS_DISTRO/setup.$CURR_SHELL
  elif [[ -f /opt/ros/$ROS_DISTRO/install/setup.$CURR_SHELL ]]; then
    source /opt/ros/$ROS_DISTRO/install/setup.$CURR_SHELL
  else
    echo >&2 "ROS 2 installation not found."
    return 1
  fi

  # Source additional stuff for colcon argcomplete
  source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.$CURR_SHELL

  # Source Ignition Gazebo stuff
  if [[ -f /opt/gazebo/fortress/install/setup.$CURR_SHELL ]]; then
    source /opt/gazebo/fortress/install/setup.$CURR_SHELL
  fi
  if [[ -f /opt/ros/ros_gz/install/local_setup.$CURR_SHELL ]]; then
    source /opt/ros/ros_gz/install/local_setup.$CURR_SHELL
  fi

  # Source our fork of rmw_fastrtps
  if [[ -f /opt/ros/rmw_fastrtps/install/local_setup.$CURR_SHELL ]]; then
    source /opt/ros/rmw_fastrtps/install/local_setup.$CURR_SHELL
  fi

  # Source additional DUA stuff
  if [[ -f /opt/ros/dua-utils/install/local_setup.$CURR_SHELL ]]; then
    source /opt/ros/dua-utils/install/local_setup.$CURR_SHELL
  fi

  # Source workspace if present
  if [[ -f /home/neo/workspace/install/local_setup.$CURR_SHELL ]]; then
    source /home/neo/workspace/install/local_setup.$CURR_SHELL
  fi
}

# Alias for Gazebo Classic that includes environment variables for HiDPI
alias gazebo='QT_AUTO_SCREEN_SCALE_FACTOR=0 QT_SCREEN_SCALE_FACTORS=[1.0] /usr/bin/gazebo'
