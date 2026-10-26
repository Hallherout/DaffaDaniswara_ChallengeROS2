#include "rclcpp/rclcpp.hpp"
#include "package_messages/msg/controller.hpp"
#include <functional>
#include <memory>
#include <cstring>

using std::placeholders::_1;

class ControllerSubscriber : public rclcpp::Node {
public:
    ControllerSubscriber() : Node("controller_subscriber") {
        sub_controller = this->create_subscription<package_messages::msg::Controller>("controller", 10, std::bind(&ControllerSubscriber::controllerCallback, this, _1));
    }

private:
    void controllerCallback(const package_messages::msg::Controller::SharedPtr msg) {
        float arr[3] = {msg->velx, msg->vely, msg->angvel};

        RCLCPP_INFO_STREAM(this->get_logger(), "velx=" << arr[0] << " vely=" << arr[1] << " angvel=" << arr[2]);
    }

    rclcpp::Subscription<package_messages::msg::Controller>::SharedPtr sub_controller;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ControllerSubscriber>());
    rclcpp::shutdown();
    return 0;
}