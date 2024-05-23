/**
 * Subscriber component declaration.
 *
 * Roberto Masocco <robmasocco@gmail.com>
 *
 * May 23, 2024
 */

#ifndef SUB_HPP
#define SUB_HPP

#include <rclcpp/rclcpp.hpp>

#include <std_msgs/msg/string.hpp>

//! There has to be a namespace when declaring a component class,
//! in order to avoid plugin name clashes with other components.
//! The name of the namespace should be the name of the package.
namespace pub_sub_components
{

/**
 * Simple subscriber node: receives and prints strings transmitted on a topic.
 */
class Subscriber : public rclcpp::Node
{
public:
  //! To be compatible with component containers, the constructor must have only this argument!
  Subscriber(const rclcpp::NodeOptions & node_opts);

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
  void msg_callback(const std_msgs::msg::String::SharedPtr msg);
};

} // namespace pub_sub_components

#endif
