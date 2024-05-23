/**
 * Publisher component definition.
 *
 * Roberto Masocco <robmasocco@gmail.com>
 *
 * May 23, 2024
 */

#include <pub_sub_components/pub.hpp>

//! There has to be a namespace when declaring a component class,
//! in order to avoid plugin name clashes with other components.
//! The name of the namespace should be the name of the package.
namespace pub_sub_components
{

/**
 * @brief Creates a Publisher node.
 */
Publisher::Publisher(const rclcpp::NodeOptions & node_opts)
: Node("publisher_node", node_opts),
  pub_cnt_(0)
{
  publisher_ = this->create_publisher<std_msgs::msg::String>(
    "/examples/test_topic",
    rclcpp::QoS(10));

  pub_timer_ = this->create_wall_timer(
    std::chrono::milliseconds(PUB_PERIOD),
    std::bind(
      &Publisher::pub_timer_callback,
      this));

  RCLCPP_INFO(this->get_logger(), "Publisher initialized");
}

/**
 * @brief Publishes a message on timer occurrence.
 */
void Publisher::pub_timer_callback(void)
{
  // Build the new message
  std::string new_data = "Hello ";
  new_data.append(std::to_string(pub_cnt_) + ".");

  std_msgs::msg::String new_msg{};

  new_msg.set__data(new_data);

  publisher_->publish(new_msg);

  // Log something
  pub_cnt_++;
  RCLCPP_INFO(this->get_logger(), "Published message %lu", pub_cnt_);
}

} // namespace pub_sub_components

//! Must do this at the end of one source file where your class definition is to generate the plugin.
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(pub_sub_components::Publisher)
