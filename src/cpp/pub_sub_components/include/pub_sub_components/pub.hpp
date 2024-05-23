/**
 * Publisher component declaration.
 *
 * Roberto Masocco <robmasocco@gmail.com>
 *
 * May 23, 2024
 */

#ifndef PUB_HPP
#define PUB_HPP

#include <rclcpp/rclcpp.hpp>

#include <std_msgs/msg/string.hpp>

#define PUB_PERIOD 300 // Publisher transmission time period [ms]

//! There has to be a namespace when declaring a component class,
//! in order to avoid plugin name clashes with other components.
//! The name of the namespace should be the name of the package.
namespace pub_sub_components
{

/**
 * Simple publisher node: transmits strings on a topic.
 */
class Publisher : public rclcpp::Node
{
public:
  //! To be compatible with component containers, the constructor must have only this argument!
  Publisher(const rclcpp::NodeOptions & node_opts);

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

  rclcpp::TimerBase::SharedPtr pub_timer_;
  void pub_timer_callback(void);

  unsigned long pub_cnt_; // Marks messages
};

} // namespace pub_sub_components

#endif
