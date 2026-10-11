#include "rclcpp/rclcpp.hpp"


class myNode:public rclcpp::Node{


    public:
    myNode():Node("cpp_test")
    {
        RCLCPP_INFO(this->get_logger(),"我还是那么爱你");

        timer=this->create_wall_timer(std::chrono::seconds(1),
                                      std::bind(&myNode::timerCallback,this));
                                      
    }

    private:

    void timerCallback()
    {
        RCLCPP_INFO(this->get_logger(),"hello world %d",counter);

        counter++;
    }

    rclcpp::TimerBase::SharedPtr timer;
    int counter;
};

int main(int argc,char **argv)
{
    rclcpp::init(argc,argv);

    auto node=std::make_shared<myNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
    
}