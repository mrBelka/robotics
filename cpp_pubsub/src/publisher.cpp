#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <stdlib.h> 

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("minimal_publisher"), count_(0)
    {
      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
      timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
      srand(time(0));
    }

  private:
    void timer_callback()
    {
      // Чтение из последовательного порта
      // Чтение из интерфейса

      int x = 2 - (rand() % 5);
      int theta = 1 - (rand() % 3);


      auto message = geometry_msgs::msg::Twist();
      message.linear.x = x;
      message.angular.z = theta;
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}