#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"





class RobotNewsStation : public rclcpp::Node{

public:
    RobotNewsStation() : Node("robot_news_station"),robot_name("R2D2")
    {
        publisher=this->create_publisher<example_interfaces::msg::String>("robot_news",10);
        timer=this->create_wall_timer(std::chrono::seconds(1),std::bind(&RobotNewsStation::publishNews,this));
        RCLCPP_INFO(this->get_logger(),"Robot News station has been started!");
    }

private:


    void publishNews()
    {
        auto msg=example_interfaces::msg::String();
        msg.data=std::string("Hi,this is")+robot_name+std::string("from the news station.");
        publisher->publish(msg);
        RCLCPP_INFO(this->get_logger(),"%s",msg.data.c_str());
    }
    std::string robot_name;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher;
    rclcpp::TimerBase::SharedPtr timer;



};


int main(int argc,char **argv)
{

    rclcpp::init(argc,argv);

    auto node=std::make_shared<RobotNewsStation>();


    rclcpp::spin(node);


    rclcpp::shutdown();
    return 0;
}