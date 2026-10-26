#include "rclcpp/rclcpp.hpp"
#include "package_messages/msg/controller.hpp"
#include <chrono>
#include <memory>

using namespace std::chrono_literals;

class ControllerPublisher : public rclcpp::Node {
public:
    ControllerPublisher() : Node("controller_publisher"), count_(0) {
        pub_pos = this->create_publisher<package_messages::msg::Controller>("controller", 10);

        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&ControllerPublisher::timer_callback, this)
        );
    }

private:
    float randomFloat() {
        return (float)(rand()) / (float)(rand());
    }

    void timer_callback() {
        package_messages::msg::Controller controller_msg;

        //isi dengan nilai random, karena fokus pada mekanisme custom message
        controller_msg.velx = randomFloat();
        controller_msg.vely = randomFloat();
        controller_msg.angvel = randomFloat();

        RCLCPP_INFO_STREAM(this->get_logger(), "Mengirim data (" << count_++ << ")");
        pub_pos->publish(controller_msg);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<package_messages::msg::Controller>::SharedPtr pub_pos;
    size_t count_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ControllerPublisher>());
    rclcpp::shutdown();
    return 0;
}