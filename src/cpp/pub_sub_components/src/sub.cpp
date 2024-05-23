/**
 * Subscriber component definition.
 *
 * Roberto Masocco <robmasocco@gmail.com>
 *
 * May 23, 2024
 */

#include <pub_sub_components/sub.hpp>

//! There has to be a namespace when declaring a component class,
//! in order to avoid plugin name clashes with other components.
//! The name of the namespace should be the name of the package.
namespace pub_sub_components
{

/**
 * @brief Creates a Subscriber node.
 */
Subscriber::Subscriber(const rclcpp::NodeOptions & node_opts)
: Node("subscriber_node", node_opts)
{
  subscriber_ = this->create_subscription<std_msgs::msg::String>(
    "/examples/test_topic",
    rclcpp::QoS(10),
    std::bind(
      &Subscriber::msg_callback,
      this,
      std::placeholders::_1));

  RCLCPP_INFO(this->get_logger(), "Subscriber initialized");
}

/**
 * @brief Echoes a new message.
 *
 * @param msg New message.
 */
void Subscriber::msg_callback(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(this->get_logger(), msg->data.c_str());
}

} // namespace pub_sub_components

//! Must do this at the end of one source file where your class definition is to generate the plugin.
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(pub_sub_components::Subscriber)
