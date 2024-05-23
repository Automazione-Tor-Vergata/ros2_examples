/**
 * Subscriber application.
 *
 * Roberto Masocco <robmasocco@gmail.com>
 *
 * May 23, 2024
 */

#include <iostream>

#include <pub_sub_components/sub.hpp>

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  //! For the options, we pass a default-constructed rvalue.
  auto sub_node = std::make_shared<pub_sub_components::Subscriber>(rclcpp::NodeOptions());
  rclcpp::spin(sub_node);
  rclcpp::shutdown();
  exit(EXIT_SUCCESS);
}
