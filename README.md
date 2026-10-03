# Food Delivery LLD (Low Level Design)

A comprehensive C++ implementation of a Food Delivery System demonstrating various design patterns and architectural principles.

## Project Structure

```
Food_Delivery_LLD/
├── CMakeLists.txt
├── main.cpp
├── README.md
├── include/
│   ├── model/
│   │   ├── User.hpp
│   │   ├── Customer.hpp
│   │   ├── Restaurant.hpp
│   │   ├── Menu.hpp
│   │   ├── MenuItem.hpp
│   │   ├── Cart.hpp
│   │   ├── CartItem.hpp
│   │   ├── Order.hpp
│   │   ├── OrderItem.hpp
│   │   ├── Payment.hpp
│   │   ├── Delivery.hpp
│   │   ├── DeliveryPartner.hpp
│   │   └── Address.hpp
│   ├── enums/
│   │   ├── OrderStatus.hpp
│   │   ├── PaymentStatus.hpp
│   │   ├── PaymentMethod.hpp
│   │   └── DeliveryStatus.hpp
│   ├── service/
│   │   ├── UserService.hpp
│   │   ├── RestaurantService.hpp
│   │   ├── CartService.hpp
│   │   ├── OrderService.hpp
│   │   ├── PaymentService.hpp
│   │   ├── PricingService.hpp
│   │   └── DeliveryService.hpp
│   ├── strategy/
│   │   ├── payment/
│   │   │   ├── PaymentStrategy.hpp
│   │   │   ├── UpiPayment.hpp
│   │   │   ├── CardPayment.hpp
│   │   │   └── CashOnDelivery.hpp
│   │   ├── pricing/
│   │   │   ├── PricingStrategy.hpp
│   │   │   ├── NormalPricing.hpp
│   │   │   └── DistanceBasedPricing.hpp
│   │   └── delivery/
│   │       ├── DeliveryAssignmentStrategy.hpp
│   │       ├── NearestPartnerStrategy.hpp
│   │       └── LeastBusyPartnerStrategy.hpp
│   ├── factory/
│   │   └── PaymentFactory.hpp
│   ├── observer/
│   │   ├── OrderObserver.hpp
│   │   ├── EmailObserver.hpp
│   │   ├── SmsObserver.hpp
│   │   └── PushObserver.hpp
│   ├── state/
│   │   ├── OrderState.hpp
│   │   ├── PlacedState.hpp
│   │   ├── ConfirmedState.hpp
│   │   ├── PreparingState.hpp
│   │   ├── ReadyForPickupState.hpp
│   │   ├── OutForDeliveryState.hpp
│   │   ├── DeliveredState.hpp
│   │   └── CancelledState.hpp
│   ├── repository/
│   │   ├── UserRepository.hpp
│   │   ├── RestaurantRepository.hpp
│   │   ├── OrderRepository.hpp
│   │   └── DeliveryRepository.hpp
│   └── util/
│       ├── IdGenerator.hpp
│       └── Logger.hpp
├── src/
│   ├── model/
│   ├── service/
│   ├── strategy/
│   │   ├── payment/
│   │   ├── pricing/
│   │   └── delivery/
│   ├── factory/
│   ├── observer/
│   ├── state/
│   ├── repository/
│   └── util/
└── tests/
    ├── CartTest.cpp
    ├── OrderTest.cpp
    ├── PaymentTest.cpp
    ├── PricingTest.cpp
    └── DeliveryTest.cpp
```

## Design Patterns Used

1. **Strategy Pattern** - Payment processing, pricing algorithms, delivery assignment
2. **Factory Pattern** - Payment method creation
3. **Observer Pattern** - Order status notifications (Email, SMS, Push)
4. **State Pattern** - Order lifecycle management
5. **Repository Pattern** - Data access abstraction

## Building the Project

### Prerequisites
- CMake 3.16+
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)

### Build Steps

```bash
# Configure
cmake -B build

# Build
cmake --build build

# Run main executable
./build/food_delivery_lld

# Run tests
ctest --test-dir build
```

## Features

- **User Management**: Customers and Restaurants with authentication
- **Menu Management**: Restaurants can manage menus and items
- **Cart System**: Add/remove items, calculate totals
- **Order Processing**: Complete order lifecycle with state management
- **Payment Processing**: Multiple payment methods (UPI, Card, COD)
- **Delivery Management**: Partner assignment with different strategies
- **Notifications**: Real-time order updates via multiple channels
- **Pricing**: Flexible pricing strategies (normal, distance-based)

## Testing

The project includes unit tests for:
- Cart functionality
- Order processing
- Payment handling
- Pricing strategies
- Delivery assignment

Run tests with: `ctest --test-dir build --output-on-failure`

## License

This is a learning project for Low Level Design practice.