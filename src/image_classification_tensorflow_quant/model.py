import tensorflow.keras as K
from tensorflow.keras.applications.inception_v3 import InceptionV3


def create_model(num_classes):
    pre_trained_model = InceptionV3(
        input_shape=(100, 100, 3),
        weights='imagenet',
        include_top=False
    )

    # for layer in pre_trained_model.layers:
    #    layer.trainable = False

    pre_train_out_layer = pre_trained_model.get_layer("mixed7")
    pretrain_out = pre_train_out_layer.output

    x = K.layers.GlobalAveragePooling2D()(pretrain_out)
    x = K.layers.Dense(units=1024, activation="relu")(x)
    x = K.layers.Dropout(0.2)(x)
    x = K.layers.Dense(units=512, activation="relu")(x)
    x = K.layers.Dropout(0.1)(x)
    x = K.layers.Dense(units=num_classes, activation="softmax")(x)

    model = K.Model(inputs=pre_trained_model.input, outputs=x)

    return model
    